/*
 * Author
 * Nama : Jauhar Arifin
 * NIM : 13515049
 * File : mstack.c
 * Tanggal : 3 November 2016
 */

#include <stdio.h>
#include "boolean.h"
#include "stacklist.h"

int main() {
	// Kamus
	Stack stack;
	boolean valid = true;
	char c;
	int dummy;
	
	// Inisialisasi stack
	CreateEmpty(&stack);
	
	// Mensimulasikan dengan melakukan push dan pop dalam stack
	c = (char) getchar();
	while (valid && c > EOF) {
		if (c == '}' && IsEmpty(stack))
			valid = false;
		else if (c == '{')
			Push(&stack, 1);
		else if (c == '}')
			Pop(&stack, &dummy);
		c = (char) getchar();
	}
	
	// Jika stack kosong, berarti valid
	if (valid)
		valid = IsEmpty(stack);
	
	// Mencetak hasil
	if (valid)
		printf("ok\n");
	else
		printf("salah\n");
	
	return 0;
}
