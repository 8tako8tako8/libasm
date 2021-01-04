section .text
    global _ft_strchr

_ft_strchr:
    ; char  *ft_strchr(const char *s, int c)
    mov rdx, 0
    jmp .loop

.loop:
    cmp BYTE[rdi + rdx], sil
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
