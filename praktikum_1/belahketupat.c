#include "stdio.h"

int main() {
	int n,i,j;
	
	scanf("%d", &n);
	
	if (n % 2 == 0 || n < 0) {
		printf("Masukan tidak valid\n");
		return 0;
	}
	
	for (i = 0; i < n/2; i++) {
		for (j = 0; j < n/2-i; j++)
			printf(" ");
		for (j = 0; j < 2*i+1; j++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("*");
	printf("\n");
	for (i = n/2-1; i >= 0; i--) {
		for (j = 0; j < n/2-i; j++)
			printf(" ");
		for (j = 0; j < 2*i+1; j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}
