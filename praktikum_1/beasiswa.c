#include "stdio.h"

int main() {
	float ip,pot;
	
	scanf("%f%f", &ip, &pot);
	if (ip >= 3.5)
		printf("4\n");
	else if (ip < 3.5 && pot < 1.0)
		printf("1\n");
	else if (pot >= 1 && pot < 5.0 && ip >= 2.0)
		printf("3\n");
	else if (pot >= 1 && pot < 5.0 && ip < 2.0)
		printf("2\n");
	else
		printf("0\n");
	
	return 0;
}
