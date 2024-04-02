.global main
.extern printf
.extern atoi
.section .text

str_fmt_d:
 .asciz "%d"
str_fmt_dn:
 .asciz "%d\n"
str_fmt_s:
 .asciz "%s"
str_fmt_sn:
 .asciz "%s\n"
.align

main:
push {lr}
mov r5, r1
ldr r0, [r5, #4]
bl atoi
mov r4, r0
ldr r0, [r5, #8]
bl atoi
ldr r1, =1
_loop0:
ldr r2, =0
cmp r0, r2
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _endloop0
mul r2, r1, r4
mov r1, r2
ldr r2, =1
sub r0, r0, r2
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

