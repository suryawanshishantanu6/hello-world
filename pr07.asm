section .data

fname: db 'abc.txt',0

msg: db "file opened successfully",0x0A
len: equ $-msg


msg1: db "file closed successfully",0x0A
len1: equ $-msg1

msg2: db "error in opening file",0x0A
len2: equ $-msg2

msg3: db "Original array is",0x0A
len3: equ $-msg3

msg4: db "Final array is",0x0A
len4: equ $-msg4

msg5: db "_________________________________",0x0A
len5: equ $-msg5


section .bss

fd: resb 17
fdnew: resb 17
buffer: resb 200
buf_len: resb 17
buffernew: resb 200
buf_lennew: resb 17
cnt: resb 2
cnt2: resb 2
cnt3: resb 2
cha: resb 2

%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro
;__________________________________________________________________________
section .text

global _start
_start:

mov rax,2
mov rdi,fname
mov rsi,2
mov rdx,0777
syscall

mov qword[fd],rax
BT rax,63
jc next
scall 1,1,msg,len
jmp next2
next:
scall 1,1,msg2,len2

next2:

scall 0,[fd],buffer,200
mov qword[buf_len],rax

scall 1,1,msg3,len3
scall 1,1,buffer,[buf_len]

;______________________________________________________________________________
;bubble sort
mov byte[cnt2],5

up2:mov rsi,buffer
mov rdi,buffer+1
mov byte[cnt],5

up:mov al,byte[rsi]
cmp al,byte[rdi]
jg next3
inc rsi
inc rdi
dec byte[cnt]
jnz up
jmp next4

next3:mov bl,byte[rsi]
mov cl,byte[rdi]
mov byte[rdi],bl
mov byte[rsi],cl
inc rsi
inc rdi
dec byte[cnt]
jnz up

next4:dec byte[cnt2]
jnz up2

scall 1,[fd],msg4,len4
scall 1,[fd],buffer,[buf_len]

mov rax,3
mov rdi,[fd]
syscall
scall 1,1,msg1,len1
scall 1,1,msg5,len5
;__________________________________________________________________


mov rax,2
mov rdi,fname
mov rsi,2
mov rdx,0777
syscall

mov qword[fdnew],rax
BT rax,63
jc next5
scall 1,1,msg,len
jmp next6
next5:
scall 1,1,msg2,len2
jmp exit
next6:

scall 0,[fdnew],buffernew,200
mov qword[buf_lennew],rax

scall 1,1,msg3,len3
scall 1,1,buffernew,[buf_lennew]

exit:
mov rax,60
mov rdi,0
syscall
