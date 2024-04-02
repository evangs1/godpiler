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
mov r2, r0
ldr r0, [r4, #8]
push {r2}
bl atoi
pop {r2}
add r9, r2, r0
sub r8, r2, r0
mul r7, r2, r0
sub r6, r0, r2
ldr r3, =2
add r5, r2, r3
ldr r3, =2
add r4, r0, r3
ldr r3, =3
add r3, r2, r3
ldr r2, =3
add r2, r0, r2
mul r8, r9, r8
mul r6, r7, r6
mul r4, r5, r4
mul r2, r3, r2
add r3, r8, r6
sub r2, r4, r2
add r1, r3, r2
ldr r0, =str_fmt_dn
bl printf
pop {pc}

