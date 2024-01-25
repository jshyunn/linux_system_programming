#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	printf("--> Before exec function\n");

	if (execlp("ls", "ls", "-a", (char*) NULL) == -1) {
		perror("execlp");
		exit(1);
	}

	printf("--> After exec function\n"); // execlp가 실행되는 순간 process가 덮여쓰여져 이 구문은 실행되지 않음
	
	return 0;
}
