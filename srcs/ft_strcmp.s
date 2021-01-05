section .text
    global _ft_strcmp

_ft_strcmp:
    ; int   ft_strcmp(const char *s1, const char *s2)   s1 = rdi, s2 = rsi
    xor rax, rax
    xor rdx, rdx
    xor rcx, rcx                            ; i = 0
    jmp .loop

.loop:
    mov dl, BYTE[rdi + rcx]
    mov al, BYTE[rsi + rcx]
    cmp dl, 0                               ; if (s1[i] == '\0')
    je  _cmp
    cmp al, 0                  ; if (s2[i] == '\0')
    je  _cmp
    cmp rdx, rax                            ; if (s1[i] - s2[i])
    jne _cmp                                ; s1[i] != s2[i]
    inc rcx                                 ; i++
    jmp .loop

_cmp:
    cmp rdx, rax
    jg  _greater
    jl  _less
    je  _equal

_greater:
    mov rax, 1
    ret

_less:
    mov rax, -1
    ret

_equal:
    mov rax, 0
    ret