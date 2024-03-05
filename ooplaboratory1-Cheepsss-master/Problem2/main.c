#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif
// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 




int main() {
	int n = 24;
	int aux;
	int a1, a2;
	int l;
	//i k l j

	for (int i = 9; i >= 3; i--) {
		for (int j = 6; j >= 0; j--) {
			aux = (n - i - j) / 2;
			a1 = aux % 2;
			a2 = a1 -1;
			if (aux + a2 > j && aux + a1 - a2 < i) {
				for (int k = i - 1; k > j + 1; k--) {
					l = n - i - j - k;
					if (l >j && l < k) {
						printf("[%d,%d,%d,%d]\n", i, k, l, j);
					}
				}
			}
		}
	}


	return 0;
}

