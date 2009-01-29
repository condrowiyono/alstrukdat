/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 29 September 2016
 */

#include "stdio.h"
#include "boolean.h"
#include "mesinkata.h"

/*
 * IsKataSama
 * Mengecek apakah kata K1 sama dengan kata K2
 * Suatu kata dikatakan sama jika panjangnya sama dan K1_i = K2_i, untuk setiap 1 <= i <= |K2|
 * Kata K1 : kata pertama yang akan dibandingkan
 * Kata K2 : kata kedua yang akan dibandingkan
 * return : boolean yang menyatakan apakah K1 = K2
 */
boolean IsKataSama (Kata K1, Kata K2) {
	if (K1.Length == K2.Length) {
		boolean sama = true;
		int i = 1;
		while (sama && i <= K2.Length) {
			sama = K1.TabKata[i] == K2.TabKata[i];
			i++;
		}
		return sama;
	} else
		return false;
}

/*
 * CetakKata
 * Mencetak kata yang diberikan dalam parameter
 * Kata kata : kata yang akan dicetak
 */
void CetakKata(Kata kata) {
	int i = 1;
	while (i <= kata.Length)
		printf("%c", kata.TabKata[i++]);
}

int main() {
	// Mendefinisikan kata "TITIK"
	Kata TITIK;
	TITIK.Length = 5;
	TITIK.TabKata[1] = 'T';
	TITIK.TabKata[2] = 'I';
	TITIK.TabKata[3] = 'T';
	TITIK.TabKata[4] = 'I';
	TITIK.TabKata[5] = 'K';
	
	// Mendefinisikan kata "KOMA"
	Kata KOMA;
	KOMA.Length = 4;
	KOMA.TabKata[1] = 'K';
	KOMA.TabKata[2] = 'O';
	KOMA.TabKata[3] = 'M';
	KOMA.TabKata[4] = 'A';
	
	// inisialisasi variabel
	int standar = 0;
	int panjang = 0;
	int kata = 0;
	
	// digunakan untuk menandai apakah kata yang akan dicetak merupakan
	// kata pertama atau bukan, jika iya maka tidak perlu ditambah spasi
	// selebum melakukan pencetakan
	boolean awal = true;
	
	STARTKATA();
	while (!EndKata) {
		kata++;
			
		// mengecek apakah kata merupakan tanda baca atau tidak
		if (IsKataSama(CKata, TITIK))
			printf(".");
		else if (IsKataSama(CKata, KOMA))
			printf(",");
		else {
			// mencetak kata
			if (!awal)
				printf(" ");
			CetakKata(CKata);
			
			if (CKata.Length < 10)
				standar++;
			else
				panjang++;
		}
		
		awal = false;
		ADVKATA();
	}
	
	printf("\n%d\n%d\n", standar, panjang);
	
	// menampilkan biaya setelah didiskon
	if (kata > 10)
		printf("%d\n", (10 * standar + panjang * 15) * 90);
	else
		printf("%d\n", 1000 * standar + panjang * 1500);
	
	return 0;
}
