.section .text
.global _start
.arm

_start:
    LDR sp, =_stack_top

    LDR r0, =_bss_start
    LDR r1, =_bss_end
    MOV r2, #0