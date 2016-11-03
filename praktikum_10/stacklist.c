/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : stacklist.c
 * Tanggal : 1 November 2016
 */

#include "stacklist.h"
#include "boolean.h"
#include <stdlib.h>

/* 
 * Alokasi
 * I.S. Sembarang
 * F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil
 *      P=Nil jika alokasi gagal
 */
void Alokasi (address *P, infotype X) {
	address q = (address) malloc(sizeof(infotype));
	Info(q) = X;
	Next(q) = Nil;
	*P = q;
}

/* 
 * Dealokasi
 * I.S. P adalah hasil alokasi, P != Nil
 * F.S. Alamat P didealokasi, dikembalikan ke sistem
 */ 
void Dealokasi (address P) {
	free(P);
}

/* 
 * IsEmpty
 * Mengirim true jika Stack kosong: TOP(S) = Nil
 */
boolean IsEmpty (Stack S) {
	return Top(S) == Nil;
}

/* 
 * CreateEmpty
 * I.S. sembarang 
 * F.S. Membuat sebuah stack S yang kosong
 */
void CreateEmpty (Stack * S) {
	Top(*S) = Nil;
}

/* 
 * Push
 * Menambahkan X sebagai elemen Stack S
 * I.S. S mungkin kosong, X terdefinisi
 * F.S. X menjadi Top yang baru jika alokasi X berhasil,
 *      jika tidak, S tetap
 * Pada dasarnya adalah operasi Insert First pada list linier
 */
void Push (Stack * S, infotype X) {
	if (IsEmpty(*S))
		Alokasi(&Top(*S), X);
	else {
		address ntop;
		Alokasi(&ntop, X);
		if (ntop != Nil) {
			Next(ntop) = Top(*S);
			Top(*S) = ntop;
		}
	}
}

/* 
 * Pop
 * Menghapus X dari Stack S.
 * I.S. S tidak mungkin kosong
 * F.S. X adalah nilai elemen TOP yang lama,
 *      elemen TOP yang lama didealokasi
 * Pada dasarnya adalah operasi Delete First pada list linier
 */
void Pop (Stack * S, infotype * X) {
	*X = Info(Top(*S));
	address tmp = Top(*S);
	Top(*S) = Next(Top(*S));
	free(tmp);
}
