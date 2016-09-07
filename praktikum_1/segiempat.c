#include "stdio.h"

int main() {
	int n,i,j;
	char a,b;
	
	scanf("%d\n%c\n%c", &n, &a, &b);
	
	if (n <= 0 || a == b) {
		printf("Masukan tidak valid\n");
		return 0;
	}
	
	for (i = 0; i < n; i++)
		printf("%c", a);
	printf("\n");
	for (i = 0; i < n-2; i++) {
		printf("%c", a);
		for (j = 0; j < n-2; j++)
			printf("%c", b);
		printf("%c\n", a);
	}
	if (n > 1) {
		for (i = 0; i < n; i++)
			printf("%c", a);
		printf("\n");
	}
	
	return 0;
}
