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

gcd:
push {lr}
cmp r0, r1
mov r2, #0
moveq r2, #1
cmp r2, #0
beq _false0
_true0:
pop {pc}
b _endif0
_false0:
cmp r0, r1
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _false1
_true1:
sub r0, r0, r1
bl gcd
pop {pc}
b _endif1
_false1:
sub r1, r1, r0
bl gcd
pop {pc}
_endif1:
_endif0:

main:
push {lr}
mov r5, r1
ldr r0, [r5, #4]
bl atoi
mov r4, r0
ldr r0, [r5, #8]
bl atoi
mov r1, r0
mov r0, r4
bl gcd
mov r1, r0
ldr r0, =str_fmt_dn
bl printf
pop {pc}

