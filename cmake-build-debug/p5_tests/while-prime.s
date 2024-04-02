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
str_lit_label0:
 .asciz "true"
str_lit_label1:
 .asciz "false"
.align

sqrt:
push {r4, lr}
ldr r1, =0
mov r4, r1
ldr r3, =0
_loop0:
cmp r3, r0
mov r1, #0
movle r1, #1
cmp r1, #0
beq _endloop0
ldr r1, =2
mul r2, r1, r4
ldr r1, =1
add r1, r2, r1
add r3, r3, r1
ldr r1, =1
add r1, r4, r1
mov r4, r1
b _loop0
_endloop0:
ldr r1, =1
sub r0, r4, r1
pop {r4, pc}

isPrime:
push {r4, r5, r6, lr}
mov r5, r0
ldr r1, =1
cmp r5, r1
mov r1, #0
movle r1, #1
cmp r1, #0
beq _false0
_true0:
ldr r0, =0
pop {r4, r5, r6, pc}
b _endif0
_false0:
ldr r4, =2
_loop1:
mov r0, r5
bl sqrt
cmp r4, r0
mov r1, #0
movle r1, #1
cmp r1, #0
beq _endloop1
mov r3, r5
mov r2, r4
ldr r1, =0
_loop2:
cmp r3, r2
mov r6, #0
movge r6, #1
cmp r6, #0
beq _endloop2
sub r3, r3, r2
ldr r6, =1
add r1, r1, r6
b _loop2
_endloop2:
ldr r1, =0
cmp r3, r1
mov r1, #0
moveq r1, #1
cmp r1, #0
beq _false1
_true1:
ldr r0, =0
pop {r4, r5, r6, pc}
b _endif1
_false1:
ldr r1, =1
add r4, r4, r1
_endif1:
b _loop1
_endloop1:
ldr r0, =1
pop {r4, r5, r6, pc}
_endif0:

main:
push {lr}
ldr r0, [r1, #4]
bl atoi
bl isPrime
cmp r0, #0
beq _false2
_true2:
ldr r1, =str_lit_label0
ldr r0, =str_fmt_sn
bl printf
b _endif2
_false2:
ldr r1, =str_lit_label1
ldr r0, =str_fmt_sn
bl printf
_endif2:
pop {pc}

