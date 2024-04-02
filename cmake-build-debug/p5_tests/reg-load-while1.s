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
mov r6, r1
ldr r0, [r6, #4]
bl atoi
mov r5, r0
ldr r0, [r6, #8]
bl atoi
mov r4, r0
ldr r0, [r6, #12]
bl atoi
ldr r1, =0
_loop0:
ldr r2, =0
cmp r0, r2
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _endloop0
add r7, r5, r4
sub r6, r5, r4
mul r3, r5, r4
sub r2, r4, r5
mul r6, r7, r6
add r6, r1, r6
mul r2, r3, r2
add r1, r6, r2
ldr r2, =1
sub r0, r0, r2
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

