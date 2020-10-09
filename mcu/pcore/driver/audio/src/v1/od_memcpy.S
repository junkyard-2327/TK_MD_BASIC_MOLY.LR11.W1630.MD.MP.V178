.global od_memcpy
.type   od_memcpy, %function

od_memcpy:
    push   {r3 - r10}
LDMloop:
    LDMIA  r1!, {r3 - r10}

    STRH   r3,  [r0], #02
    LSR    r3,  r3,   #16
    STRH   r3,  [r0], #02

    STRH   r4,  [r0], #02
    LSR    r4,  r4,   #16
    STRH   r4,  [r0], #02

    STRH   r5,  [r0], #02
    LSR    r5,  r5,   #16
    STRH   r5,  [r0], #02

    STRH   r6,  [r0], #02
    LSR    r6,  r6,   #16
    STRH   r6,  [r0], #02

    STRH   r7,  [r0], #02
    LSR    r7,  r7,   #16
    STRH   r7,  [r0], #02

    STRH   r8,  [r0], #02
    LSR    r8,  r8,   #16
    STRH   r8,  [r0], #02

    STRH   r9,  [r0], #02
    LSR    r9,  r9,   #16
    STRH   r9,  [r0], #02

    STRH   r10, [r0], #02
    LSR    r10, r10,  #16
    STRH   r10, [r0], #02

    SUBS   r2,  r2,   #0x20
    LDR    r3,  =0
    CMP    r2,  r3
    BNE    LDMloop
    
    POP    {r3 - r10}
    bx     lr