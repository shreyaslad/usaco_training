/*
ID: slad0711
LANG: C
TASK: friday
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_leap_year(int year) {
	if (!(year % 100)) {
		if (!(year % 400)) {
			return 1;
		}
	} else if (!(year % 4)) {
		return 1;
	}

	return 0;
}

int main() {
	FILE* in = fopen("friday.in", "r");
	FILE* out = fopen("friday.out", "w");

	int64_t years;
	fscanf(in, "%ld", &years);
	
	int* dpm = malloc(sizeof(int) * 12);//{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int* tpm = malloc(sizeof(int) * 7); //{0, 0, 0, 0, 0, 0, 0};

	dpm[0] = 31;
	dpm[1] = 28;
	dpm[2] = 31;
	dpm[3] = 30;
	dpm[4] = 31;
	dpm[5] = 30;
	dpm[6] = 31;
	dpm[7] = 31;
	dpm[8] = 30;
	dpm[9] = 31;
	dpm[10] = 30;
	dpm[11] = 31;

	int64_t base = 1900;
	int64_t base_unix = -2208988800;

	for (int64_t i = 0; i < years; i++) {
		printf("Current year: %ld\n", base + i);
		if (is_leap_year(base + i)) {
			dpm[1] = 29;
		} else {
			dpm[1] = 28;
		}

		for (int j = 0; j < 12; j++) {
			printf("Day of week: %d\n", ((abs(base_unix) / 86400) + 4) % 7);
			tpm[i] += 1;

			base_unix += dpm[i] * 86400;
		}
	}

	for (int i = 0; i < 7; i++) {
		fprintf(out, "%d ", tpm[i]);
	}

	fclose(in);
	fclose(out);
}
