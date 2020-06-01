/*
ID: qoob
LANG: C++
TASK: measurement
*/

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int day;
	char name[20];
	int change;
} entry_t;

typedef struct {
	char name[20];
	int gallons;
} cow_t;

int cmpfunc(const void* a, const void* b) {
	return ((entry_t *)a)->day - ((entry_t *)b)->day;
}

int main() {
	FILE* in = fopen("measurement.in", "r");
	FILE* out = fopen("measurement.out", "w");

	int cnt = 0;
	int base = 7;
	int greatest = base;

	int n;
	fscanf(in, "%d\n", &n);

	entry_t entries[n];
	cow_t cows[n];

	int i;
	for (i = 0; i < n; i++) {
		fscanf(in, "%d %s %d\n", &entries[i].day, entries[i].name, &entries[i].change);
		strncpy(cows[i].name, entries[i].name, 20);
		cows[i].gallons = base;
	}

	qsort(entries, n, sizeof(entry_t), cmpfunc);

	int get_cow(char* name) {
		int j;
		for (j = 0; j < n; j++) {
			if (!strncmp(cows[j].name, name, 20)) {
				return j;
			}
		}

		return -1;
	}

	for (i = 0; i < n; i++) {
		cows[get_cow(entries[i].name)].gallons += entries[i].change;
		if (cows[get_cow(entries[i].name)].gallons >= greatest) {
			greatest = cows[get_cow(entries[i].name)].gallons;
			cnt++;
		}
	}

	fprintf(out, "%d", cnt + 1);
}