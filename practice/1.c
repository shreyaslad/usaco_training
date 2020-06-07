/*
ID: slad0711
LANG: C
TASK: test
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE* in = fopen("test.in", "r");
	FILE* out = fopen("test.out", "w");

	int a, b;
	fscanf(in, "%d %d", &a, &b);
	fprintf(out, "%d\n", a + b);

	exit(0);
}
