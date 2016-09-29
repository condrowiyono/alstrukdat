/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 29 September 2016
 */

#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"

/* State Mesin Token */
boolean EndToken;
Token CToken;

/*
 * IgnoreBlank
 * Mengabaikan satu atau beberapa BLANK
 * I.S. : CC sembarang 
 * F.S. : CC ≠ BLANK atau CC = MARK
 */
void IgnoreBlank() {
	while (CC == BLANK)
		ADV();
}

/*
 * STARTTOKEN
 * I.S. : CC sembarang 
 * F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token
 */

void STARTTOKEN() {
	START();
	EndToken = false;
	IgnoreBlank();
	ADVTOKEN();
}

/*
 * ADVTOKEN
 * I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
 * F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
 * Proses : Akuisisi kata menggunakan procedure SalinKata
 */
void ADVTOKEN() {
	if (CC == MARK)
		EndToken = true;
	else {
		SalinToken();
		IgnoreBlank();
	}
}

/* 
 * SalinToken
 * Mengakuisisi Token dan menyimpan hasilnya dalam CToken
 * I.S. : CC adalah karakter pertama dari Token
 * F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong"
 */
void SalinToken() {
	CToken.tkn = CC;
	if (CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^') {
		CToken.val = -1;
		ADV();
	} else {
		CToken.tkn = 'b';
		CToken.val = 0;
		while (CC != MARK && CC != BLANK) {
			CToken.val *= 10;
			CToken.val += (int) (CC - '0');
			ADV();
		}
	}
}
