#include "stdio.h"
#include "jam.h"

int main() {
	int n,i;
	JAM awal,akhir,p,q;
	
	awal = MakeJAM(23,59,59);
	akhir = MakeJAM(0,0,0);
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("[%d]\n", i);
		BacaJAM(&p);
		BacaJAM(&q);
		
		if (JLT(p,q))
			printf("%ld\n", Durasi(p, q));
		else
			printf("%ld\n", Durasi(q, p));
			
		if (JLT(p,awal))
			awal = p;
		if (JLT(q,awal))
			awal = q;
		if (JGT(p,akhir))
			akhir = p;
		if (JGT(q,akhir))
			akhir = q;		
	}
	
	TulisJAM(awal);
	printf("\n");
	TulisJAM(akhir);
	printf("\n");
	
	return 0;
}
