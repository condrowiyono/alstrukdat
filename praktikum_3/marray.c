/*
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 8 September 2016
 * File : marray.c
 */

#include "stdio.h"
#include "boolean.h"
#include "array.h"

int main() {
	// Kamus
	TabInt t;
	int x,i,count;
	
	// Membaca isi tabel
	BacaIsi(&t);
	
	// Menulis isi tabel
	TulisIsiTab(t);
	printf("\n");
	
	// Membaca nilai x
	scanf("%d", &x);
	
	// Menghitung kemunculan x
	count = 0;
	if (!IsEmpty(t))
		for (i = GetFirstIdx(t); i <= GetLastIdx(t); i++)
			if (Elmt(t,i) == x)
				count++;
	printf("%d\n", count);
	
	// Mencari index x
	i = Search1(t, x);
	if (i == IdxUndef)
		printf("%d tidak ada\n", x);
	else
		printf("%d\n", i);
		
	// Menampilkan status x apakah max, min atau median
	if (i != IdxUndef) {
		InsSortAsc(&t);
		
		if (MaxUrut(t) == x)
			printf("maksimum\n");
		if (MinUrut(t) == x)
			printf("minimum\n");
		
		int n = NbElmt(t);
		if ((n % 2 == 0 && Elmt(t,n/2) == x) || (n % 2 == 1 && Elmt(t,n/2+1) == x))
			printf("median\n");
	}
	
	return 0;
}
