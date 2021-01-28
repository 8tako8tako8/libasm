section .text
	global	_ft_strcmp

_ft_strcmp:
	; int	ft_strcmp(const char *s1, const char *s2)
	; s1 = rdi, s2 = rsi
	xor	rax, rax
	xor	rdx, rdx
	xor	rcx, rcx			; i = 0
	jmp	.loop

.loop:
	mov	al, BYTE[rdi + rcx]
	mov	dl, BYTE[rsi + rcx]
	cmp	al, 0				; if (s1[i] == '\0')
	je	_diff
	cmp	dl, 0				; if (s2[i] == '\0')
	je	_diff
	cmp	al, dl			; if (s1[i] - s2[i])
	jne	_diff				; s1[i] != s2[i]
	inc	rcx				; i++
	jmp .loop

_diff:
	sub rax, rdx
	ret
