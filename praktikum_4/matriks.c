/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 15 September 2015
 * Nama file : matriks.c
 */

#include "matriks.h"
#include "boolean.h"
#include "stdio.h"

/*
 * MakeMATRIKS
 * Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori
 * I.S. NB dan NK adalah valid untuk memori matriks yang dibuat
 * F.S. Matriks M sesuai dengan definisi di atas terbentuk
 */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	int i,j;
	for (i = 1; i <= NB; i++)
		for (j = 1; j <= NK; j++)
			Elmt(*M,i,j) = 0;
}

/*
 * IsIdxValid
 * Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun
 */
boolean IsIdxValid (int i, int j) {
	return i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax;
}

/*
 * GetFirstIdxBrs
 * Mengirimkan indeks baris terkecil M
 */
indeks GetFirstIdxBrs (MATRIKS M) {
	return BrsMin;
}

/*
 * GetFirstIdxKol
 * Mengirimkan indeks kolom terkecil M
 */
indeks GetFirstIdxKol (MATRIKS M) {
	return KolMin;
}

/*
 * GetLastIdxBrs
 * Mengirimkan indeks baris terbesar M
 */
indeks GetLastIdxBrs (MATRIKS M) {
	return NBrsEff(M);
}

/*
 * GetLastIdxKol
 * Mengirimkan indeks kolom terbesar M
 */
indeks GetLastIdxKol (MATRIKS M) {
	return NKolEff(M);
}

/*
 * IsIdxEff
 * Mengirimkan true jika i, j adalah indeks efektif bagi M
 */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
	return i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M); 
}

/*
 * GetElmtDiagonal
 * Mengirimkan elemen M(i,i)
 */
ElType GetElmtDiagonal (MATRIKS M, indeks i) {
	return Elmt(M,i,i);
}

/*
 * CopyMATRIKS
 * Melakukan assignment MHsl  MIn
 */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) {
	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
	int i,j;
	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++)
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++)
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
}

/*
 * BacaMATRIKS
 * I.S. IsIdxValid(NB,NK)
 * F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK
 * Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya
 * Selanjutnya membaca nilai elemen per baris dan kolom
 * Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
   1 2 3
   4 5 6
   8 9 10 
 */
void BacaMATRIKS (MATRIKS * M, int NB, int NK) {
	MakeMATRIKS(NB,NK,M);
	int i,j;
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
			scanf("%d", &Elmt(*M,i,j));
}

/*
 * TulisMATRIKS
 * I.S. M terdefinisi
 * F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi
 * Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom
 * Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
   1 2 3
   4 5 6
   8 9 10
 */
void TulisMATRIKS (MATRIKS M) {
	int i,j;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			printf("%d", Elmt(M,i,j));
			if (j == GetLastIdxKol(M) && i < GetLastIdxBrs(M))
				printf("\n");
			if (j < GetLastIdxKol(M))
				printf(" ");
		}
}

/*
 * TambahMATRIKS
 * Prekondisi : M1  berukuran sama dengan M2
 * Mengirim hasil penjumlahan matriks: M1 + M2
 */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
	MATRIKS M;
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
	int i,j;
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
			Elmt(M,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
	return M;
}
 

/*
 * KurangMATRIKS
 * Prekondisi : M berukuran sama dengan M
 * Mengirim hasil pengurangan matriks: salinan M1 – M2
 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
	MATRIKS M;
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
	int i,j;
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
			Elmt(M,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
	return M;
}

/*
 * KaliMATRIKS
 * Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2
 * Mengirim hasil perkalian matriks: salinan M1 * M2
 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
	MATRIKS M;
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
	int i,j,k;
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++)
			for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
				Elmt(M,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
	return M;
}

/*
 * KaliKons
 * Mengirim hasil perkalian setiap elemen M dengan X
 */
MATRIKS KaliKons (MATRIKS M, ElType X) {
	MATRIKS MH;
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MH);
	int i,j;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			Elmt(MH,i,j) = Elmt(M,i,j) * X;
	return MH;
}

/*
 * PKaliKons
 * I.S. M terdefinisi, K terdefinisi
 * F.S. Mengalikan setiap elemen M dengan K
 */
void PKaliKons (MATRIKS * M, ElType K) {
	int i,j;
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
			Elmt(*M,i,j) *= K;
}

/*
 * EQ
 * Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan
 * untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j)
 * Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2)
 */
boolean EQ (MATRIKS M1, MATRIKS M2) {
	if (EQSize(M1,M2)) {
		int i,j;
		boolean sama = true;
		for (i = GetFirstIdxBrs(M1); sama && i <= GetLastIdxBrs(M1); i++)
			for (j = GetFirstIdxKol(M1); sama && j <= GetLastIdxKol(M1); j++)
				sama = Elmt(M1,i,j) == Elmt(M2,i,j);
		return sama;
	} else
		return false;
}

/*
 * NEQ
 * Mengirimkan true jika M1 tidak sama dengan M2
 */
boolean NEQ (MATRIKS M1, MATRIKS M2) {
	return !EQ(M1,M2);
}

/*
 * EQSize
 * Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2
 * yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2)
 */
boolean EQSize (MATRIKS M1, MATRIKS M2) {
	return NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2);
}

/*
 * NBElmt
 * Mengirimkan banyaknya elemen M
 */
int NBElmt (MATRIKS M) {
	return NBrsEff(M) * NKolEff(M);
}

/*
 * IsBujurSangkar
 * Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama
 */
boolean IsBujurSangkar (MATRIKS M) {
	return NBrsEff(M) == NKolEff(M);
}

/*
 * IsSimetri
 * Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j) = M(j,i)
 */
