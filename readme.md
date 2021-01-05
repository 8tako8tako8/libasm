<h3>libasm</h3>
<p>標準ライブラリのいくつかをIntel記法64bitアセンブリで書く課題。(mac環境)</p>
自作する関数は、プロトタイプ宣言。

```
size_t      ft_strlen(const char *s);
char        *ft_strcpy(char *dst, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t     ft_read(int fildes, const void *buf, size_t nbyte);
char        *ft_strdup(const char *s1);
```

今回実装した*.sファイルは、gccの中間生成物。
普段のコンパイルでは、.c -> .s -> -> .o -> a.out

・アセンブリ
３つのセクションで構成される。今回は各関数をtextセクションに記述した。
```
・dataセクション - 初期化されたデータまたは定数を宣言するために使用される。このデータは実行時に変更されない。
・bssセクション - 変数の宣言に使用される。
・textセクション - 実際のコードを保持するために使用される。
```

・汎用レジスタ
汎用レジスタは１６個ある。
```
・64bit
rax rcx rdx rbx rsp rbp rsi rdi r8  r9  r10 r11 r12 r13 r14 r15
・32bit
eax ecx edx ebx esp ebp esi edi
・16bit
ax  cx  dx  bx  sp  bp  si  di
・8bit
al  cl  dl  bl  spl bpl sil dil
```
```
rax: 戻り値、rdi: 第１引数、rsi: 第２引数、 rdx: 第３引数、rcx: 第４引数、r8: 第５引数、r9: 第６引数
```

```
レジスタへの代入
mov     [レジスタ], 1

レジスタを０に初期化
xor     [レジスタ], [レジスタ]

演算
add     [レジスタ], 1       ; += 1
sub     [レジスタ], 1       ; -= 1
inc     [レジスタ]          ; [レジスタ]++
dec     [レジスタ]          ; [レジスタ]--

ラベルに飛ぶ
jmp     [ラベル]

比較
cmp     [レジスタ], [レジスタ]

cmpの結果からラベルに飛ぶ
je      [ラベル]            ; cmpの結果、等しい時。
jl      [ラベル]            ; cmpの結果、左が大きい時。(signed)
jg      [ラベル]            ; cmpの結果、右が大きい時。(signed)
jz      [ラベル]            ; cmpの結果、=0の時。

レジスタの保存から取り出し
push    [レジスタ]
pop     [レジスタ]

関数を呼び出す。
call    function

システムコールを呼び出す。
syscall
```

<h4>Reference</h4>
<p>[NASMチュートリアル: https://cs.lmu.edu/~ray/notes/nasmtutorial/</p>
<p>macOSシステムコール: https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master</p>
<p>syamashiさん作: https://note.com/syamashi/n/na7c4aeb5f2db</p>
<p>ywakeさん作: https://zenn.dev/wake/articles/13114fd46affd2c38d88</p>
