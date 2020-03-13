#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000
#define MAX 10000

int count_words(char buffer[]);

int words[MAX];
int n = 0;

int main() {
	char buffer[BUFFER_SIZE];
	FILE *fp = fopen("harry.txt", "r");
	FILE* fp2 = fopen("output.txt", "w");
	int i = 0;
	while (!feof(fp)) {
		fgets(buffer, BUFFER_SIZE, fp);
		i++;
		int len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		int nwords = count_words(buffer);
		printf("%s:%d:%d\n", buffer, nwords, strlen(buffer));
		fprintf(fp2, "%s:%d:%d\n", buffer, nwords, strlen(buffer));
	}
	fclose(fp);
	fclose(fp2);

	return 0;
}

int count_words(char buffer[]) {
	int count = 0;
	for (int i = 0; i < strlen(buffer); i++) {
		if (!isspace(buffer[1]) && (i==0 || isspace(buffer[i - 1])))
			count++;
	}
	return count;
}