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
mov r5, r1
ldr r0, [r5, #4]
bl atoi
mov r4, r0
ldr r0, [r5, #8]
bl atoi
_loop0:
cmp r4, r0
mov r2, #0
movne r2, #1
cmp r2, #0
beq _endloop0
cmp r4, r0
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _false0
_true0:
sub r4, r4, r0
b _endif0
_false0:
sub r0, r0, r4
_endif0:
b _loop0
_endloop0:
mov r1, r4
ldr r0, =str_fmt_dn
bl printf
pop {pc}

