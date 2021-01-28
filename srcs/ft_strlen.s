section .text
	global	_ft_strlen

_ft_strlen:
	; size_t ft_strlen(const char *s) s = rdi
	xor	rcx, rcx
	jmp	.loop

.loop:
	cmp	BYTE[rdi + rcx], 0
	je	.exit
	inc	rcx
	jmp	.loop

.exit:
	mov	rax, rcx
	ret
