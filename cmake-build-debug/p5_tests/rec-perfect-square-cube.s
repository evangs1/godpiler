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

findPerfectSquareAndCubes:
push {r4, r5, r6, r7, lr}
mov r6, r0
mov r4, r1
mov r5, r2
cmp r4, r6
mov r3, #0
movlt r3, #1
cmp r3, #0
beq _false0
_true0:
ldr r1, =1
mov r0, r5
bl isSquare
mov r7, r0
ldr r1, =1
mov r0, r5
bl isCube
and r3, r7, r0
cmp r3, #0
beq _false1
_true1:
ldr r3, =1
add r4, r4, r3
b _endif1
_false1:
_endif1:
ldr r3, =1
add r2, r5, r3
mov r0, r6
mov r1, r4
bl findPerfectSquareAndCubes
pop {r4, r5, r6, r7, pc}
b _endif0
_false0:
ldr r3, =1
sub r0, r5, r3
pop {r4, r5, r6, r7, pc}
_endif0:

isSquare:
push {lr}
mul r2, r1, r1
cmp r2, r0
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _false2
_true2:
ldr r0, =0
pop {pc}
b _endif2
_false2:
mul r2, r1, r1
cmp r2, r0
mov r2, #0
moveq r2, #1
cmp r2, #0
beq _false3
_true3:
ldr r0, =1
pop {pc}
b _endif3
_false3:
ldr r2, =1
add r1, r1, r2
bl isSquare
pop {pc}
_endif3:
_endif2:

isCube:
push {lr}
mul r3, r1, r1
mul r2, r3, r1
cmp r2, r0
mov r2, #0
movgt r2, #1
cmp r2, #0
beq _false4
_true4:
ldr r0, =0
pop {pc}
b _endif4
_false4:
mul r3, r1, r1
mul r2, r3, r1
cmp r2, r0
mov r2, #0
moveq r2, #1
cmp r2, #0
beq _false5
_true5:
ldr r0, =1
pop {pc}
b _endif5
_false5:
ldr r2, =1
add r1, r1, r2
bl isCube
pop {pc}
_endif5:
_endif4:

main:
push {lr}
ldr r0, [r1, #4]
bl atoi
ldr r1, =0
ldr r2, =1
bl findPerfectSquareAndCubes
mov r1, r0
ldr r0, =str_fmt_dn
bl printf
pop {pc}

