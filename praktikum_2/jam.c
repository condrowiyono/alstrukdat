/*
 * Author
 * Nama				: Jauhar Arifin
 * NIM				: 13515049
 * Tanggal		: Kamis, 1 September 2016
 * Nama file	: jam.c
 */

#include "jam.h"
#include "stdio.h"

/*
 * IsJAMValid
 * Mengambalikan nilai true jika kombinasi H,M,S adalah jam yang valid
 */
boolean IsJAMValid (int H, int M, int S) {
	return (H >= 0 && H < 24 && M >= 0 && M < 60 && S >= 0 && S < 60);
}

/*
 * MakeJAM
 * Membuat instance dari JAM baru menggunakan nilai HH,MM,SS
 * Prekondisi : HH, MM, SS valid untuk membentuk JAM
 */
JAM MakeJAM (int HH, int MM, int SS) {
	JAM jam;

	Hour(jam) = HH;
	Minute(jam) = MM;
	Second(jam) = SS;

	return jam;
}

/*
 * BacaJAM
 * Membaca nilai jam dari input user hingga user memberikan nilai jam yang valid
 * I.S. : J tidak terdefinisi
 * F.S. : J terdefinisi dan merupakan jam yang valid
 */
void BacaJAM (JAM * J) {
	int h, m, s;

	do {
		scanf("%d %d %d", &h, &m, &s);
		if (!IsJAMValid(h,m,s))
			printf("Jam tidak valid\n");
	} while (!IsJAMValid(h,m,s));

	*J = MakeJAM(h,m,s);
}

/*
 * TulisJAM
 * Menuliskan nilai jam dalam format HH:MM:SS ke standard output
 * I.S. : J sembarang
 * F.S. : Nilai J ditulis dg format HH:MM:SS
 */
void TulisJAM (JAM J) {
	printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
}

/*
 * JAMToDetik
 * Mengubah nilai jam menjadi detik dengan rumus 3600*H + 60*M + S
 */
long JAMToDetik (JAM J) {
	return Hour(J) * 3600 + Minute(J) * 60 + Second(J);
}

/*
 * DetikToJAM
 * Membuat instance JAM baru dari banyaknya detik yang diberikan
 * Jika detik melebihi satu hari, maka dikonversi terlebih dahulu agar tidak
 * melebihi sati hari dengan cara memodulo detik dengan 86400
 */
JAM DetikToJAM (long N) {
	N %= 86400;

	int h = N / 3600;
	int m = (N % 3600) / 60;
	int s = N % 60;

	return MakeJAM(h,m,s);
}

/*
 * JEQ
 * Mengembalikan nilai true jika J1 = J2, dan false jika sebaliknya
 */
boolean JEQ (JAM J1, JAM J2) {
	return Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2);
}

/*
 * JNEQ
 * Mengembalikan nilai true jika J1 != J2, dan false jika sebaliknya
 */
boolean JNEQ (JAM J1, JAM J2) {
	return !JEQ(J1, J2);
}

/*
 * JLT
 * Mengembalikan nilai true jika J1 < J2, dan false jika sebaliknya
 */
boolean JLT (JAM J1, JAM J2) {
	if (Hour(J1) == Hour(J2)) {
		if (Minute(J1) == Minute(J2))
			return Second(J1) < Second(J2);
		else
			return Minute(J1) < Minute(J2);
	} else
		return Hour(J1) < Hour(J2);
}

/*
 * JGT
 * Mengembalikan nilai true jika J1 > J2, dan false jika sebaliknya
 */
boolean JGT (JAM J1, JAM J2) {
	return !(JLT(J1,J2) || JEQ(J1,J2));
}

/*
 * NextDetik
 * Mengirim satu detik setelah J dan mengambalikannya dalam bentuk JAM
 */
JAM NextDetik (JAM J) {
	return NextNDetik(J, 1);
}

/*
 * NextDetik
 * Mengirim N detik setelah J dan mengambalikannya dalam bentuk JAM
 */
JAM NextNDetik (JAM J, int N) {
	return DetikToJAM((JAMToDetik(J) + N + 864000) % 86400);
}

/*
 * PrevDetik
 * Mengirim stau detik sebelum J dan mengambalikannya dalam bentuk JAM
 */
JAM PrevDetik (JAM J) {
	return NextNDetik(J, -1);
}

/*
 * PrevNDetik
 * Mengirim N detik sebelum J dan mengambalikannya dalam bentuk JAM
 */
JAM PrevNDetik (JAM J, int N) {
	return NextNDetik(J, -N);
}

/*
 * Durasi
 * Mengirim JAkh-JAw dlm Detik, dengan kalkulasi
 * Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw
 */
long Durasi (JAM JAw, JAM JAkh) {
	return (JAMToDetik(JAkh) - JAMToDetik(JAw) + 86400) % 86400;
}
