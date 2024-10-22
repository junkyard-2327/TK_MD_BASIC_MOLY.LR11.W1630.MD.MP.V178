/*
 * Copyright (C) 2006 Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "rekey_child_sa_job.h"

#include <daemon.h>
#include <time.h>

typedef struct private_rekey_child_sa_job_t private_rekey_child_sa_job_t;

/**
 * Private data of an rekey_child_sa_job_t object.
 */
struct private_rekey_child_sa_job_t {
	/**
	 * Public rekey_child_sa_job_t interface.
	 */
	rekey_child_sa_job_t public;

	/**
	 * reqid of the child to rekey
	 */
	u_int32_t reqid;

	/**
	 * protocol of the CHILD_SA (ESP/AH)
	 */
	protocol_id_t protocol;

	/**
	 * inbound SPI of the CHILD_SA
	 */
	u_int32_t spi;
};

METHOD(job_t, destroy, void,
	private_rekey_child_sa_job_t *this)
{
	free(this);
}

METHOD(job_t, checkout_by_id, ike_sa_t*,
	private_rekey_child_sa_job_t *this)
{
	ike_sa_t *ike_sa = NULL;
	int j = 0;
	struct timespec tsa, tsr;

	do {
		ike_sa = charon->ike_sa_manager->checkout_by_id(charon->ike_sa_manager, this->reqid, TRUE);
		if (ike_sa) {
			break;
		}
		j++;
		DBG1(DBG_JOB, "CHILD_SA with reqid %d not found for rekeying, loop: %d",  this->reqid, j);
		tsa.tv_sec = 0;
		tsa.tv_nsec = 0;
		tsr.tv_sec = 0;
		tsr.tv_nsec = 500000000;
		clock_nanosleep(CLOCK_REALTIME_ALARM, 0, &tsr, &tsa);
	} while (j < 10);

	return ike_sa;
}

METHOD(job_t, execute, job_requeue_t,
	private_rekey_child_sa_job_t *this)
{
	ike_sa_t *ike_sa = NULL;
	status_t status = SUCCESS;
	int i = 0;
	struct timespec tsa, tsr;

	ike_sa = checkout_by_id(this);

	if (ike_sa == NULL)
	{
		DBG1(DBG_JOB, "IKE_SA to rekey not found");
	}
	else
	{
		status = ike_sa->rekey_child_sa(ike_sa, this->protocol, this->spi);
		for (i = 1; (i < 60) && (status == NEED_MORE); i++)
		{
			charon->ike_sa_manager->checkin(charon->ike_sa_manager, ike_sa);
			DBG1(DBG_IKE, "delaying rekey_child_sa_job initiation,loop: %d", i);

			tsa.tv_sec = 0;
			tsa.tv_nsec = 0;
			tsr.tv_sec = 0;
			tsr.tv_nsec = 500000000;
			clock_nanosleep(CLOCK_REALTIME_ALARM, 0, &tsr, &tsa);

			ike_sa = checkout_by_id(this);
			if (ike_sa == NULL)
			{
				DBG1(DBG_JOB, "CHILD_SA with reqid %d not found for rekeying",  this->reqid);
				return JOB_REQUEUE_NONE;
			}
			status = ike_sa->rekey_child_sa(ike_sa, this->protocol, this->spi);
		}

		charon->ike_sa_manager->checkin(charon->ike_sa_manager, ike_sa);
	}
	return JOB_REQUEUE_NONE;
}

METHOD(job_t, get_priority, job_priority_t,
	private_rekey_child_sa_job_t *this)
{
	return JOB_PRIO_MEDIUM;
}

/*
 * Described in header
 */
rekey_child_sa_job_t *rekey_child_sa_job_create(u_int32_t reqid,
												protocol_id_t protocol,
												u_int32_t spi)
{
	private_rekey_child_sa_job_t *this;

	INIT(this,
		.public = {
			.job_interface = {
				.execute = _execute,
				.get_priority = _get_priority,
				.destroy = _destroy,
			},
		},
		.reqid = reqid,
		.protocol = protocol,
		.spi = spi,
	);

	return &this->public;
}
