/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 8 Agustus 2016
 */

#include "boolean.h"
#include "array.h"

#include "stdio.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
void MakeEmpty (TabInt * T) {
	Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
	return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T) {
	return IdxMax;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T) {
	return NbElmt(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
	return i >= IdxMin && i <= IdxMax;
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i) {
	return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
	return NbElmt(T) <= 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) {
	return NbElmt(T) >= IdxMax;
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T) {
	int n;
	do {
		scanf("%d", &n);
	} while (n < 0 || n > MaxNbEl(*T));

	Neff(*T) = n;
	IdxType i;
	for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++)
		scanf("%d", &(Elmt(*T,i)));
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void BacaIsiTab (TabInt * T) {
	Neff(*T) = 0;

	ElType x;
	do {
		scanf("%d", &x);
		if (x != -9999)
			Elmt(*T, ++Neff(*T)) = x;
	} while (x != -9999 && Neff(*T) < IdxMax);
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
void TulisIsi (TabInt T) {
	if (IsEmpty(T))
		printf("Tabel kosong\n");
	else {
		IdxType i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			printf("[%d]%d\n", i, Elmt(T,i));
	}
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T) {
	printf("[");
	IdxType i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		if (i > GetFirstIdx(T))
			printf(",%d", Elmt(T,i));
		else
			printf("%d", Elmt(T,i));
	printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
	TabInt hasil;
	Neff(hasil) = NbElmt(T1);
	IdxType i;
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		Elmt(hasil, i) = Elmt(T1,i) + Elmt(T2,i);
	return hasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2) {
	TabInt hasil;
	Neff(hasil) = NbElmt(T1);
	IdxType i;
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		Elmt(hasil, i) = Elmt(T1,i) - Elmt(T2,i);
	return hasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2) {
	TabInt hasil;
	Neff(hasil) = NbElmt(T1);
	IdxType i;
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		Elmt(hasil, i) = Elmt(T1,i) * Elmt(T2,i);
	return hasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c) {
	TabInt hasil;
	Neff(hasil) = NbElmt(Tin);
	IdxType i;
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
		Elmt(hasil, i) = Elmt(Tin,i) * c;
	return hasil;
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2) {
	if (IsEmpty(T1) && IsEmpty(T2))
		return true;
	else if (NbElmt(T1) == NbElmt(T2)) {
		IdxType i = GetFirstIdx(T1);
		while (i < GetLastIdx(T1) && Elmt(T1,i) == Elmt(T2,i))
			i++;
		if (i == GetLastIdx(T1))
			return Elmt(T1,i) == Elmt(T2,i);
		else
			return false;
	} else
		return false;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2) {
	IdxType i = GetFirstIdx(T1);
	while (i <= GetLastIdx(T1) && i <= GetLastIdx(T2)) {
		if (Elmt(T1,i) != Elmt(T2,i))
			return Elmt(T1,i) < Elmt(T2,i);
		i++;
	}
	return i > GetLastIdx(T1) && i <= GetLastIdx(T2);
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
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
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X) {
	if (IsEmpty(T))
		return IdxUndef;
	else {
		IdxType i = GetFirstIdx(T);
		IdxType idx;
		boolean found = false;
		while (!found && i <= GetLastIdx(T)) {
			found = Elmt(T,i) == X;
			idx = i;
			i++;
		}

		if (found)
			return idx;
		else
			return IdxUndef;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X) {
	boolean found = false;
	IdxType i = GetFirstIdx(T);
	while (!found && i <= GetLastIdx(T))
		found = Elmt(T, i++) == X;
	return found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X) {
	Elmt(T,0) = X;
	IdxType i = GetLastIdx(T);
	while (i >= 0 && Elmt(T,i) != X)
		i--;
	return i > 0;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
	ElType m = Elmt(T, GetFirstIdx(T));
	IdxType i;
	for (i = 2; i <= GetLastIdx(T); i++)
		if (Elmt(T,i) > m)
			m = Elmt(T,i);
	return m;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T) {
	ElType m = Elmt(T, GetFirstIdx(T));
	IdxType i;
	for (i = 2; i <= GetLastIdx(T); i++)
		if (Elmt(T,i) < m)
			m = Elmt(T,i);
	return m;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T) {
	IdxType j = GetFirstIdx(T);
	ElType m = Elmt(T, GetFirstIdx(T));
	IdxType i;
	for (i = 2; i <= GetLastIdx(T); i++)
		if (Elmt(T,i) > m) {
			m = Elmt(T,i);
			j = i;
		}
	return j;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T) {
	IdxType j = GetFirstIdx(T);
	ElType m = Elmt(T, GetFirstIdx(T));
	IdxType i;
	for (i = 2; i <= GetLastIdx(T); i++)
		if (Elmt(T,i) < m) {
			m = Elmt(T,i);
			j = i;
		}
	return j;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout) {
	Neff(*Tout) = NbElmt(Tin);
	IdxType i;
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
		Elmt(*Tout,i) = Elmt(Tin,i);
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T) {
	TabInt hasil;
	Neff(hasil) = Neff(T);

	IdxType i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		Elmt(hasil,i) = Elmt(T, GetLastIdx(T)-i+GetFirstIdx(T));

	return hasil;
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T) {
	if (IsEmpty(T))
		return true;
	else {
		IdxType i = GetFirstIdx(T);
		IdxType j = GetLastIdx(T);
		while (i < j && Elmt(T,i) == Elmt(T,j)) {
			i++;
			j--;
		}
		return i >= j;
	}
}
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T) {
	if (!IsEmpty(*T)) {
		IdxType i;
		for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
			IdxType j;
			for (j = i + 1; j <= GetLastIdx(*T); j++)
				if (Elmt(*T,i) < Elmt(*T,j)) {
					ElType temp = Elmt(*T,i);
					Elmt(*T,i) = Elmt(*T,j);
					Elmt(*T,j) = temp;
				}
		}
	}
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt * T) {
	if (!IsEmpty(*T)) {
		IdxType i;
		for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
			IdxType j = i - 1;
			ElType temp = Elmt(*T, i);
			while (j >= GetFirstIdx(*T) && Elmt(*T,j) > temp) {
				Elmt(*T,j+1) = Elmt(*T,j);
				j--;
			}
			Elmt(*T, j+1) = temp;
		}
	}
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X) {
	Neff(*T) += 1;
	Elmt(*T, GetLastIdx(*T)) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, ElType X, IdxType i) {
	IdxType idx;
	for (idx = GetLastIdx(*T); idx >= i; idx--)
		Elmt(*T,idx + 1) = Elmt(*T, idx);
	Elmt(*T,i) = X;
	Neff(*T) += 1;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
	*X = Elmt(*T, GetLastIdx(*T));
	Neff(*T) -= 1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X) {
	IdxType idx;
	*X = Elmt(*T, i);
	for (idx = i+1; idx <= GetLastIdx(*T); idx++)
		Elmt(*T,idx-1) = Elmt(*T,idx);
	Neff(*T) -= 1;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X) {
	if (SearchSentinel(*T, X))
		printf("nilai sudah ada\n");
	else if (!IsFull(*T))
		AddAsLastEl(T, X);
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X) {
	return Search1(T,X);
}
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
ElType MaxUrut (TabInt T) {
	return Elmt(T, GetLastIdx(T));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
ElType MinUrut (TabInt T) {
	return Elmt(T, GetFirstIdx(T));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min) {
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
void Add1Urut (TabInt * T, ElType X) {
	if (!IsFull(*T)) {
		IdxType i = GetLastIdx(*T);
		while (i >= GetFirstIdx(*T) && Elmt(*T,i) > X) {
			Elmt(*T, i+1) = Elmt(*T,i);
			i--;
		}
		Neff(*T) += 1;
		Elmt(*T,i+1) = X;
	}
}
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
void Del1Urut (TabInt * T, ElType X) {
	IdxType i = Search1(*T, X);
	ElType tmp;
	if (i != IdxUndef)
		DelEli(T, i, &tmp);
}
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
