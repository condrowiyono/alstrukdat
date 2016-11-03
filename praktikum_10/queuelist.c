/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : queuelist.c
 * Tanggal : 1 November 2016
 */

#include "queuelist.h"
#include "stdlib.h"
#include "boolean.h"

/* 
 * Alokasi
 * I.S. Sembarang
 * F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil
 *      P=Nil jika alokasi gagal
 */
void Alokasi (address *P, infotype X) {
	*P = (address) malloc(sizeof(infotype));
	Info(*P) = X;
	Next(*P) = Nil;
}

/* 
 * Dealokasi
 * I.S. P adalah hasil alokasi, P != Nil
 * F.S. Alamat P didealokasi, dikembalikan ke sistem
 */
void Dealokasi (address  P) {
	free(P);
}

/* 
 * IsEmpty
 * Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil
 */
boolean IsEmpty (Queue Q) {
	return Head(Q) == Nil && Tail(Q) == Nil;
}

/* 
 * NbElmt
 * Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong
 */
int NbElmt(Queue Q) {
	address i = Head(Q);
	int n = 0;
	while (i != Nil) {
		n++;
		i = Next(i);
	}
	return n;
}

/* 
 * CreateEmpty
 * I.S. sembarang
 * F.S. Sebuah Q kosong terbentuk
 */
void CreateEmpty(Queue * Q) {
	Head(*Q) = Tail(*Q) = Nil;
}

/* 
 * Add
 * Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap
 * Pada dasarnya adalah proses insert last
 * I.S. Q mungkin kosong
 * F.S. X menjadi TAIL, TAIL "maju"
 */
void Add (Queue * Q, infotype X) {
	address p;
	Alokasi(&p, X);
	
	if (IsEmpty(*Q))
		Head(*Q) = Tail(*Q) = p;
	else {
		Next(Tail(*Q)) = p;
		Tail(*Q) = p;
	}
}

/* 
 * Del
 * Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD
 * Pada dasarnya operasi delete first
 * I.S. Q tidak mungkin kosong
 * F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur"
 */
void Del(Queue * Q, infotype * X) {
	*X = InfoHead(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil)
		Tail(*Q) = Nil;
}
