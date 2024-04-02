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
ldr r0, [r1, #4]
bl atoi
ldr r1, =0
ldr r5, =1
ldr r4, =0
_loop0:
ldr r2, =1
sub r2, r0, r2
cmp r4, r2
mov r2, #0
movlt r2, #1
cmp r2, #0
beq _endloop0
ldr r3, =2
mul r2, r3, r5
add r2, r2, r1
mov r1, r5
mov r5, r2
ldr r2, =1
add r4, r4, r2
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

