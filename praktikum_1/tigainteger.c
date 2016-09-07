#include <stdio.h>

void CekInteger (int x);
int Max (int a, int b, int c);
int Min (int a, int b, int c);

int main () {
	int A, B, C;
	int nilaitengah;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	CekInteger(A);
	CekInteger(B);
	CekInteger(C);

	printf("%d\n", Max(A,B,C));
	printf("%d\n", Min(A,B,C));
	
	nilaitengah = A + B + C - Max(A,B,C) - Min(A,B,C);

	printf("%d\n", nilaitengah);

	return 0;
}

void CekInteger (int x) {
	if (x > 0) {
		printf("POSITIF-");
		if (x % 2)
			printf("GANJIL\n");
		else
			printf("GENAP\n");
	} else if (x == 0)
		printf("NOL\n");
	else
		printf("NEGATIF\n");
}

int Max (int a, int b, int c) {
	if (a >= b && a >= c)
		return a;
	if (b >= a && b >= c)
		return b;
	return c;
}

int Min (int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}
