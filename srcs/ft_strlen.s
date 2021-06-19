section .text
    global _ft_strlen

_ft_strlen:
    ; size_t ft_strlen(const char *s) s = rdi
    xor rcx, rcx                ; 文字数、0に初期化
    jmp .loop                   ; loopに飛ぶ

.loop:
    cmp BYTE[rdi + rcx], 0      ; '\0'であるかチェック
    je  _exit                   ; '\0'ならばexitに跳ぶ
    inc rcx                     ; カウンター変数をインクリメント
    jmp .loop                   ; loopの繰り返し

_exit:
    mov rax, rcx                ; 戻り値用にraxに代入
    ret