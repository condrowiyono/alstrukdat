#include "listdp.h"
#include "boolean.h"
#include "stdio.h"

/* 
 * SearchPrec
 * Mengirimkan address elemen sebelum elemen yang nilainya>=X
 * Mencari apakah ada elemen list dengan Info(P)>=X
 * Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama.
 * Jika tidak ada, mengirimkan Nil
 * Jika P adalah elemen pertama, maka Prec=Nil
 */
address SearchPrec (List L, infotype X);

/*
 * InsertUrut
 * Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
   Manfaatkan fungsi SearchPrec.
 * I.S. X terdefinisi. L terdefinisi, mungkin kosong.
        Jika tidak kosong, L terurut membesar.
 * F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
        satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
        dapat dilakukan di awal, di tengah, maupun di akhir.
        Jika alokasi gagal, L tetap.
 */
void InsertUrut (List *L, infotype X);

/* 
 * Max
 * Menghasilkan nilai terbesar dari elemen list L. L tidak kosong.
 */
infotype Max (List L);

/* 
 * Min
 * Menghasilkan nilai terkecil dari elemen list L. L tidak kosong.
 */
infotype Min (List L);

/* 
 * Average
 * Menghasilkan nilai rata-rata elemen L. L tidak kosong.
 */
float Average (List L);

int main() {
	List list;
	CreateEmpty(&list);
	
	infotype x;
	scanf("%d", &x);
	while (x != -9999) {
		InsertUrut(&list, x);
		scanf("%d", &x);
	}
	
	if (!IsEmpty(list)) {
		printf("%d\n%d\n%.2f\n", Max(list), Min(list), Average(list));	
		PrintForward(list); printf("\n");
		PrintBackward(list); printf("\n");
	} else
		printf("[]\n");
	
	return 0;
}

address SearchPrec (List L, infotype X) {
	address i = First(L);
	address h = Nil;
	boolean found = false;
	while (!found && i != Nil)
		if (Info(i) >= X) {
			h = Prev(i);
			found = true;
		} else
			i = Next(i);
	return h;
}

void InsertUrut (List *L, infotype X) {
	if (IsEmpty(*L))
		InsVLast(L, X);
	else {
		address prev = SearchPrec(*L,X);
		if (prev == Nil) {
			if (Info(First(*L)) < X)
				InsVLast(L, X);
			else
				InsVFirst(L, X);
		} else
			InsertAfter(L, Alokasi(X), prev);
	}
}

infotype Max (List L) {
	address i = Next(First(L));
	infotype max = Info(First(L));
	while (i != Nil) {
		if (Info(i) > max)
			max = Info(i);
		i = Next(i);
	}
	return max;
}

infotype Min (List L) {
	address i = Next(First(L));
	infotype min = Info(First(L));
	while (i != Nil) {
		if (Info(i) < min)
			min = Info(i);
		i = Next(i);
	}
	return min;
}

float Average (List L) {
	address i = First(L);
	infotype sum = 0;
	int n = 0;
	while (i != Nil) {
		sum += Info(i);
		i = Next(i);
		n++;
	}
	return (float) sum / (float) n;
}
