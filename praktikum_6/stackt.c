/*
 * Auhtor
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Selasa, 27 September 2016
 * File : stackt.c
 */

#include "boolean.h"
#include "stackt.h"
#include "stdlib.h"

/*
 * CreateEmpty
 * I.S. sembarang
 * F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
 * jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai
 * Ciri stack kosong : TOP bernilai Nil
 */
void CreateEmpty (Stack *S) {
	S = (Stack*) malloc(sizeof(Stack));
	Top(*S) = 0;
	InfoTop(*S) = Nil;
}

/*
 * IsEmpty
 * Mengirim true jika Stack kosong: lihat definisi di atas
 */
boolean IsEmpty (Stack S) {
	return InfoTop(S) == Nil;
}

/*
 * IsFull
 * Mengirim true jika tabel penampung nilai elemen stack penuh
 */
boolean IsFull (Stack S) {
	return Top(S) >= MaxEl;
}

/*
 * Push
 * Menambahkan X sebagai elemen Stack S.
 * I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. X menjadi TOP yang baru,TOP bertambah 1
 */
void Push (Stack * S, infotype X) {
	Top(*S)++;
	InfoTop(*S) = X;
}

/*
 * Pop
 * Menghapus X dari Stack S.
 * I.S. S  tidak mungkin kosong
 * F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1
 */
void Pop (Stack * S, infotype* X) {
	*X = InfoTop(*S);
	Top(*S)--;
}
