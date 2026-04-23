.section .text
.global _start
.arm

_start:
    LDR sp, =_stack_top

    LDR r0, =_bss_start
    LDR r1, =_bss_end
    MOV r2, #0

bss_loop:
    CMP r0, r1
    BGE bss_done
    STR r2, [r0], #4
    B bss_loop

bss_done:
    LDR r0, =_data_flash_start
    LDR r1, =_data_start
    LDR r2, =_data_end