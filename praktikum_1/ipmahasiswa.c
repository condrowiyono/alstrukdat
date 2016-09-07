#include "stdio.h"

#define boolean unsigned char
#define true 1
#define false 0

boolean isWithinRange(float x, float start, float end) {
	return (x >= start) && (x <= end);
}

int main() {
	int n,lulus;
	float s,p;
	
	p = -1;
	lulus = 0;
	n = 0;
	s = 0;
	do {
		scanf("%f", &p);
		if (isWithinRange(p, 0.0, 4.0)) {
			n++;
			s += p;
			if (isWithinRange(p, 2.75, 4.0))
				lulus++;
		}
	} while (p != -999);
	
	if (n > 0)
		printf("%d\n%d\n%d\n%.2f\n", n, lulus, n - lulus, s / n);
	else
		printf("Tidak ada data\n");
	
	return 0;
}
