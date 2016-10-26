#include "boolean.h"
#include "listdp.h"
#include "stdlib.h"
#include "stdio.h"

boolean IsEmpty (List L) {
	return First(L) == Nil && Last(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
	address hasil = (address) malloc(sizeof(ElmtList));
	if (hasil != Nil) {
		Info(hasil) = X;
		Next(hasil) = Nil;
		Prev(hasil) = Nil;
	}
	return hasil;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
	address i = First(L);
	address found = Nil;
	while (found == Nil && i != Nil) {
		if (Info(i) == X)
			found = i;
		i = Next(i);
	}
	return found;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
	address p = Alokasi(X);
	if (p != Nil) {
		Next(p) = First(*L);
		if (First(*L) != Nil)
			Prev(First(*L)) = p;
		First(*L) = p;
		if (Last(*L) == Nil)
			Last(*L) = p;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X) {
	address p = Alokasi(X);
	if (p != Nil) {
		Prev(p) = Last(*L);
		if (Last(*L) != Nil)
			Next(Last(*L)) = p;
		Last(*L) = p;
		if (First(*L) == Nil)
			First(*L) = p;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
	*X = Info(First(*L));
	address tmp = First(*L);
	First(*L) = Next(tmp);
	if (First(*L) != Nil)
		Prev(First(*L)) = Nil;
	else
		Last(*L) = Nil;
	Dealokasi(tmp);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X) {
	*X = Info(Last(*L));
	address tmp = Last(*L);
	Last(*L) = Prev(tmp);
	if (Last(*L) != Nil)
		Next(Last(*L)) = Nil;
	else
		First(*L) = Nil;
	Dealokasi(tmp);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
	Next(P) = First(*L);
	if (First(*L) != Nil)
		Prev(First(*L)) = P;
	else {
		Last(*L) = P;
		Next(Last(*L)) = Nil;
	}
	First(*L) = P;
	Prev(First(*L)) = Nil;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P) {
	Prev(P) = Last(*L);
	if (Last(*L) != Nil)
		Next(Last(*L)) = P;
	else {
		First(*L) = P;
		Prev(First(*L)) = Nil;
	}
	Last(*L) = P;
	Next(Last(*L)) = Nil;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec) {
	Prev(P) = Prec;
	Next(P) = Next(Prec);
	Next(Prec) = P;
	if (Next(P) != Nil)
		Prev(Next(P)) = P;
	else {
		Last(*L) = P;
		Next(Last(*L)) = Nil;
	}
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ) {
	Next(P) = Succ;
	Prev(P) = Prev(Succ);
	Prev(Succ) = P;
	if (Prev(P) != Nil)
		Next(Prev(P)) = P;
	else {
		First(*L) = P;
		Prev(First(*L)) = Nil;
	}
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) == Nil)
		Last(*L) = Nil;
	else
		Prev(First(*L)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P) {
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) == Nil)
		First(*L) = Nil;
	else
		Next(Last(*L)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X) {
	address i = First(*L);
	while (i != Nil) {
		address tmp = Next(i);
		if (Info(i) == X) {
			if (Prev(i) != Nil)
				Next(Prev(i)) = Next(i);
			else {
				First(*L) = Next(i);
				if (First(*L) != Nil)
					Prev(First(*L)) = Nil;
			}
			if (Next(i) != Nil)
				Prev(Next(i)) = Prev(i);
			else {
				Last(*L) = Prev(i);
				if (Last(*L) != Nil)
					Next(Last(*L)) = Nil;
			}
			Dealokasi(i);
		}
		i = tmp;
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec) {
	*Pdel = Next(Prec);
	address hapus = Next(Prec);
	if (hapus != Nil) {
		if (Next(hapus) != Nil)
			Prev(Next(hapus)) = Prec;
		else {
			Last(*L) = Prec;
			Next(Last(*L)) = Nil;
		}
		Next(Prec) = Next(hapus);
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ) {
	*Pdel = Prev(Succ);
	address hapus = Prev(Succ);
	if (hapus != Nil) {
		if (Prev(hapus) != Nil)
			Next(Prev(hapus)) = Succ;
		else {
			First(*L) = Succ;
			Prev(First(*L)) = Nil;
		}
		Prev(Succ) = Prev(hapus);
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
	printf("[");
	address i = First(L);
	boolean first = true;
	while (i != Nil) {
		if (!first)
			printf(",");
		printf("%d", Info(i));
		first = false;
		i = Next(i);
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L) {
	printf("[");
	address i = Last(L);
	boolean first = true;
	while (i != Nil) {
		if (!first)
			printf(",");
		printf("%d", Info(i));
		first = false;
		i = Prev(i);
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
