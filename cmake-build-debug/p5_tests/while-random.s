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
mov r7, r1
ldr r0, [r7, #4]
bl atoi
mov r6, r0
ldr r0, [r7, #8]
bl atoi
mov r5, r0
ldr r0, [r7, #12]
bl atoi
mov r4, r0
ldr r0, [r7, #16]
bl atoi
ldr r2, =0
ldr r1, =0
_loop0:
cmp r2, r6
mov r3, #0
movlt r3, #1
cmp r3, #0
beq _endloop0
add r3, r1, r5
add r3, r3, r4
add r1, r3, r0
ldr r3, =1
add r2, r2, r3
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

