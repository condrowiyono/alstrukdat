/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : mprioqueue.c
 * Tanggal : 3 November 2016
 */
 
#include "boolean.h"
#include "prioqueue.h"
#include <stdio.h>

int main() {
	// Kamus
	PrioQueue queue;
	infotype X,C;
	int n,curTime,dilayani;
	
	// Inisialisasi priority queue dan current time
	CreateEmpty(&queue);
	curTime = 0;
	
	// Mensimulasikan antrian
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &X.tKedatangan, &X.id, &X.nMat, &X.dLayanan);
			
		// Melayani antrian jika current time masih kurang dari kedatangan X
		while (!IsEmpty(queue) && curTime < X.tKedatangan) {
			Del(&queue, &C);
			printf("%d %d %d\n", curTime, C.id, curTime - C.tKedatangan);
			curTime += C.dLayanan;
			dilayani++;
		}
		
		// Memasukkan X kedalam antrian
		Add(&queue, X);
		if (curTime < X.tKedatangan)
			curTime = X.tKedatangan;
	}
	
	// Melayani pelanggan yang masih ada di antrian
	while (!IsEmpty(queue)) {
		Del(&queue, &C);
		printf("%d %d %d\n", curTime, C.id, curTime - C.tKedatangan);
		curTime += C.dLayanan;
		dilayani++;
	}
	
	// Kasus ketika tidak ada pelanggan yang dilayani
	if (dilayani == 0)
		printf("Tidak ada layanan\n");
	
	return 0;
} 
