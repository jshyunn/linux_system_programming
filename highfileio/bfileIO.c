#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char* fileName = "binary.bin";
	int data[5] = { 10, 20, 30, 40, 50 };
	FILE* fp = NULL;
	
	if (!(fp = fopen(fileName, "wb"))) {
		fprintf(stderr, "Fail to open the file - %s\n", fileName);
		exit(1);
	}

	int i = fwrite(data, sizeof(int), 5, fp);
	printf("Success to write %d objects(s).\n", i);

	fclose(fp);
	return 0;
}
