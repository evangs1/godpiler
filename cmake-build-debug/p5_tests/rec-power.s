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

power:
push {r4, lr}
mov r4, r0
ldr r2, =0
cmp r1, r2
mov r2, #0
moveq r2, #1
cmp r2, #0
beq _false0
_true0:
ldr r0, =1
pop {r4, pc}
b _endif0
_false0:
ldr r2, =1
sub r1, r1, r2
mov r0, r4
bl power
mul r0, r4, r0
pop {r4, pc}
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
bl power
mov r1, r0
ldr r0, =str_fmt_dn
bl printf
pop {pc}

