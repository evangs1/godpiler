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

sumOfN:
push {r4, lr}
mov r4, r0
ldr r1, =0
cmp r4, r1
mov r1, #0
movle r1, #1
cmp r1, #0
beq _false0
_true0:
ldr r0, =0
pop {r4, pc}
b _endif0
_false0:
ldr r1, =1
sub r0, r4, r1
bl sumOfN
add r0, r4, r0
pop {r4, pc}
_endif0:

main:
push {lr}
ldr r0, [r1, #4]
bl atoi
bl sumOfN
mov r1, r0
ldr r0, =str_fmt_dn
bl printf
pop {pc}

