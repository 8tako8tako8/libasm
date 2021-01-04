section .text
    global _ft_strcpy

_ft_strcpy:
    ; char  *ft_strcpy(char *dst, const char *src)  dst = rdi, src = rsi
    cmp rsi, 0                          ; if (rsi == NULL)
    je  _exit
    xor rcx, rcx                        ; i = 0
    jmp .loop

.loop:
    mov dl, BYTE[rsi + rcx]
    mov BYTE[rdi + rcx], dl             ; dst[i] = src[i]
    cmp dl, 0                           ; if (src[i] == '\0')
    je  _exit
    inc rcx                             ; i++
    jmp .loop

_exit:
    cmp rax, rdi
    ret                                 ; return (dst)