#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//
// This program takes as command line a single integer value which represents a year and then computes and displays the Easter date for that year
// The algorithm for computing the catholic Easter date is the following :
//	A = year mod 19
//	B = year mod 4
//	C = year mod 7
//	D = (19 * A + 24) mod 30
//	E = (2 * B + 4 * C + 6 * D + 5) mod 7 where mod is the remainder of the division of x to y.
// Easter day is then(22 + E + D) March.Note that this formula can give a date from April if 22 + E + D > 31; also take this case into account!
// The program will display the Easter date in the following way "The Easter day is 02 April " (use trailing zeros for the day if it is less than 10)
int main(int argc, char* argv[]) {
	struct date{
		int year;
		char month[30];
		int day;
	};
	struct date d1;
	int A, B, C, D, E, ed;
	printf("Current year: ");
	scanf("%d", &d1.year);
	if (d1.year < 1876) {
		printf("Invalid input, the year should be greater or equal to 1876");
	}
	else {
		A = d1.year % 19;
		B = d1.year % 4;
		C = d1.year % 7;
		D = (19 * A + 24) % 30;
		E = (2 * B + 4 * C + 6 * D + 5) % 7;
		ed = 22 + E + D;
		if (ed <= 31) {
			strcpy(d1.month, "March");
		}
		else {
			strcpy(d1.month, "April");
		}
		d1.day = ed % 31;
		if (d1.day < 10) {
			printf("In year %d the Easter date is %s 0%d", d1.year, d1.month, d1.day);
		}
		else {
			printf("In year %d the Easter date is %s %d", d1.year, d1.month, d1.day);
		}
	}

	return 0;
}

