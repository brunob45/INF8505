.text_segment PM 0
    r0 = 0x0a
    r1 = 0x70
    r2 = 30
    r4 = 0
    r4 = r4 + r0
    r4 = r4 + r1
    r4 = r4 - r1
    r4 = r4 | r1
    r4 = r4 & r1
    goto L1
    r4 = r4 - r1
    nop
    nop
L1: r4 = 100
    nop
    nop
    nop
.stop
    nop
    nop
