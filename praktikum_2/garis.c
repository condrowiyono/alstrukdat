#include "garis.h"
#include "point.h"
#include "boolean.h"
#include "stdio.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L) {
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L) {
	POINT p,q;

	do {
		BacaPOINT(&p);
		BacaPOINT(&q);
		if (EQ(p,q))
			printf("Garis tidak valid\n");
	} while (EQ(p,q));

	MakeGARIS(p,q,L);
}

void TulisGARIS (GARIS L) {
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
}

float PanjangGARIS (GARIS L) {
	return Panjang(PAwal(L), PAkhir(L));
}

float Gradien (GARIS L) {
	POINT p1 = PAwal(L);
	POINT p2 = PAkhir(L);
	
	return (Ordinat(p2) - Ordinat(p1))/(Absis(p2) - Absis(p1));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY) {
	Geser (&PAwal(*L), deltaX, deltaY);
	Geser (&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2) {
	return Gradien(L1)*Gradien(L2) == -1;
}

boolean IsSejajar (GARIS L1, GARIS L2) {
	return Gradien(L1) == Gradien(L2);
}
