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
ldr r0, [r1, #4]
bl atoi
ldr r2, =0
ldr r7, =1
ldr r1, =0
_loop0:
cmp r2, r0
mov r3, #0
movlt r3, #1
cmp r3, #0
beq _endloop0
ldr r6, =1
ldr r5, =0
_loop1:
mul r3, r6, r6
cmp r3, r7
mov r4, #0
movle r4, #1
mvn r3, r5
and r3, r4, r3
cmp r3, #0
beq _endloop1
mul r3, r6, r6
cmp r3, r7
mov r3, #0
moveq r3, #1
cmp r3, #0
beq _false0
_true0:
ldr r5, =1
b _endif0
_false0:
ldr r5, =0
_endif0:
ldr r3, =1
add r6, r6, r3
b _loop1
_endloop1:
cmp r5, #0
beq _false1
_true1:
ldr r6, =1
ldr r5, =0
_loop2:
mul r4, r6, r6
mul r3, r4, r6
cmp r3, r7
mov r4, #0
movle r4, #1
mvn r3, r5
and r3, r4, r3
cmp r3, #0
beq _endloop2
mul r4, r6, r6
mul r3, r4, r6
cmp r3, r7
mov r3, #0
moveq r3, #1
cmp r3, #0
beq _false2
_true2:
ldr r5, =1
b _endif2
_false2:
ldr r5, =0
_endif2:
ldr r3, =1
add r6, r6, r3
b _loop2
_endloop2:
cmp r5, #0
beq _false3
_true3:
mov r1, r7
ldr r3, =1
add r2, r2, r3
b _endif3
_false3:
_endif3:
b _endif1
_false1:
_endif1:
ldr r3, =1
add r7, r7, r3
b _loop0
_endloop0:
ldr r0, =str_fmt_dn
bl printf
pop {pc}

