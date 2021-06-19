section .text
    global _ft_strcmp

_ft_strcmp:
    ; int ft_strcmp(const char *s1, const char *s2)
    ; s1 = rdi, s2 = rsi
    xor rax, rax            ; 0に初期化
    xor rdx, rdx            ; 0に初期化
    xor rcx, rcx            ; 0に初期化
    jmp .loop               ; loopに飛ぶ

.loop:
    mov al, BYTE[rdi + rcx] ; 比較用にレジスタに代入
    mov dl, BYTE[rsi + rcx] ; 比較用にレジスタに代入
    cmp al, 0               ; if (s1[i] == '\0')
    je  _diff               ; diffに飛ぶ
    cmp dl, 0               ; if (s2[i] == '\0')
    je  _diff               ; diffに飛ぶ
    cmp al, dl              ; if (s1[i] - s2[i])
    jne _diff               ; s1[i] != s2[i]
    inc rcx                 ; カウンター変数のインクリメント
    jmp .loop               ; loopの繰り返し

_diff:
    sub rax, rdx            ; 差がraxに入る
    ret
