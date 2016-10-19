#include "listlinier.h"
#include "boolean.h"
#include "stdlib.h"
#include "stdio.h"

/*
 * IsEmpty
 * Mengirim true jika list kosong
 */
boolean IsEmpty (List L) {
	return First(L) == Nil;
}

/*
 * CreateEmpty
 * I.S. sembarang
 * F.S. Terbentuk list kosong
 */
void CreateEmpty (List *L) {
	First(*L) = Nil;
}

/*
 * Alokasi
 * Mengirimkan address hasil alokasi sebuah elemen
 * Jika alokasi berhasil, maka address tidak nil, dan misalnya
 * menghasilkan P, maka Info(P)=X, Next(P)=Nil
 * Jika alokasi gagal, mengirimkan Nil
 */
address Alokasi (infotype X) {
	address p = (address) malloc(sizeof(ElmtList));
	if (p != Nil) {
		Info(p) = X;
		Next(p) = Nil;
	}
	return p;
}

/*
 * Dealokasi
 * I.S. P terdefinisi
 * F.S. P dikembalikan ke sistem
 * Melakukan dealokasi/pengembalian address P
 */
void Dealokasi (address *P) {
	free(*P);
}

/*
 * Search
 * Mencari apakah ada elemen list dengan Info(P)= X
 * Jika ada, mengirimkan address elemen tersebut.
 * Jika tidak ada, mengirimkan Nil
 */
address Search (List L, infotype X) {
	address p = First(L);
	address i = Nil;
	while (i == Nil && p != Nil) {
		if (Info(p) == X)
			i = p;
		p = Next(p);
	}
	return i;
}

/*
 * InsVFirst
 * I.S. L mungkin kosong
 * F.S. Melakukan alokasi sebuah elemen dan
 * menambahkan elemen pertama dengan nilai X jika alokasi berhasil
 */
void InsVFirst (List *L, infotype X) {
	address p = Alokasi(X);
	if (p != Nil) {
		Next(p) = First(*L);
		First(*L) = p;
	}
}

/*
 * InsVLast
 * I.S. L mungkin kosong
 * F.S. Melakukan alokasi sebuah elemen dan
 * menambahkan elemen list di akhir: elemen terakhir yang baru
 * bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
 */
void InsVLast (List *L, infotype X) {
	address last = Nil;
	address i = First(*L);
	while (i != Nil) {
		last = i;
		i = Next(i);
	}
	
	if (last == Nil)
		First(*L) = Alokasi(X);
	else
		Next(last) = Alokasi(X);
}

/*
 * DelVFirst
 * I.S. List L tidak kosong
 * F.S. Elemen pertama list dihapus: nilai info disimpan pada X
 *      dan alamat elemen pertama di-dealokasi
 */
void DelVFirst (List *L, infotype *X) {
	address first = First(*L);
	First(*L) = Next(first);
	*X = Info(first);
	Dealokasi(&first);
}

/*
 * DelVLast
 * I.S. list tidak kosong
 * F.S. Elemen terakhir list dihapus: nilai info disimpan pada X
 *      dan alamat elemen terakhir di-dealokasi
 */
void DelVLast (List *L, infotype *X) {
	address last = Nil;
	address blast = Nil;
	address i = First(*L);
	while (i != Nil) {
		blast = last;
		last = i;
		i = Next(i);
	}
	
	if (blast != Nil)
		Next(blast) = Nil;
	else
		First(*L) = Nil;
	
	*X = Info(last);
	Dealokasi(&last);
}

/*
 * InsertFirst
 * I.S. Sembarang, P sudah dialokasi
 * F.S. Menambahkan elemen ber-address P sebagai elemen pertama
 */
void InsertFirst (List *L, address P) {
	Next(P) = First(*L);
	First(*L) = P;
}

/*
 * InsertAfter
 * I.S. Prec pastilah elemen list dan bukan elemen terakhir,
 *      P sudah dialokasi
 * F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
 */
