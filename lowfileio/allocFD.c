#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int openFile(void) {
	int fd = open("hello.txt", O_RDWR);
	if (fd == -1) {
		perror("File Open");
		exit(1);
	}
	return fd;
}

int main(void) {
	int fd = 0;

	fd = openFile(); printf("fd = %d\n", fd); // fd = 3 
	close(fd);
	
	close(0); // stdin의 fd가 삭제되어 다음 fd는 0이 됨

	fd = openFile(); printf("fd = %d\n", fd); // fd = 0
	close(fd);

	return 0;
}
