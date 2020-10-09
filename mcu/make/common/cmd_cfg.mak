#########################
## common variable part ##
##########################
# script, tools, commands

ifndef COMMON_ROOT
COMMON_ROOT = common
endif

CAT             = perl ${COMMON_ROOT}/tools/init/cat.pl
CHK_OS          = perl ${COMMON_ROOT}/tools/init/chkOS.pl
CH_MOD          = perl ${COMMON_ROOT}/tools/init/chmod.pl
COPY_FILE       = perl ${COMMON_ROOT}/tools/init/copy_files.pl -f
COPY_DIR        = perl ${COMMON_ROOT}/tools/init/copy_files.pl -r
COMPARE         = perl ${COMMON_ROOT}/tools/init/compare.pl
DEL_FILE        = perl ${COMMON_ROOT}/tools/init/remove.pl -f
DEL_DIR         = perl ${COMMON_ROOT}/tools/init/rmdir.pl -f
ECHO            = perl ${COMMON_ROOT}/tools/init/echo.pl
GET_FNAME       = perl ${COMMON_ROOT}/tools/init/get_filename.pl
LIST_DIR        = perl ${COMMON_ROOT}/tools/init/dir.pl
MKDIR           = perl ${COMMON_ROOT}/tools/init/mkdir.pl
MOVE            = perl ${COMMON_ROOT}/tools/init/move.pl -f
RECURSIVE_DIR   = perl ${COMMON_ROOT}/tools/init/recursive_dir.pl

LNITEM          = perl ${COMMON_ROOT}/tools/lnitem.pl
ECHOLONGSTRING  = perl ${COMMON_ROOT}/tools/echoLongString.pl
ECHOLONGSTRING2 = perl $(COMMON_ROOT)/tools/echoLongString2.pl
ECHOLONGSTRING3 = perl $(COMMON_ROOT)/tools/echoLongString3.pl
ECHOLONGSTRING4 = perl $(COMMON_ROOT)/tools/echoLongString4.pl
ECHOLONGSTRING5 = perl $(COMMON_ROOT)/tools/echoLongString5.pl
CHDIR           = cd

# others
AND           = &&


OS_VERSION = $(shell perl ${COMMON_ROOT}/tools/init/chkOS.pl)
#####################
## windows section ##
#####################
ifeq ($(strip $(OS_VERSION)),MSWin32)
# script, tools, commands
LINKER        = "${CORE_ROOT}/mtk_tools/guardian/Linker.exe"
SENDER        = "${CORE_ROOT}/mtk_tools/guardian/Sender.exe"
STRCMPEX      = ${COMMON_ROOT}\tools\init\strcmpex_window.exe
MAKE          = "${CORE_ROOT}/tools/make.exe"
GREP_V        = find /V

# if-else command
IF            = if
IF_EXIST      = if exist
IF_NOT        = if not
IF_NOT_EXIST  = if not exist
IF_ERR_TRUE   = if ERRORLEVEL 1 
IF_ERR_FALSE  = if not errorlevel 1
THEN          = 
ELSE          = else
CMD_END       =

# for loop command
FOR           = for
F_OPT         = /F usebackq
IN            = in (
DO            = ) do 
DONE          =

# condition
EQU           = EQU
NEQ           = NEQ

# others
DEV_NUL       = NUL
DECLARE_VAR   = %%
PRE_VAR       = %%
P_VAR         = %
WITH          = &

else
###################
## Linux section ##
###################
# script, tools
LINKER        = ${CORE_ROOT}/mtk_tools/guardian/Linker
SENDER        = ${CORE_ROOT}/mtk_tools/guardian/Sender
STRCMPEX      = ${COMMON_ROOT}/tools/init/strcmpex_linux.exe
MAKE          = make
GREP_V        = grep -v

# if-else command
IF            = if [ 
IF_EXIST      = if [ -e
IF_NOT        = if [ ! 
IF_NOT_EXIST  = if [ ! -e
IF_ERR_TRUE   = if [ $$? != 0
IF_ERR_FALSE  = if [ $$? == 0
THEN          =  ]; then 
ELSE          = ;else
CMD_END       =  ;fi


# for loop command
FOR           = for
F_OPT         =
IN            = in
DO            = ;do 
DONE          = ;done

# condition
EQU           = =
NEQ           = !=

# others
DEV_NUL       = /dev/null
DECLARE_VAR   =
PRE_VAR       = $$
P_VAR         = $
WITH          = ;

endif # OS_VERSION end

