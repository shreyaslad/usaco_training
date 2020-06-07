/*
ID: qoob
LANG: C++
TASK: blocks
*/

// http://www.usaco.org/index.php?page=viewproblem2&cpid=664

#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE* in = fopen("blocks.in", "r");
	FILE* out = fopen("blocks.out", "w");

	int n;
	fscanf(in, "%d", &n);

	fclose(in);
	fclose(out);
}