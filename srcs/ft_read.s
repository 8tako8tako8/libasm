extern	___error
section .text
	global	_ft_read

_ft_read:
	; ssize_t	ft_read(int fildes, const void *buf, size_t nbyte)
	mov	rax, 0x2000003
	syscall
	jc	_error			; rax = errno
	ret

_error:
	push	rax			; save errno
	call	___error		; retrieve address to errno
	pop	rdi
	mov	[rax], rdi		; put errno in return value of __error (pointer to errno)
	mov	rax, -1
	ret
