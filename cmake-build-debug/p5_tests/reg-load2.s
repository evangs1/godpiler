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
mov r4, r1
ldr r0, [r4, #4]
bl atoi
mov r6, r0
ldr r0, [r4, #8]
bl atoi
add r2, r6, r0
sub r3, r6, r0
mul r4, r2, r3
mul r3, r6, r0
sub r2, r0, r6
mul r2, r3, r2
add r5, r4, r2
ldr r2, =2
add r2, r6, r2
ldr r3, =2
add r3, r0, r3
mul r4, r2, r3
ldr r2, =3
add r3, r6, r2
ldr r2, =3
add r2, r0, r2
mul r2, r3, r2
sub r2, r4, r2
add r1, r5, r2
ldr r0, =str_fmt_dn
bl printf
pop {pc}

