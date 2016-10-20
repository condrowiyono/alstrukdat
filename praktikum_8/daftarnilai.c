/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 20 Oktober 2016
 */
 
#include "boolean.h"
#include "listlinier.h"
#include "stdio.h"
 
int main() {
	List lNilai;
	CreateEmpty(&lNilai);
	
	int x;
	do {
		scanf("%d", &x);
		if (x >= 0 && x <= 100)
			InsVFirst(&lNilai, x);
	} while (x >= 0 && x <= 100);
	
	if (IsEmpty(lNilai))
		printf("Daftar nilai kosong\n");
	else {
		printf("%d\n", NbElmt(lNilai));
		printf("%d\n", Max(lNilai));
		printf("%d\n", Min(lNilai));
		printf("%.2f\n", Average(lNilai));
		
		List lNilaiBalik = FInversList(lNilai);
		
		PrintInfo(lNilaiBalik); printf("\n");
		PrintInfo(lNilai); printf("\n");
	}
} 
