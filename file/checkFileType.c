#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf;
	int kind;

	stat("checkFileType.c", &buf);

	printf("Mode = %o (Hexa = %x)\n",
			(unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	kind = buf.st_mode & S_IFMT;
	printf("Kind = %x\n", kind);

	// 정의된 매크로 사용	
	if (S_ISREG(buf.st_mode)) printf("checkFileType.c : Regular File\n");

	return 0;
}
