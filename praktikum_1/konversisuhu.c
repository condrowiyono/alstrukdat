#include "stdio.h"

int main() {
	float suhu;
	char c;

	scanf("%f\n%c", &suhu, &c);
	
	switch(c) {
		case 'R': printf("%.2f\n", 4.0/5.0*suhu); break;
		case 'F': printf("%.2f\n", 9.0/5.0*suhu + 32.0); break;
		case 'K': printf("%.2f\n", 273.15 + suhu); break;
	}

	return 0;
}
