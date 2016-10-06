/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Selasa, 5 Oktober 2015
 * Nama file : queue.c
 */

#include "queue.h"
#include "boolean.h"
#include "stdio.h"
#include "stdlib.h"

/*
 * AvgElmt
 * Menghitung rata-rata nilai dari elemen yang ada dalam suatu queue
 * Q : queue yang ingin dihitung rata-ratanya, Q tidak kosong
 * return : float yang menyatakan rata-rata elemen dalam Q
 */
float AvgElmt (Queue Q) {
	int n = 0;
	int s = 0;
	int x = 0;
	while (!IsEmpty(Q)) {
		Del(&Q, &x);
		s += x;
		n++;
	}
	return (float)s /(float)n;
}

int main() {
	// membaca nilai maximum queue
	int n;
	scanf("%d", &n);
	
	// membuat queue
	Queue antrian;
	CreateEmpty(&antrian, n);
	
	// variabel a dan b digunakan untuk menampung perintah
	int a,b;
	scanf("%d", &a);
	while (a != 0) {
		if (a == 1)
			scanf("%d", &b);
			
		// mengirim pesan jika queue penuh atau kosong
		if (a == 1 && IsFull(antrian))
			printf("Queue penuh\n");
		else if (a == 2 && IsEmpty(antrian))
			printf("Queue kosong\n");
		
		// mempush dan pop queue
		else if (a == 1)
			Add(&antrian, b);
		else
			Del(&antrian, &b);
			
		// perintah selanjutnya
		scanf("%d", &a);
	}
	
	// menampilkan hasil perhitungan rata-rata elemen dalam queue
	if (IsEmpty(antrian))
		printf("0\nTidak bisa dihitung\n");
	else
		printf("%d\n%.2f\n", NBElmt(antrian), AvgElmt(antrian));
	
	return 0;
} 
