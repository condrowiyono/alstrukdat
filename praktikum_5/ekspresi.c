/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 29 September 2016
 */

#include "stdio.h"
#include "mesintoken.h"

int main() {
	// Start baca token
	STARTTOKEN();
	
	// Jika file kosong
	if (EndToken)
		printf("Ekspresi kosong\n");
	else
		// Membaca token demi token
		while (!EndToken) {
			if (CToken.tkn != 'b')
				printf("%c\n", CToken.tkn);
			else
				printf("%d\n", CToken.val);
			ADVTOKEN();
		}
	
	return 0;
}
