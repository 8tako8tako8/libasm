extern _ft_strlen
extern _malloc
extern _ft_strcpy

section .text
    global	_ft_strdup

_ft_strdup:
    ; char *ft_strdup(const char *s1)
    push rdi            ; s1の保存
    call _ft_strlen     ; ft_strlenを呼び出し
    mov rdi, rax        ; strlenの結果をrdiに代入
    inc rdi             ; カウンター変数をインクリメント
    call _malloc        ; malloc(strlen+1)
    cmp rax, 0          ; if (rax == NULL)
    je _error           ; errorに飛ぶ
    mov rdi, rax        ; mallocしたものをrdiに代入
    pop rsi             ; はじめにpushしたs1を取得
    call _ft_strcpy     ; strcpy(rdi, rsi)
    ret

_error:
    mov rax, 0
    ret