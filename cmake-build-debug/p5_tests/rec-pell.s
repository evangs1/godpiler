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

printPellSequence:
push {r4, r5, r6, lr}
mov r4, r2
ldr r5, =1
sub r5, r0, r5
cmp r1, r5
mov r5, #0
movlt r5, #1
cmp r5, #0
beq _false0
_true0:
ldr r5, =1
add r1, r1, r5
ldr r6, =2
mul r5, r6, r4
add r2, r5, r3
mov r3, r4
bl printPellSequence
pop {r4, r5, r6, pc}
b _endif0
_false0:
mov r0, r3
pop {r4, r5, r6, pc}
_endif0:

main:
push {lr}
ldr r0, [r1, #4]
bl atoi
ldr r1, =0
ldr r2, =1
ldr r3, =0
bl printPellSequence
mov r1, r0
ldr r0, =str_fmt_dn
bl printf
pop {pc}

