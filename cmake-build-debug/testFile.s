str_fmt_d:
 .asciz "%d"
str_fmt_dn:
 .asciz "%d\n"
str_fmt_s:
 .asciz "%s"
str_fmt_sn:
 .asciz "%s\n"
func:
push {lr}
mul r2, r0, r1
mov r0, r2
pop {pc}
main:
push {r4, lr}
ldr r1, [r1, #4]
ldr r0, =str_fmt_sn
bl printf
mov r4, #1
_loop0:
mov r2, #10
cmp r4, r2
mov r2, #0
movlt r2, #1
cmp r2, #0
beq _endloop0
mov r1, #2
mov r0, r4
bl func
mov r4, r0
mov r1, r4
ldr r0, =str_fmt_dn
bl printf
b _loop0
_endloop0:
pop {r4, pc}
