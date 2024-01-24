#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct stat buf;

	stat("linux.txt", &buf);
	printf("Before Link Count = %d\n", (int)buf.st_nlink);

	link("linux.txt", "linux.ln");

	stat("linux.txt", &buf);
	printf("After Hard Link Count = %d\n", (int)buf.st_nlink);

	symlink("linux.txt", "linux.sym");

	stat("linux.txt", &buf);
	printf("After Soft Link Count = %d\n", (int)buf.st_nlink);

	int cnt;

	cnt = unlink("linux.sym");
	if (cnt == -1)
	{
		perror("Unlink linux.sym");
		exit(1);
	}

	printf("Unlink linux.sym success!!\n");

	return 0;
}
