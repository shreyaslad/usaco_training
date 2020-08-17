/*
ID: qoob
LANG: C++
TASK: diamond
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cmpfunc(const void* a, const void* b) {
	return (*(int *)a) - (*(int *)b);
}

int main() {
	FILE* in = fopen("diamond.in", "r");
	FILE* out = fopen("diamond.out", "w");

	int n, k;
	fscanf(in, "%d %d", &n, &k);

	int arr[n];
	int acc = 0;

	for (int i = 0; i < n; i++) {
		fscanf(in, "%d\n", &arr[i]);
	}

	// this can probably be removed
	qsort(arr, n, sizeof(int), cmpfunc);

	for (int i = 0; i < n; i++) {
		int tmp = 0;

		for (int j = 0; j < n; j++) {
		// we must make sure arr[j] >= arr[j] because we're comparing
		// everything to every other thing
		// sorting does not matter at this point

		// the difference of the two numbers has to be less than or equal to k
		if ((max(arr[j], arr[i]) - min(arr[j], arr[i])) <= k && arr[j] >= arr[i])
			tmp++;
		}

		if (tmp > acc)
			acc = tmp; // we found the greater number of diamonds
	}

	// acc should now hold the greatest number of diamonds
	fprintf(out, "%d\n", acc);

	fclose(in);
	fclose(out);
}