boolean IsSimetri (MATRIKS M) {
	if (IsBujurSangkar(M)) {
		boolean ya = true;
		int i,j;
		for (i = GetFirstIdxBrs(M); ya && i <= GetLastIdxBrs(M); i++)
			for (j = i + 1; ya && j <= GetLastIdxKol(M); j++)
				ya = Elmt(M,i,j) == Elmt(M,j,i);
		return ya;
	} else
		return false;
}

/*
 * IsSatuan
 * Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0
 */
boolean IsSatuan (MATRIKS M) {
	if (IsBujurSangkar(M)) {
		boolean satuan = true;
		int i,j;
		for (i = GetFirstIdxBrs(M); satuan && i <= GetLastIdxBrs(M); i++)
			for (j = GetFirstIdxKol(M); satuan && j <= GetLastIdxKol(M); j++)
				satuan = (i != j || Elmt(M,i,j) == 1) && (i == j || Elmt(M,i,j) == 0);
		return satuan;
	} else
		return false;
}

/*
 * IsSparse
 * Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0
 */
boolean IsSparse (MATRIKS M) {
	int n,i,j;
	n = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			if (Elmt(M,i,j) != 0)
				n++;
	return 20*n <= NBElmt(M);
}

/*
 * Inverse1
 * Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1)
 */
MATRIKS Inverse1 (MATRIKS M) {
	return KaliKons(M,-1);
}

/*
 * Determinan
 * Prekondisi: IsBujurSangkar(M)
 * Menghitung nilai determinan M
 */
float Determinan (MATRIKS M) {	
	if (NBrsEff(M) == 1)
		return Elmt(M,GetFirstIdxBrs(M), GetLastIdxBrs(M));
	else {
		float det = 0.0f;
		int i;
		for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++) {
			MATRIKS X;
			MakeMATRIKS(NBrsEff(M)-1, NBrsEff(M)-1,&X);
			int j,k;
			for (j = GetFirstIdxBrs(M) + 1; j <= GetLastIdxBrs(M); j++)
				for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++)
					if (k < i)
						Elmt(X,j-1,k) = Elmt(M,j,k);
					else if (k > i)
						Elmt(X,j-1,k-1) = Elmt(M,j,k);
			if (i % 2 == 0)
				det -= Elmt(M,GetFirstIdxBrs(M),i) * Determinan(X);
			else
				det += Elmt(M,GetFirstIdxBrs(M),i) * Determinan(X);
		}
		return det;
	}
}

/*
 * PInverse1
 * I.S. M terdefinisi
 * F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1)
 */
void PInverse1 (MATRIKS * M) {
	*M = KaliKons(*M,-1);
}

/*
 * Transpose
 * I.S. M terdefinisi dan IsBujursangkar(M)
 * F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i)
 */
void Transpose (MATRIKS * M) {
	int i,j,tmp;
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
		for (j = i + 1; j <= GetLastIdxKol(*M); j++) {
			tmp = Elmt(*M,i,j);
			Elmt(*M,i,j) = Elmt(*M,j,i);
			Elmt(*M,j,i) = tmp;
		}
}

/*
 * RataBrs
 * Menghasilkan rata-rata dari elemen pada baris ke-i
 * Prekondisi: i adalah indeks baris efektif dari M
 */
float RataBrs (MATRIKS M, indeks i) {
	int j,sum;
	sum = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		sum += Elmt(M,i,j);
	return (float) sum / (float) NKolEff(M);
}

/*
 * RataKol
 * Menghasilkan rata-rata dari elemen pada kolom ke-j
 * Prekondisi: j adalah indeks kolom efektif dari M
 */
float RataKol (MATRIKS M, indeks j) {
	int i,sum;
	sum = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		sum += Elmt(M,i,j);
	return (float) sum / (float) NBrsEff(M);
}

/*
 * MaxMinBrs
 * I.S. i adalah indeks baris efektif dari M, M terdefinisi
 * F.S. max berisi elemen maksimum pada baris i dari M
        min berisi elemen minimum pada baris i dari M
 */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min) {
	*max = Elmt(M,i,GetFirstIdxKol(M));
	*min = Elmt(M,i,GetFirstIdxKol(M));
	int j;
	for (j = GetFirstIdxKol(M) + 1; j <= GetLastIdxKol(M); j++) {
		if (Elmt(M,i,j) < *min)
			*min = Elmt(M,i,j);
		if (Elmt(M,i,j) > *max)
			*max = Elmt(M,i,j);
	}
} 

/* 
 * MaxMinKol
 * I.S. j adalah indeks kolom efektif dari M, M terdefinisi
 * F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M
 */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min) {
	*max = Elmt(M,GetFirstIdxBrs(M),j);
	*min = Elmt(M,GetFirstIdxBrs(M),j);
	int i;
	for (i = GetFirstIdxBrs(M) + 1; i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M,i,j) < *min)
			*min = Elmt(M,i,j);
		if (Elmt(M,i,j) > *max)
			*max = Elmt(M,i,j);
	}
}

/*
 * CountXBrs
 * Menghasilkan banyaknya kemunculan X pada baris i dari M
 */
int CountXBrs (MATRIKS M, indeks i, ElType X) {
	int j,n;
	n = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		if (Elmt(M,i,j) == X)
			n++;
	return n;
}

/*
 * CountXKol
 * Menghasilkan banyaknya kemunculan X pada kolom j dari M
 */
int CountXKol (MATRIKS M, indeks j, ElType X){
	int i,n;
	n = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		if (Elmt(M,i,j) == X)
			n++;
	return n;
}
