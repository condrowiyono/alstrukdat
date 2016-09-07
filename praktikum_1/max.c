#include "stdio.h"

#define max(a,b) a > b ? a : b

int main() {
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", max(max(a,b),c));
	return 0;
}
