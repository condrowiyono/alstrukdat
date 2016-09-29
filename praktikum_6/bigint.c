/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 29 September 2016
 * File : bigint.c
 */

#include "stdio.h"
#include "stdlib.h"
#include "stackt.h"

int main() {
	// digunakan untuk menerima input user
	char *s = (char*) malloc(102);
	
	// stack untuk menampung bigint pertama dan kedua
	Stack s1,s2;
	
	// inisialisasi stack
	CreateEmpty(&s1);
	CreateEmpty(&s2);
	
	// memasukkan bigint pertama ke stack
	scanf("%s", s);
	int i = 0;
	while (s[i] != '#')
		Push(&s1, s[i++]-'0');
	
	// memasukkan bigint kedua ke stack
	scanf("%s", s);
	i = 0;
	while (s[i] != '#')
		Push(&s2, s[i++]-'0');
		
	// inisialisasi stack hasil
	Stack hasil;
	CreateEmpty(&hasil);
		
	// menghitung nilai penjumlahan kedua bigint
	int simpan = 0;
	while (!IsEmpty(s1) || !IsEmpty(s2)) {
		int bil1,bil2;
		
		// mengambil nilai top dari bigint pertama, jika stack sudah habis,
		// isi dengan nol
		if (IsEmpty(s1))
			bil1 = 0;
		else
			Pop(&s1, &bil1);
			
		// mengambil nilai top dari bigint kedua, jika stack sudah habis,
		// isi dengan nil
		if (IsEmpty(s2))
			bil2 = 0;
		else
			Pop(&s2, &bil2);
			
		// mem-push hasil penjumlahan ke stack hasil
		Push(&hasil, (bil1 + bil2 + simpan) % 10);
		
		// mengupdate nilai penyimpanan sisa penjumlahan
		simpan = (bil1 + bil2 + simpan) / 10;
	}
	// jika masih ada yang disimpan, masukkan ke hasil
	if (simpan > 0)
		Push(&hasil, simpan);
		
	// mencetak hasil
	while (!IsEmpty(hasil)) {
		int x;
		Pop(&hasil, &x);
		printf("%d", x);
	}
	printf("\n");
	
	return 0;
}
