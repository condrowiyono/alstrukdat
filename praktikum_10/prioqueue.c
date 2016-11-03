/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : prioqueue.c
 * Tanggal : 3 November 2016
 */

#include "boolean.h"
#include "prioqueue.h"

/* 
 * Alokasi
 * I.S. Sembarang
 * F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil
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
 * Mengirim true jika Q kosong: HEAD(Q)=Nil
 */
boolean IsEmpty (PrioQueue Q) {
	return Head(Q) == Nil;
}

/* 
 * NbElmt
 * Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong
 */
int NbElmt(PrioQueue Q) {
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
void CreateEmpty(PrioQueue * Q) {
	Head(*Q) = Nil;
}

/* 
 * Add
 * Proses: Mengalokasi X dan menambahkan X sesuai aturan priority queue
   jika alokasi berhasil; jika alokasi gagal Q tetap
 * I.S. Q mungkin kosong
 */
void Add (PrioQueue * Q, infotype X) {
	address p;
	Alokasi(&p, X);
	
	if (IsEmpty(*Q))
		Head(*Q) = p;
	else {
		address prev = Nil;
		address i = Head(*Q);
		
		boolean inserted = false;
		while (!inserted && i != Nil) {
			if (Info(i).nMat < X.nMat) {
				if (prev == Nil) {
					Head(*Q) = p;
					Next(p) = i;
				} else {
					Next(prev) = p;
					Next(p) = i;
				}
				inserted = true;
			}
			prev = i;
			i = Next(i);
		}
		
		if (!inserted)
			Next(prev) = p;
	}
}

/* 
 * Del
 * Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD
 * Pada dasarnya operasi delete first
 * I.S. Q tidak mungkin kosong
 * F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur"
 */
void Del(PrioQueue * Q, infotype * X) {
	*X = Info(Head(*Q));
	Head(*Q) = Next(Head(*Q));
}
