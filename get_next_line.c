#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
	1. Read onto "buf"
	2. While isn't NULL, copy "buf" to "tmp"
	3. 

*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	int BUFFER_SIZE = 5;
	char buf[BUFFER_SIZE];
	static char *tmp;
	char *line;
	size_t i;
	size_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	bytes_read = 1;
	line = NULL;

	// check how much is read
	bytes_read = read(fd, buf, BUFFER_SIZE);

	printf("Test%zu\n", bytes_read);
	
	// copy buf -> tmp
	ft_strlcpy(tmp, buf, bytes_read);
	
	// copy tmp -> line
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i] = tmp[i];
	return (line);
}

int main()
{
	int fd;
	char *line;
	int i;

	fd = open("test.txt", O_RDONLY | S_IRUSR);
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}