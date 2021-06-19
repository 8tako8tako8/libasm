section .text
    global _ft_strchr

_ft_strchr:
    ; char *ft_strchr(const char *s, int c)
    xor rdx, rdx                ; 0に初期化
    jmp .loop                   ; loopに飛ぶ

.loop:
    cmp BYTE[rdi + rdx], sil    ; c='\0'の時のための比較
    je  .exit
    cmp BYTE[rdi + rdx], 0
    je  .error
    inc rdx
    jmp .loop

.exit:
    add rdi, rdx
    mov rax, rdi
    ret

.error:
    mov rax, 0
    ret
