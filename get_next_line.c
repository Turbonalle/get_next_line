#include <stdio.h>

char *get_next_line(int fd)
{
	char *buf;
	static char *tmp;
	char *line;
	size_t i;
	size_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	bytes_read = 1;
	line = NULL;

	x = read(fd, buf, n);
	ft_strlcpy(tmp, buf, x);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		line[i] = tmp[i];
	}
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while (i)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}