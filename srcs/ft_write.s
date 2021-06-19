extern ___error
section .text
    global _ft_write

_ft_write:
    ; ssize_t ft_write(int fildes, const void *buf, size_t nbyte)
    mov     rax, 0x2000004      ; writeシステムコール呼び出し用
    syscall
    jc      _error              ; rax = errno(システムコール失敗時にキャリーフラグが設定される)
    ret

_error:
    push    rax                 ; errnoを保存する
    call    ___error            ; errnoへのアドレスを取得
    pop     rdi                 ; 保存しておいたerrnoを取得
    mov     [rax], rdi          ; __errorの戻り値にerrnoへのアドレスを入れる
    mov     rax, -1             ; 戻り値に-1を代入
    ret