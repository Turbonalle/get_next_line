#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t BUF_SIZE = 4;

char *check_for_line(char *str)
{
	while (str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char *get_next_line(int fd)
{
	char **str_array;
	char buffer[BUF_SIZE];
	size_t bytes_read;
	size_t i;
	size_t n;
	int boolean;

	bytes_read = read(fd, buffer, BUF_SIZE);
	boolean = 0;
	n = 0;
	// read until newline or end is reached
	while (bytes_read >= 0 && boolean == 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			str_array[n][i] = buffer[i];
			i++;
		}
		str_array[i] = '\0';
		n++;
		bytes_read = read(fd, buffer, BUF_SIZE);
		if (check_for_newline(str_array[i]))
		{
			while (str_array[i])
			{
				
			}
			boolean = 1;
		}
	}

	
	
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