#include "./includes/libasm.h"

void	print_ft_strlen(char s[]){
	int n;
	printf("-----ft_strlen(%s)-----\n", s);
	n = ft_strlen(s);
	printf("ft_strlen:[%d]\n", n);
	n = strlen(s);
	printf("   strlen:[%d]\n\n", n);
}

void	print_ft_strcpy(char s1[], char s2[]){
	char *tmp = strdup(s1);
	char *s3;
	printf("-----ft_strcpy(%s, %s)-----\n", s1, s2);
	s3 = ft_strcpy(s1, s2);
	printf("ft_strcpy:[%s]\n", s3);
	ft_strcpy(s1, tmp);
	s3 = strcpy(s1, s2);
	printf("   strcpy:[%s]\n\n", s3);
	strcpy(s1, tmp);
	free(tmp);
}

void	print_ft_strcmp(char s1[], char s2[]){
	int n;
	printf("-----ft_strcmp(%s, %s)-----\n", s1, s2);
	n = ft_strcmp(s1, s2);
	printf("ft_strcmp:[%d]\n", n);
	n = strcmp(s1, s2);
	printf("   strcmp:[%d]\n\n", n);
}

void	print_ft_write(int fd, char s[], size_t byte){
	errno = 0;
	printf("-----ft_write(%d, %s, %zu)-----\n", fd, s, byte);
	printf("ft_write:[");
	int count = ft_write(fd, s, byte);
	printf("] count:[%d]", count);
	printf(" strerror:[%s]", strerror(errno));
	printf(" error:[%d]\n", errno);
	errno = 0;
	printf("   write:[");
	count = write(fd, s, byte);
	printf("] count:[%d]", count);
	printf(" strerror:[%s]", strerror(errno));
	printf(" error:[%d]\n\n", errno);
}

void	print_ft_read(char pass[], char buf[]){
	int fd;
	int n;
	int i = -1;
	while (++i < 1024)
		buf[i] = 0;
	errno = 0;
	fd = open(pass, O_RDONLY);
	n = ft_read(fd, buf, 1024);
	printf("-----ft_read(fd:[%d], pass:[%s])-----\n", fd, pass);
	printf("ft_read:[%s]\n", buf);
	printf("val:[%d], strerror:[%s], errno:[%d]\n", n, strerror(errno), errno);
	close(fd);
	i = 0;
	while (++i < 1024)
		buf[i] = 0;
	errno = 0;
	fd = open(pass, O_RDONLY);
	n = read(fd, buf, 1024);
	printf("   read:[%s]\n", buf);
	printf("val:[%d], strerror:[%s], errno:[%d]\n\n", n, strerror(errno), errno);
	close(fd);
}

void	print_ft_strdup(char s[]){
	char *dup;

	printf("-----ft_strdup(%s)-----\n", s);
	dup = ft_strdup(s);
	printf("ft_strdup:[%s]\n", dup);
	free(dup);
	dup = strdup(s);
	printf("   strdup:[%s]\n\n", dup);
	free(dup);
}

int main()
{
    printf("------------ strlen -------------\n");
    printf("[honke: %zu], [zisaku: %zu]\n", strlen("hello"), ft_strlen("hello"));
    printf("[honke: %zu], [zisaku: %zu]\n", strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    printf("[honke: %zu], [zisaku: %zu]\n", strlen(""), ft_strlen(""));

    printf("------------ strcpy -------------\n");
    char    cpy1[100] = "abc";
    char    cpy2[100] = "abc";

    strcpy(cpy1, "");
    ft_strcpy(cpy2, "");
    printf("[honke: %s], [zisaku: %s]\n", cpy1, cpy2);
    strcpy(cpy1, "abcdefg");
    ft_strcpy(cpy2, "abcdefg");
    printf("[honke: %s], [zisaku: %s]\n", cpy1, cpy2);
    strcpy(cpy1, "1");
    ft_strcpy(cpy2, "1");    
    printf("[honke: %s], [zisaku: %s]\n", cpy1, cpy2);

    printf("------------ strcmp -------------\n");
    printf("[honke: %d], [zisaku: %d]\n", strcmp("abc", "abc"), ft_strcmp("abc", "abc"));
    printf("[honke: %d], [zisaku: %d]\n", strcmp("abc", "abb"), ft_strcmp("abc", "abb"));
    printf("[honke: %d], [zisaku: %d]\n", strcmp("abb", "abc"), ft_strcmp("abb", "abc"));
    printf("[honke: %d], [zisaku: %d]\n", strcmp("abc", ""), ft_strcmp("abc", ""));
    printf("[honke: %d], [zisaku: %d]\n", strcmp("", "abc"), ft_strcmp("", "abc"));
    printf("[honke: %d], [zisaku: %d]\n", strcmp("", ""), ft_strcmp("", ""));

    printf("------------ write -------------\n");
	int     count;
    
	errno = 0;
    count = write(1, "hello", 6);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, "hello", 6);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(1, "hello", 3);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, "hello", 3);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(1, "hello", 0);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, "hello", 0);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(1, "", 1);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, "", 1);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(2, "hello", 6);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(2, "hello", 6);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(1, NULL, 1);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, NULL, 1);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(1, NULL, -1);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(1, NULL, -1);
	printf(", count: %d, errno: %d\n\n", count, errno);

	errno = 0;
    count = write(42, "hello", 6);
	printf(", count: %d, errno: %d\n", count, errno);
 	errno = 0;
    count = ft_write(42, "hello", 6);
	printf(", count: %d, errno: %d\n\n", count, errno);

    int fd;
    fd = open("test.txt", O_RDWR | O_CREAT, 0644);
	ft_write(fd, "hello world!", 12);
	close(fd);

    printf("------------ read -------------\n");
    char    buf1[100] = {};
    char    buf2[100] = {};
    char    buf3[100] = {};
    char    buf4[100] = {};
    int     size = 0;

	errno = 0;
	fd = open("read_1.txt", O_RDONLY);
	size = read(fd, buf1, 10);
	printf("read: [%s], size: %d, errno: %d\n", buf1, size, errno);
	close(fd);
	errno = 0;
	fd = open("read_1.txt", O_RDONLY);
	size = ft_read(fd, buf2, 10);
	printf("ft_read: [%s], size: %d, errno: %d\n", buf2, size, errno);
	close(fd);

	errno = 0;
	fd = open("not_exist.txt", O_RDONLY);
	size = read(fd, buf3, 10);
	printf("read: [%s], size: %d, errno: %d\n", buf3, size, errno);
	close(fd);
	errno = 0;
	fd = open("not_exist.txt", O_RDONLY);
	size = ft_read(fd, buf4, 10);
	printf("ft_read: [%s], size: %d, errno: %d\n", buf4, size, errno);
	close(fd);

    printf("------------ strdup -------------\n");
    char    *dup1;
    char    *dup2;

    dup1 = strdup("aaaaaaaaaaaaaaa");
    printf("honke: [%s]\n", dup1);
    free(dup1);
    dup2 = ft_strdup("aaaaaaaaaaaaaaa");
    printf("zisaku: [%s]\n", dup2);
    free(dup2);

    dup1 = strdup("");
    printf("honke: [%s]\n", dup1);
    free(dup1);
    dup2 = ft_strdup("");
    printf("zisaku: [%s]\n", dup2);
    free(dup2);

	return (0);
}
