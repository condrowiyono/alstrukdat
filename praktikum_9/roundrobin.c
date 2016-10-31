#include "listsirkuler.h"
#include "stdio.h"
#include "boolean.h"

/*
 * DeleteRR
 * Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
   jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
   jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar
 * Jika L kosong, cetak "List kosong"
 * I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
        L terdefinisi, mungkin kosong.
 * F.S. Elemen terakhir L diproses sesuai aturan round-robin.
        L mungkin menjadi kosong.
 */
void DeleteRR (List *L, infotype TQ);

/* 
 * Average
 * Menghasilkan nilai rata-rata elemen L. L tidak kosong.
 */
float Average (List L);

int main() {
	int TQ = 0;
	do {
		scanf("%d", &TQ);
	} while (TQ <= 0);
	
	List list;
	CreateEmpty(&list);
	
	char cmd[2];
	int x;
	scanf("%s", cmd);
	while (cmd[0] != 'F') {
		switch (cmd[0]) {
			case 'A':
				scanf("%d", &x);
				if (x > 0)
					InsVFirst(&list, x);
				break;
			case 'D':
				DeleteRR(&list, TQ);
				break;
			default:
				printf("Kode salah\n");
				break;
		}
		scanf("%s", cmd);
	}
	
	if (IsEmpty(list))
		printf("Proses selesai\n");
	else
		printf("%.2f\n", Average(list));
}

void DeleteRR (List *L, infotype TQ) {
	if (!IsEmpty(*L)) {
		address last = First(*L);
		while (Next(last) != First(*L))
			last = Next(last);
		
		if (Info(last) > TQ) {
			printf("%d\n", TQ);
			Info(last) -= TQ;
			First(*L) = last;
		} else {
			printf("%d\n", Info(last));
			infotype dummy; DelVLast(L, &dummy);
		}
	} else
		printf("List kosong\n");
}

float Average (List L) {
	address i = First(L);
	infotype sum = 0;
	int n = 0;
	do {
		sum += Info(i);
		n++;
		i = Next(i);
	} while (i != First(L));
	return (float) sum / (float) n;
}
