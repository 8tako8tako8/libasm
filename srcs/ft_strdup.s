extern  _ft_strlen
extern  _malloc
extern  _ft_strcpy

section .text
    global _ft_strdup

_ft_strdup:
    ; char  *ft_strdup(const char *s1)
    push    rdi
    call    _ft_strlen
    mov     rdi, rax
    inc     rdi
    call    _malloc         ; malloc(strlen+1)
    cmp     rax, 0          ; if (rax == NULL)
    je      _error
    mov     rdi, rax
    pop     rsi
    call    _ft_strcpy      ; strcpy(rdi, rsi)
    ret

_error:
    mov     rax, 0
    ret