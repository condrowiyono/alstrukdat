/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 29 September 2016
 * File : bigint.c
 */

#include "mesintoken.h"
#include "stackt.h"
#include "stdio.h"

/*
 * pangkat
 * digunakan untuk menghitung nilai a^b
 * a : basis yang akan dipangkatkan
 * b : nilai pangkat
 * return : int yang menyatakan a^b
 */
int pangkat(int a, int b) {
	if (b == 0)
		return 1;
	int c = a*a;
	if (b % 2 == 0)
		return c*c;
	else
		return c*c*a;
}

int main() {
	// inisialisasi stack yang menampung bilangan
	Stack st;
	CreateEmpty(&st);
	
	STARTTOKEN();
	while (!EndToken) {
		if (CToken.tkn == 'b') {
			// jika token merupakan bilangan, push kedalam stack
			Push(&st, CToken.val);
			printf("%d\n", CToken.val);
		} else {
			int bil1,bil2,hasil;
			
			// mengambil dua bilangan paling atas dari stack
			Pop(&st, &bil1);
			Pop(&st, &bil2);
			
			printf("%d %c %d\n", bil2, CToken.tkn, bil1);
			
			// menghitung nilai dari ekspresi yang bersangkutan
			switch(CToken.tkn) {
				case '+':
					hasil = bil2 + bil1;
					break;
				case '-':
					hasil = bil2 - bil1;
					break;
				case '*':
					hasil = bil2 * bil1;
					break;
				case '/':
					hasil = bil2 / bil1;
					break;
				case '^':
					hasil = pangkat(bil2 , bil1);
					break;
			}
			
			// mem-push hasil ekspresi kedalam stack
			Push(&st, hasil);
			printf("%d\n", hasil);
		}
		ADVTOKEN();
	}
	
	// mencetak hasil ekspresi
	if (IsEmpty(st))
		printf("Ekspresi kosong\n");
	else {
		int hasil;
		Pop(&st, &hasil);
		printf("Hasil=%d\n", hasil);
	}
	
	return 0;
} 
