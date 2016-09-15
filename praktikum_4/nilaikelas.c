/*
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * Tanggal : Kamis, 15 Sepetember 2016
 * Nama file : nilaikelas.c
 */

#include "matriks.h"
#include "boolean.h"
#include "stdio.h"

/*
 * TulisNilaiX
 * Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
 * Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
 * Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
 * I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
 * F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
 * Jika tidak ada elemen dengan nilai = X, menuliskan []
 * Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
   1 3 3
   2 5 6
   7 3 9
   maka jika j = 2 dan X = 3, akan tercetak: [1,3]
 */
void TulisNilaiX (MATRIKS M, indeks j, ElType X) {
	boolean awal = true;
	int i;
	printf("[");
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		if (Elmt(M,i,j) == X) {
			if (!awal)
				printf(",");
			printf("%d",i);
			awal = false;
		}
	printf("]");
}

/*
 * TulisStatistikMhs
 * Menuliskan statistik untuk mahasiswa dengan nomor urut i.
 * Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah.
 * Pada dasarnya: menuliskan statistik untuk data pada baris ke-i
 * I.S. M terdefinisi, i adalah indeks baris efektif M
 * F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
 * [i] <rata-rata> <nilai max> <nilai min>
 * Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
   100 83 83
   72 55 60
   77 93 90
   maka jika i = 2 akan tercetak:
   [2] 62.33 72 55
 */
void TulisStatistikMhs (MATRIKS M, indeks i) {
	ElType max,min;
	MaxMinBrs(M, i, &max, &min);
	printf("[%d] %.2f %d %d\n", i, RataBrs(M,i), max, min);
}

/*
 * TulisStatistikMK
 * Menuliskan statistik untuk mata kuliah dengan nomor urut j.
 * Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut
   dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut
   dan siapa saja yang memperolehnya).
 * Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
 * I.S. M terdefinisi, j adalah indeks kolom efektif M }
 * F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
 * [j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
 * Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
   100 83 83
   72 55 60
   77 93 90
   maka jika j = 2 akan tercetak:
   [2] 77.00 [93 1 [3]] [55 1 [2]]
 */
void TulisStatistikMK (MATRIKS M, indeks j) {
	ElType min,max;
	int nmin,nmax;
	
	float rata = RataKol(M,j);
	MaxMinKol(M, j, &max, &min);
	nmin = CountXKol(M, j, min);
	nmax = CountXKol(M, j, max);
	
	printf("[%d] %.2f [%d %d ",j, rata, max, nmax);
	TulisNilaiX(M,j,max);
	printf("] [%d %d ", min, nmin);
	TulisNilaiX(M,j,min);
	printf("]\n");
}

int main() {
	// Membaca Matrix
	int n,m;
	scanf("%d%d", &n, &m);
	MATRIKS nilai;
	BacaMATRIKS(&nilai, n, m);
	
	// Inisialisasi iterator
	indeks i;
	
	printf("STATISTIK PER MAHASISWA\n");
	for (i = GetFirstIdxBrs(nilai); i <= GetLastIdxBrs(nilai); i++)
		TulisStatistikMhs(nilai, i);
	
	printf("STATISTIK PER MATA KULIAH\n");
	for (i = GetFirstIdxKol(nilai); i <= GetLastIdxKol(nilai); i++)
		TulisStatistikMK(nilai, i);
		
	return 0;
}
