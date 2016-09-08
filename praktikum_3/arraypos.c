/*
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 8 September 2016
 * File : arraypos.c
 */

#include "boolean.h"
#include "stdio.h"
#include "arraypos.h"

/* 
 * MakeEmpty : membuat tabel kosong
 * I.S. T sembarang
 * F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1
 * Proses: Inisialisasi semua elemen tabel T dengan ValUndef
 */
void MakeEmpty (TabInt * T) {
	IdxType i;
	for (i = IdxMin; i <= IdxMax; i++)
		Elmt(*T,i) = ValUndef;
}

/* 
 * NbElmt : Banyaknya elemen
 * Mengirimkan banyaknya elemen efektif tabel
 * Mengirimkan nol jika tabel kosong
 */
int NbElmt (TabInt T) {
	IdxType i = IdxMin;
	while (i <= IdxMax && Elmt(T,i) != ValUndef)
		i++;
	return i-1;
}

/*
 * MaxNbEl : Daya tampung container
 * Mengirimkan maksimum elemen yang dapat ditampung oleh tabel
 */
int MaxNbEl (TabInt T) {
	return IdxMax - IdxMin + 1;
}

/* 
 * GetFirstIdx 
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen T pertama
 */
IdxType GetFirstIdx (TabInt T) {
	return IdxMin;
}

/*
 * GetLastIdx
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen T terakhir
 */
IdxType GetLastIdx (TabInt T) {
	return GetFirstIdx(T) + NbElmt(T) - 1;
}

/*
 * IsIdxValid
 * Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel
 * yaitu antara indeks yang terdefinisi utk container
 */
boolean IsIdxValid (TabInt T, IdxType i) {
	return i >= IdxMin && i <= IdxMax;
}

/*
 * IsIdxEff
 * Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel
 * yaitu antara FirstIdx(T)..LastIdx(T)
 */
boolean IsIdxEff (TabInt T, IdxType i) {
	return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}

/*
 * IsEmpty
 * Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak
 */

boolean IsEmpty (TabInt T) {
	return NbElmt(T) <= 0;
}

/*
 * IsFull
 * Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak
 */
boolean IsFull (TabInt T) {
	return NbElmt(T) >= MaxNbEl(T);
}

/*
 * BacaIsi Mendefinisikan isi tabel dari pembacaan
 * I.S. T sembarang
 * F.S. Tabel T terdefinisi
 * Proses : membaca banyaknya elemen T dan mengisi nilainya
 * 1. Baca banyaknya elemen diakhiri enter, misalnya N
 *    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T)
 *    Jika N tidak valid, tidak diberikan pesan kesalahan
 * 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
 *    IdxMin satu per satu diakhiri enter
 *    Jika N = 0; hanya terbentuk T kosong
 */
void BacaIsi (TabInt * T) {
	MakeEmpty(T);
	
	int n;
	do {
		scanf("%d", &n);
	} while (n < 0 || n > MaxNbEl(*T));

	IdxType i;
	for (i = IdxMin; i < IdxMin + n; i++)
		scanf("%d", &(Elmt(*T,i)));
}

/*
 * TulisIsiTab
 * Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter
 * I.S. T boleh kosong
 * F.S. Jika T tidak kosong: [e1,e2,...,en]
 * Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
 * Jika tabel kosong : menulis []
 */
void TulisIsiTab (TabInt T) {
	printf("[");
	if (!IsEmpty(T)) {
		IdxType i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			if (i > GetFirstIdx(T))
				printf(",%d", Elmt(T,i));
			else
				printf("%d", Elmt(T,i));
	}
	printf("]");
}

/*
 * PlusMinusTab
 * Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
 * Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan
 * Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama
 */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus) {
	TabInt hasil;
	
	MakeEmpty(&hasil);
	
	IdxType i;
	IdxType j = GetFirstIdx(T1);
	IdxType k = GetFirstIdx(T2);
	for (i = IdxMin; j <= GetLastIdx(T1); i++,j++,k++)
		if (plus)
			Elmt(hasil, i) = Elmt(T1,j) + Elmt(T2,k);
		else
			Elmt(hasil, i) = Elmt(T1,j) - Elmt(T2,k);

	return hasil;
}

/*
 * IsEQ
 * Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama
 */
boolean IsEQ (TabInt T1, TabInt T2) {
	if (NbElmt(T1) == NbElmt(T2)) {
		if (IsEmpty(T1))
			return true;
		IdxType i = GetFirstIdx(T1);
		IdxType j = GetFirstIdx(T2);
		boolean sama = true;
		while (sama && i <= GetLastIdx(T1))
			sama = Elmt(T1,i++) == Elmt(T2,j++);
		return sama;
	} else
		return false;
}