void InsertAfter (List *L, address P, address Prec) {
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

/*
 * InsertLast
 * I.S. Sembarang, P sudah dialokasi
 * F.S. P ditambahkan sebagai elemen terakhir yang baru
 */
void InsertLast (List *L, address P) {
	address last = Nil;
	address i = First(*L);
	while (i != Nil) {
		last = i;
		i = Next(i);
	}
	
	Next(P) = Nil;
	if (last == Nil)
		First(*L) = P;
	else
		Next(last) = P;
}

/*
 * DelFirst
 * I.S. List tidak kosong
 * F.S. P adalah alamat elemen pertama list sebelum penghapusan
 *      Elemen list berkurang satu (mungkin menjadi kosong)
 * First element yg baru adalah suksesor elemen pertama yang lama
 */
void DelFirst (List *L, address *P) {
	address first = First(*L);
	First(*L) = Next(first);
	*P = first;
}

/*
 * DelP
 * I.S. Sembarang
 * F.S. Jika ada elemen list beraddress P, dengan Info(P)=X
 * 		Maka P dihapus dari list dan di-dealokasi
 * 		Jika tidak ada elemen list dengan Info(P)=X, maka list tetap
 * 		List mungkin menjadi kosong karena penghapusan
 */
void DelP (List *L, infotype X) {
	address bi = Nil;
	address i = First(*L);
	while (i != Nil)
		if (Info(i) == X) {
			if (bi != Nil)
				Next(bi) = Next(i);
			else
				First(*L) = Next(i);
			address tmp = Next(i);
			Dealokasi(&i);
			i = tmp;
		} else {
			bi = i;
			i = Next(i);
		}
}

/*
 * DelLast
 * I.S. List tidak kosong
 * F.S. P adalah alamat elemen terakhir list sebelum penghapusan
 *      Elemen list berkurang satu (mungkin menjadi kosong)
 * Last element baru adalah predesesor elemen pertama yg lama,
 * jika ada
 */
void DelLast (List *L, address *P) {
	address blast = Nil;
	address last = Nil;
	address i = First(*L);
	while (i != Nil) {
		blast = last;
		last = i;
		i = Next(i);
	}
	
	*P = last;
	if (blast != Nil)
		Next(blast) = Nil;
	else
		First(*L) = Nil;
}

/*
 * DelAfter
 * I.S. List tidak kosong. Prec adalah anggota list
 * F.S. Menghapus Next(Prec):
 *      Pdel adalah alamat elemen list yang dihapus
 */
void DelAfter (List *L, address *Pdel, address Prec) {
	*Pdel = Next(Prec);
	if (*Pdel != Nil)
		Next(Prec) = Next(*Pdel);
}

/*
 * PrintInfo
 * I.S. List mungkin kosong
 * F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en]
 * Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
 * Jika list kosong : menulis []
 * Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah
 */
void PrintInfo (List L) {
	printf("[");
	boolean awal = true;
	address i = First(L);
	while (i != Nil) {
		if (!awal)
			printf(",");
		printf("%d", Info(i));
		i = Next(i);
		awal = false;
	}
	printf("]");
}

/*
 * NbElmt
 * Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong
 */
int NbElmt (List L) {
	int c = 0;
	address i = First(L);
	while (i != Nil) {
		c++;
		i = Next(i);
	}
	return c;
}

/*
 * Max
 * Mengirimkan nilai Info(P) yang maksimum
 */
infotype Max (List L) {
	infotype m = Info(First(L));
	address i = Next(First(L));
	while (i != Nil) {
		if (Info(i) > m)
			m = Info(i);
		i = Next(i);
	}
	return m;
}

/*
 * Konkat1
 * I.S. L1 dan L2 sembarang
 * F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2
 * Konkatenasi dua buah list : L1 dan L2
 * menghasilkan L3 yang baru (dengan elemen list L1 dan L2)
 * dan L1 serta L2 menjadi list kosong.
 * Tidak ada alokasi/dealokasi pada prosedur ini
 */
void Konkat1 (List *L1, List *L2, List *L3) {
	if (IsEmpty(*L1))
		First(*L3) = First(*L2);
	else {
		First(*L3) = First(*L1);
		address last = Nil;
		address i = First(*L1);
		while (i != Nil) {
			last = i;
			i = Next(i);
		}
		Next(last) = First(*L2);
	}
	
	First(*L1) = First(*L2) = Nil;
}
