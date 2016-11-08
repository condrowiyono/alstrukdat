/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : listrek.c
 * Tanggal : 8 November 2016
 */

#include "listrek.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* 
 * Alokasi
 * Mengirimkan address hasil alokasi sebuah elemen
 * Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
   maka Info(P) = X, Next(P) = Nil
 * Jika alokasi gagal, mengirimkan Nil
 */
address Alokasi (infotype X) {
	address P = (address) malloc(sizeof(infotype));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}	

/* 
 * Dealokasi
 * I.S. P terdefinisi
 * F.S. P dikembalikan ke sistem
 * Melakukan dealokasi/pengembalian address P
 */
void Dealokasi (address P) {
	free(P);
}

/* 
 * IsEmpty
 * Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong
 */
int IsEmpty(List L) {
	return L == Nil;
}

/* 
 * IsOneElmt
 * Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong
 */
int IsOneElmt(List L) {
	if (!IsEmpty(L))
		return Next(L) == Nil;
	else
		return 0;
}

/* 
 * FirstElmt
 * Mengirimkan elemen pertama sebuah list L yang tidak kosong
 */
infotype FirstElmt (List L) {
	return Info(L);
}

/* 
 * Tail
 * Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong
 */
List Tail(List L) {
	return Next(L);
}

/* 
 * Konso
 * Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
 * e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L.
 */
List Konso(infotype e, List L) {
	address P = Alokasi(e);
	if (P == Nil)
		return L;
	else {
		Next(P) = L;
		return P;
	}
}

/* 
 * KonsB
 * Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
 * e harus dialokasi terlebih dahulu
 * Jika alokasi e gagal, mengirimkan L
 */ 
List KonsB(List L, infotype e) {
	address P = Alokasi(e);
	if (P != Nil) {
		if (IsEmpty(L))
			return P;
		else {
			address i = L;
			address last = Nil;
			while (i != Nil) {
				last = i;
				i = Next(i);
			}
			Next(last) = P;
		}
	}
	return L;
}

/* 
 * Copy
 * Mengirimkan salinan list L (menjadi list baru)
 * Jika ada alokasi gagal, mengirimkan L
 */ 
List Copy (List L) {
	if (IsEmpty(L))
		return Nil;
	else
		return Konso(Info(L), Tail(L));
}

/* 
 * MCopy
 * I.S. Lin terdefinisi
 * F.S. Lout berisi salinan dari Lin
 * Proses : menyalin Lin ke Lout
 */
void MCopy (List Lin, List *Lout) {
	List cp = Copy(Lin);
	*Lout = cp;
}

/* 
 * Concat
 * Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
 * Jika ada alokasi gagal, menghasilkan Nil
 */
List Concat (List L1, List L2) {
	if (IsEmpty(L2))
		return L1;
	else if (IsEmpty(L1))
		return L2;
	else
		return Concat(KonsB(L1, Info(L2)), Tail(L2));
}

/* 
 * MConcat
 * I.S. L1, L2 terdefinisi
 * F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin"
 * Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2
 */
void MConcat (List L1, List L2, List *LHsl) {
	*LHsl = Concat(L1,L2);
}

/* 
 * PrintList
 * I.S. L terdefinisi.
 * F.S. Setiap elemen list dicetak.
 */
void PrintList (List L) {
	if (!IsEmpty(L)) {
		printf("%d\n", FirstElmt(L));
		PrintList(Tail(L));
	}
}

/* 
 * NbElmtList
 * Mengirimkan banyaknya elemen list L, Nol jika L kosong
 */
int NbElmtList (List L) {
	if (IsEmpty(L))
		return 0;
	else
		return 1 + NbElmtList(Tail(L));
}

/* 
 * Search
 * Mengirim true jika X adalah anggota list, false jika tidak
 */
boolean Search (List L, infotype X) {
	if (IsEmpty(L))
		return false;
	else if (Info(L) == X)
		return true;
	else
		return Search(Tail(L), X);
}