/*
 * Search1
 * Search apakah ada elemen tabel T yang bernilai X
 * Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
 * Jika tidak ada, mengirimkan IdxUndef
 * Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
 * Skema Searching yang digunakan bebas
 */
IdxType Search1 (TabInt T, ElType X) {
	if (IsEmpty(T))
		return IdxUndef;
	else {
		IdxType i = GetFirstIdx(T);
		while (i <= GetLastIdx(T) && Elmt(T,i) != X)
			i++;
		if (i > GetLastIdx(T))
			return IdxUndef;
		else
			return i;
	}
}

/*
 * SearchB
 * Search apakah ada elemen tabel T yang bernilai X
 * Jika ada, menghasilkan true, jika tidak ada menghasilkan false
 * Skema searching yang digunakan bebas
 */
boolean SearchB (TabInt T, ElType X) {
	return Search1(T,X) != IdxUndef;
}

/*
 * MaxMin
 * I.S. Tabel T tidak kosong
 * F.S. Max berisi nilai maksimum T;
 *      Min berisi nilai minimum T
 */
void MaxMin (TabInt T, ElType * Max, ElType * Min) {
	IdxType i = GetFirstIdx(T);
	
	*Max = Elmt(T,i);
	*Min = Elmt(T,i);
	
	i++;
	while (i <= GetLastIdx(T)) {
		if (Elmt(T,i) > *Max)
			*Max = Elmt(T,i);
		if (Elmt(T,i) < *Min)
			*Min = Elmt(T,i);
		i++;
	}
}

/*
 * SumTab
 * Menghasilkan hasil penjumlahan semua elemen T
 * Jika T kosong menghasilkan 0
 */
ElType SumTab (TabInt T) {
	ElType sum = 0;
	if (!IsEmpty(T)) {
		IdxType i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			sum += Elmt(T,i);
	}
	return sum;
}

/*
 * CountX
 * Menghasilkan berapa banyak kemunculan X di T
 * Jika T kosong menghasilkan 0
 */
int CountX (TabInt T, ElType X) {
	if (!IsEmpty(T)) {
		IdxType i;
		int n = 0;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			if (Elmt(T,i) == X)
				n++;
		return n;
	} else
		return 0;
}

/*
 * IsAllGenap
 * Menghailkan true jika semua elemen T genap
 */
boolean IsAllGenap (TabInt T) {
	boolean genap = true;
	if (!IsEmpty(T)) {
		IdxType i = GetFirstIdx(T);
		while (i <= GetLastIdx(T) && genap)
			genap = Elmt(T,i++) % 2 == 0;
	}
	return genap;
}

/*
 * Sort
 * I.S. T boleh kosong
 * F.S. Jika asc = true, T terurut membesar
 *      Jika asc = false, T terurut mengecil
 * Proses : Mengurutkan T dengan salah satu algoritma sorting,
 * algoritma bebas
 */
void Sort (TabInt * T, boolean asc) {
	IdxType i,j;
	if (!IsEmpty(*T)) {
		IdxType fi = GetFirstIdx(*T);
		IdxType li = GetLastIdx(*T);
		for (i = fi; i < li; i++)
			for (j = i + 1; j <= li; j++)
				if ((Elmt(*T,i) > Elmt(*T,j) && asc) || (Elmt(*T,i) < Elmt(*T,j) && !asc)) {
					ElType temp = Elmt(*T,i);
					Elmt(*T,i) = Elmt(*T,j);
					Elmt(*T,j) = temp;
				}
	}
}

/*
 * AddAsLastEl
 * Proses: Menambahkan X sebagai elemen terakhir tabel
 * I.S. Tabel T boleh kosong, tetapi tidak penuh
 * F.S. X adalah elemen terakhir T yang baru
 */
void AddAsLastEl (TabInt * T, ElType X) {
	if (IsEmpty(*T))
		Elmt(*T,IdxMin) = X;
	else
		Elmt(*T,GetLastIdx(*T)+1) = X;
}

/*
 * DelLastEl
 * Proses : Menghapus elemen terakhir tabel
 * I.S. Tabel tidak kosong
 * F.S. X adalah nilai elemen terakhir T sebelum penghapusan,
 *      Banyaknya elemen tabel berkurang satu
 *      Tabel T mungkin menjadi kosong
 */
void DelLastEl (TabInt * T, ElType * X) {
	*X = Elmt(*T, GetLastIdx(*T));
	Elmt(*T, GetLastIdx(*T)) = ValUndef;
}
