#include "./includes/libasm.h"

int main()
{
	printf("------------ strlen -------------\n");
	printf("[honke: %zu], [zisaku: %zu]\n\n", strlen("hello"), ft_strlen("hello"));
	printf("[honke: %zu], [zisaku: %zu]\n\n", strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	printf("[honke: %zu], [zisaku: %zu]\n\n", strlen(""), ft_strlen(""));

	printf("------------ strcpy -------------\n");
	char	cpy1[100] = "abc";
	char	cpy2[100] = "abc";

	char	*tmp1;
	char	*tmp2;
	tmp1 = strcpy(cpy1, "aaa");
	tmp2 = ft_strcpy(cpy2, "aaa");
	printf("[honke: %s], [zisaku: %s]\n\n", tmp1, tmp2);

	strcpy(cpy1, "");
	ft_strcpy(cpy2, "");
	printf("[honke: %s], [zisaku: %s]\n\n", cpy1, cpy2);
	strcpy(cpy1, "abcdefg");
	ft_strcpy(cpy2, "abcdefg");
	printf("[honke: %s], [zisaku: %s]\n\n", cpy1, cpy2);
	strcpy(cpy1, "1");
	ft_strcpy(cpy2, "1");
	printf("[honke: %s], [zisaku: %s]\n\n", cpy1, cpy2);

	printf("------------ strcmp -------------\n");
	char cmp1[] = "abc";
	char cmp2[] = "abx";
	char cmp3[] = "abb";
	char cmp4[] = "";
	
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp1, cmp2), ft_strcmp(cmp1, cmp2));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp1, cmp1), ft_strcmp(cmp1, cmp1));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp1, cmp3), ft_strcmp(cmp1, cmp3));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp3, cmp1), ft_strcmp(cmp3, cmp1));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp1, cmp4), ft_strcmp(cmp1, cmp4));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp4, cmp1), ft_strcmp(cmp4, cmp1));
	printf("[honke: %d], [zisaku: %d]\n\n", strcmp(cmp4, cmp4), ft_strcmp(cmp4, cmp4));

	printf("------------ write -------------\n");
	int	 count;
	
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
	char	buf1[100] = {};
	char	buf2[100] = {};
	int	 size = 0;

	errno = 0;
	if ((fd = open("read_1.txt", O_RDONLY)) < 0)
	{
		strerror(errno);
		return (0);
	}
	if ((size = read(fd, buf1, 10)) < 0)
	{
		strerror(errno);
		return (0);
	}
	printf("read: [%s], size: %d, errno: %d\n", buf1, size, errno);
	close(fd);

	errno = 0;
	if ((fd = open("read_1.txt", O_RDONLY)) < 0)
	{
		strerror(errno);
		return (0);
	}
	if ((size = ft_read(fd, buf2, 10)) < 0)
	{
		strerror(errno);
		return (0);
	}
	printf("ft_read: [%s], size: %d, errno: %d\n", buf2, size, errno);
	close(fd);

	//char	buf3[100] = {};
	//char	buf4[100] = {};
	/* errno = 0;
	if ((fd = open("not_exist.txt", O_RDONLY)) < 0)
	{
		strerror(errno);
		return (0);
	}
	if ((size = read(fd, buf3, 10)) < 0)
	{
		strerror(errno);
		return (0);
	}
	printf("read: [%s], size: %d, errno: %d\n", buf3, size, errno);
	close(fd); */

	/* errno = 0;
	if ((fd = open("not_exist.txt", O_RDONLY)) < 0)
	{
		strerror(errno);
		return (0);
	}
	if ((size = ft_read(fd, buf4, 10)) < 0)
	{
		strerror(errno);
		return (0);
	}
	printf("ft_read: [%s], size: %d, errno: %d\n", buf4, size, errno);
	close(fd); */

	printf("------------ strdup -------------\n");
	char	*dup1;
	char	*dup2;

	dup1 = strdup("aaaaaaaaaaaaaaa");
	printf(" honke: [%s]\n", dup1);
	free(dup1);
	dup2 = ft_strdup("aaaaaaaaaaaaaaa");
	printf("zisaku: [%s]\n", dup2);
	free(dup2);

	dup1 = strdup("");
	printf(" honke: [%s]\n", dup1);
	free(dup1);
	dup2 = ft_strdup("");
	printf("zisaku: [%s]\n", dup2);
	free(dup2);

	printf("\n");

	return (0);
}
