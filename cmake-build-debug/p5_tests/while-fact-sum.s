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
ldr r4, =1
_loop0:
cmp r4, r0
mov r2, #0
movle r2, #1
cmp r2, #0
beq _endloop0
ldr r3, =1
ldr r2, =1
_loop1:
cmp r2, r4
mov r5, #0
movle r5, #1
cmp r5, #0
beq _endloop1
mul r5, r3, r2
mov r3, r5
ldr r5, =1
add r2, r2, r5
b _loop1
_endloop1:
add r1, r1, r3
ldr r2, =1
add r4, r4, r2
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

