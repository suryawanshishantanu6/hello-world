%macro scall 4
        mov eax,%1
        mov ebx,%2 
        mov ecx,%3
        mov edx,%4
        int 80h
%endmacro

section .data
        arr dd -18888888h,18888888h,22222222h,11111111h,-33333333h
        n equ 5
        pmsg db 10d,13d,"The Count of Positive No: ",10d,13d
        plen equ $-pmsg
        nmsg db 10d,13d,"The Count of Negative No: ",10d,13d
        nlen equ $-nmsg
        nwline db 10d,13d
    
section .bss
        pcnt resq 1
        ncnt resq 1
        char_answer resb 8
    
section .text
        global _start
        _start:
                mov esi,arr
                mov edi,n
                mov ebx,0
                mov ecx,0
        
        up:    
                mov eax,[esi]
                cmp eax,00000000h
                js negative
    
        positive:       inc ebx
                        jmp next
        negative:       inc ecx
    
        next:    add esi,4
                dec edi
                jnz up

                mov [pcnt],ebx
                mov [ncnt],ecx

                scall 4,1,pmsg,plen
                mov eax,[pcnt]
                call display

                scall 4,1,nmsg,nlen
                mov eax,[ncnt]
                call display
                scall 4,1,nwline,1
                mov eax,1
                mov ebx,0
                int 80h
        
        
;display procedure for 32bit        
display:
        mov esi,char_answer+7
        mov ecx,8

        cnt:    mov edx,0
                mov ebx,16h
                div ebx
                cmp dl,09h
                jbe add30
                add dl,07h
        add30:    add dl,30h
                mov [esi],dl
                dec esi
                dec ecx
                jnz cnt
        scall 4,1,char_answer,8
ret
