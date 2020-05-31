/*
ID: slad0711
LANG: C
TASK: friday
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int is_leap_year(uint64_t time) {
	if (!(time % 100))
		if (!(time % 400))
			return 1;
	else if (!(time % 4))
		return 1;

	return 0;
}

int main() {
	FILE* in = fopen("friday.in", "r");
	FILE* out = fopen("friday.out", "w");

	int years;
	fscanf(in, "%d", &years);

	uint64_t base_year = 1900;
	uint64_t time = 0;
	uint64_t day = 86400;

	uint64_t days[7] = { 0, 0, 0, 0, 0, 0, 0 };

	int days_per_year = 365;

	for (int i = 0; i < (years - 1); i++) {
		if (is_leap_year)
			days_per_year = 366;
		else
			days_per_year = 365;

		for (int i = 0; i < days_per_year; i++) {
			time += day;
		}
	}
}