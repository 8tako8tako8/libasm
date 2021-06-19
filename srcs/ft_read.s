extern ___error
section .text
    global  _ft_read

_ft_read:
    ; ssize_t ft_read(int fildes, const void *buf, size_t nbyte)
    mov     rax, 0x2000003  ; readシステムコール呼び出し用
    syscall
    jc      _error          ; rax = errno
    ret

_error:
    push    rax             ; errnoの保存
    call    ___error        ; errnoへのアドレスを取得
    pop     rdi             ; 保存しておいたerrnoを取得
    mov     [rax], rdi      ; __errorの戻り値にerrnoへのアドレスを入れる
    mov     rax, -1         ; 戻り値に-1を代入
    ret
