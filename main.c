#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

// void test_textfiles()
// {
// 	char *line1;
// 	char *line2;
// 	char *line3;
// 	char *line4;
// 	char *line5;
// 	char *line6;
// 	char *line7;
// 	char *line8;
// 	char *line9;
// 	int i;

// 	int fd1 = open("test1.txt", O_RDONLY | S_IRUSR);
// 	int fd2 = open("test2.txt", O_RDONLY | S_IRUSR);
// 	int fd3 = open("test3.txt", O_RDONLY | S_IRUSR);
// 	int fd4 = open("test4.txt", O_RDONLY | S_IRUSR);
// 	int fd5 = open("test5.txt", O_RDONLY | S_IRUSR);
// 	int fd6 = open("test6.txt", O_RDONLY | S_IRUSR);
// 	int fd7 = open("test7.txt", O_RDONLY | S_IRUSR);
// 	int fd8 = open("test8.txt", O_RDONLY | S_IRUSR);
// 	int fd9 = open("test9.txt", O_RDONLY | S_IRUSR);

// 	i = 0;
// 	//printf("BUF_SIZE = %zu\n\n", BUF_SIZE);
// 	while (i < 6)
// 	{
// 		line1 = get_next_line(fd1);
// 		if (line1 == NULL)
// 			break;
// 		printf("%s", line1);
// 		free(line1);
// 		line2 = get_next_line(fd2);
// 		if (line2 == NULL)
// 			break;
// 		printf("%s", line2);
// 		free(line2);
// 		line3 = get_next_line(fd3);
// 		if (line3 == NULL)
// 			break;
// 		printf("%s", line3);
// 		free(line3);
// 		line4 = get_next_line(fd4);
// 		if (line4 == NULL)
// 			break;
// 		printf("%s", line4);
// 		free(line4);
// 		line5 = get_next_line(fd5);
// 		if (line5 == NULL)
// 			break;
// 		printf("%s", line5);
// 		free(line5);
// 		line6 = get_next_line(fd6);
// 		if (line6 == NULL)
// 			break;
// 		printf("%s", line6);
// 		free(line6);
// 		line7 = get_next_line(fd7);
// 		if (line7 == NULL)
// 			break;
// 		printf("%s", line7);
// 		free(line7);
// 		line8 = get_next_line(fd8);
// 		if (line8 == NULL)
// 			break;
// 		printf("%s", line8);
// 		free(line8);
// 		line9 = get_next_line(fd9);
// 		if (line9 == NULL)
// 			break;
// 		printf("%s", line9);
// 		free(line9);
// 	}
// }

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