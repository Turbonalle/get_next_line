#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t BUF_SIZE = 5;


//-[LIBFT]----------------------------------------------------------------------

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if (c == 0)
		return (ptr);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((count * size) % size != 0)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (*s1)
		joined_str[i++] = *s1++;
	while (*s2)
		joined_str[i++] = *s2++;
	joined_str[i] = 0;
	return (joined_str);
}


//-[HELPER]---------------------------------------------------------------------

static char	*ft_copy_and_free(char *buffer, char *add_to_end)
{
	char	*temp;
	
	temp = ft_strjoin(buffer, add_to_end);
	free(buffer);
	return (temp);
}

static char	*ft_get_rest(char *buffer)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (!buffer[i]) // Changed to check for eof instead of checking the whole buffer
	{
		free(buffer);
		return (NULL);
	}
	// j = 0;
	// while (buffer[j])
	// 	j++;
	trimmed = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char)); // Changed to strlen instead of iterating with j, so i would save two lines. Also fixed miscalculation by adding one byte for ending char
	if (!trimmed)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		trimmed[j++] = buffer[i++];
	// trimmed[j] = '\0';	// Removed adding the terminating char
	free(buffer);
	return (trimmed);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])	// Added buffer check to avoid unnecessary steps if buffer is empty
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char)); // Added one more byte for the terminating char. Had miscounted it...
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	// line[i] = buffer[i];
	return (line);
}

static char	*ft_read(char *result, int fd)
{
	char	*buffer;
	int		bytes_read;

	if (!result) // Moved NULL-check here instead of gnl()
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUF_SIZE + 1, sizeof(char));
	// if (!buffer)	// This should not be needed, since we're accounting for (BUF_SIZE <= 0) in gnl()
	// 	return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUF_SIZE);
		if (bytes_read < 0)
			free(buffer); // Added freeing to avoid mem leak at eof
			return (NULL);
		buffer[bytes_read] = '\0';
		result = ft_copy_and_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUF_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	// if (!buffer)
	// {
	// 	buffer = ft_calloc(1, 1);
	// 	buffer[0] = '\0';
	// }

	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_rest(buffer);
	return (line);
}




















//-[MAIN]--------------------------------------------------------------------------

void test_textfiles()
{
	char *line1;
	char *line2;
	char *line3;
	char *line4;
	char *line5;
	char *line6;
	char *line7;
	char *line8;
	char *line9;
	int i;

	int fd1 = open("test1.txt", O_RDONLY | S_IRUSR);
	int fd2 = open("test2.txt", O_RDONLY | S_IRUSR);
	int fd3 = open("test3.txt", O_RDONLY | S_IRUSR);
	int fd4 = open("test4.txt", O_RDONLY | S_IRUSR);
	int fd5 = open("test5.txt", O_RDONLY | S_IRUSR);
	int fd6 = open("test6.txt", O_RDONLY | S_IRUSR);
	int fd7 = open("test7.txt", O_RDONLY | S_IRUSR);
	int fd8 = open("test8.txt", O_RDONLY | S_IRUSR);
	int fd9 = open("test9.txt", O_RDONLY | S_IRUSR);

	i = 0;
	//printf("BUF_SIZE = %zu\n\n", BUF_SIZE);
	while (i < 6)
	{
		line1 = get_next_line(fd1);
		if (line1 == NULL)
			break;
		// printf("GNL = '%s'\n\n", line1);
		printf("%s", line1);
		free(line1);
		line2 = get_next_line(fd2);
		if (line2 == NULL)
			break;
		printf("%s", line2);
		free(line2);
		line3 = get_next_line(fd3);
		if (line3 == NULL)
			break;
		printf("%s", line3);
		free(line3);
		line4 = get_next_line(fd4);
		if (line4 == NULL)
			break;
		printf("%s", line4);
		free(line4);
		line5 = get_next_line(fd5);
		if (line5 == NULL)
			break;
		printf("%s", line5);
		free(line5);
		line6 = get_next_line(fd6);
		if (line6 == NULL)
			break;
		printf("%s", line6);
		free(line6);
		line7 = get_next_line(fd7);
		if (line7 == NULL)
			break;
		printf("%s", line7);
		free(line7);
		line8 = get_next_line(fd8);
		if (line8 == NULL)
			break;
		printf("%s", line8);
		free(line8);
		line9 = get_next_line(fd9);
		if (line9 == NULL)
			break;
		printf("%s", line9);
		free(line9);
	}
}

void test_bible()
{
	char *line;
	int fd = open("bible.txt", O_RDONLY | S_IRUSR);
	while (1)
	{
		line = get_next_line(fd);
		if (line <= 0)
			break;
		printf("%s", line);
		free(line);
	}
}

int main()
{
	//test_textfiles();
	test_bible();
	return (0);
}