section .text
    global _ft_strcpy

_ft_strcpy:
    ; char  *ft_strcpy(char *dst, const char *src)
    ; dst = rdi, src = rsi
    cmp	rsi, 0              ; if (rsi == NULL)
    je	_exit               ; exitに飛ぶ
    xor	rcx, rcx            ; i = 0
    jmp .loop               ; loopに飛ぶ

.loop:
    mov	dl, BYTE[rsi + rcx] ; レジスタに代入
    mov	BYTE[rdi + rcx], dl ; dst[i] = src[i]
    cmp	dl, 0               ; if (src[i] == '\0')
    je	_exit               ; exitに飛ぶ
    inc	rcx                 ; i++
    jmp	.loop               ; loopの繰り返し

_exit:
    cmp	rax, rdi            ; ???
    ret                     ; return (dst)