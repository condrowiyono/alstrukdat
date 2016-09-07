#include "stdio.h"

int main() {
	int i,n,s;
	scanf("%d", &n);

	s = 0;
	for (i = 1; i <= n; i++)
		s += i;

	printf("%d\n", s);

	return 0;
}
