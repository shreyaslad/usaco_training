/*
ID: qoob
LANG: C++
TASK: shuffle
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE* in = fopen("shuffle.in", "r");
	FILE* out = fopen("shuffle.out", "w");

	int n;
	fscanf(in, "%d\n", &n);

	int a[n + 1];
	int cows[n + 1];
	int disp[n + 1];
	
	for (int i = 1; i <= n; i++) {
		fscanf(in, "%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
		fscanf(in, "%d", &cows[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			disp[j] = cows[a[j]];
		}

		for (int j = 0; j <= n; j++) {
			cows[j] = disp[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		fprintf(out, "%d\n", cows[i]);
	}
}