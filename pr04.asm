section .data
msg  db 10d,13d,"                   MENU For Multiplication"
     db 10d,"1. Successive Addition"
     db 10d,"2. Shift and Add method"
     db 10d,"3. Exit"
     db 10d
     db 10d,"Enter your choice: "
msglen equ $-msg

msg1 db 10,13,"Enter first 4 digit hexadecimal no:"
msg1len equ $-msg1

msg2 db 10,13,"Enter second 4 digit hexadecimal no:"
msg2len equ $-msg2

msg3 db 10,13,"Result by first method is:"
msg3len equ $-msg3

msg4 db 10,13,"Result by second method is:"
msg4len equ $-msg4

section .bss
choice resb 2
abc resb 8
num1 resb 5
num2 resb 5
cnt resb 1
num resb 5
number resb 4

%macro display 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro



section .text
global _start
_start:

display msg,msglen
accept choice,2
mov al,[choice]
sub al,30h

cmp al,01
je successive_addition

cmp al,02
je add_rol

cmp al,03
je exit

successive_addition:

display msg1,msg1len
accept num,5
call ascii_original

mov [num1],rbx

display msg2,msg2len
accept num,5
call ascii_original

mov [num2],rbx

mov rbx,0
mov rax,0  ;used for sum variable
mov rdx,0    ;used for carry

mov rbx,[num1]
mov rcx,[num2]
l11:
add rax,rbx
jnc l12
inc rdx    ;ie carry=carry+1

l12:
dec rcx
jnz l11

mov rbx,0

call original_ascii
jmp _start

add_rol:
display msg1,msg1len

accept num,5
call ascii_original
mov [num1],bx

display msg2,msg2len
accept num,5
call ascii_original
mov [num2],bx

mov rax,0
mov rbx,0
mov rcx,0

mov cx,16

mov ax,[num1]
mov bx,[num2]

l15:
;add rax,rax

shl ax,1
jnc l66
add ax,bx
l66:    dec cl
jnz l15
;mov bx,ax
call original_ascii

exit:
mov rax,60
mov rbx,0
syscall

ascii_original:
mov esi,num
mov ecx,4
mov bx,0

l2:
rol bx,4
mov al,[esi]
cmp al,39h
jbe l3
sub al,07h

l3:
sub al,30h
mov ah,0
add bx,ax
inc esi
loop l2

ret

original_ascii:
mov ecx,4
mov esi,number

l4:
rol ax,4
mov dl,al
and dl,0fh
cmp dl,09h
jbe l5
add dl,07h
l5:
add dl,30h
mov [esi],dl
inc esi
loop l4
display number,4
ret
