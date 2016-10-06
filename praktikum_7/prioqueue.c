/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Selasa, 5 Oktober 2015
 * Nama file : queue.c
 */

#include "stdlib.h"
#include "stdio.h"
#include "boolean.h"
#include "prioqueue.h"

/*
 * IsEmpty
 * Mengirim true jika Q kosong: lihat definisi di atas
 */
boolean IsEmpty (Queue Q) {
	return Head(Q) == Nil && Tail(Q) == Nil;
}

/*
 * IsFull
 * Mengirim true jika tabel penampung elemen Q sudah penuh
 * yaitu mengandung elemen sebanyak MaxEl
 */
boolean IsFull (Queue Q) {
	return NBElmt(Q) == MaxEl(Q);
}

/*
 * NBElmt
 * Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong
 */
int NBElmt (Queue Q) {
	if (IsEmpty(Q))
		return 0;
	else
		return (Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q) + 1;
}

/*
 * CreateEmpty
 * I.S. sembarang
 * F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb:
		Jika alokasi berhasil, Tabel memori dialokasi berukuran Max
		atau : jika alokasi gagal, Q kosong dg MaxEl=0
 * Proses : Melakukan alokasi,Membuat sebuah Q kosong
 */
void CreateEmpty (Queue * Q, int Max) {
	DeAlokasi(Q);
	(*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
	MaxEl(*Q) = Max;
}

/*
 * DeAlokasi
 * Proses: Mengembalikan memori Q
 * I.S. Q pernah dialokasi
 * F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0
 */
void DeAlokasi(Queue * Q) {
	if (Q == Nil)
		Q = (Queue *) malloc(sizeof(Queue));
	if ((*Q).T != Nil)
		free((*Q).T);
	MaxEl(*Q) = 0;
	Head(*Q) = 0;
	Tail(*Q) = 0;
}

/*
 * Add
 * Proses: Menambahkan X pada Q dengan aturan FIFO
 * I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
 * F.S. X menjadi TAIL yang baru, TAIL "maju"
 * Jika Tail(Q)=MaxEl+1 maka geser isi tabel, shg Head(Q)=1
 */
void Add (Queue * Q, infotype X) {
	if (IsEmpty(*Q))
		Head(*Q) = 1;
	Tail(*Q) = Tail(*Q) % MaxEl(*Q) + 1;
	InfoTail(*Q) = X;
	
	int i = Tail(*Q);
	boolean insert = true;
	while (i != Head(*Q) && insert) {
		int previ = i - 1 == 0 ? MaxEl(*Q) : i - 1;
		
		if (Prio(Elmt(*Q,i)) > Prio(Elmt(*Q,previ))) {
			infotype tmp = Elmt(*Q,i);
			Elmt(*Q,i) = Elmt(*Q,previ);
			Elmt(*Q,previ) = tmp;
		} else
			insert = false;
		
		i = previ;
	}
}

/*
 * Del
 * Proses: Menghapus X pada Q dengan aturan FIFO
 * I.S. Q tidak mungkin kosong
 * F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju";Q mungkin kosong
 */
void Del(Queue * Q, infotype * X) {
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1)
		Head(*Q) = Tail(*Q) = Nil;
	else
		Head(*Q) = Head(*Q) % MaxEl(*Q) + 1;
}

/* 
 * PrintQueue
 * Mencetak isi queue Q ke layar
 * I.S. Q terdefinisi, mungkin kosong
 * F.S. Q tercetak ke layar dengan format:
   <prio-1> <elemen-1>
   ...
   <prio-n> <elemen-n>
 */
void PrintQueue (Queue Q) {
	infotype last;
	while (!IsEmpty(Q)) {
		Del(&Q, &last);
		printf("%d %d\n", Prio(last), Info(last)); 
	}
	printf("#\n");
}
