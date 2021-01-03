section .text
    global _ft_strlen

_ft_strlen:
    ; size_t ft_strlen(const char *s)
    mov rsi, 0
    jmp .loop

.loop:
    cmp BYTE[rdi + rsi], 0
    je  .exit
    inc rsi
    jmp .loop

.exit:
    mov rax, rsi
    ret
