/*
ID: qoob
LANG: C++
TASK: billboard
*/

/*
Theory
------
Calculate and compare the bounds of two rectangles
Draw a new rectangle that fits in the bounds of the other
Calculate the intersection area
Rinse and repeat
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int x1, y1, x2, y2;
} rectangle_t;


int main() {
	FILE* in = fopen("billboard.in", "r");
	FILE* out = fopen("billboard.out", "w");

	rectangle_t a, b, c;

	fscanf(in, "%d %d %d %d\n", a.x1, a.x2, a.y1, a.y2);
	fscanf(in, "%d %d %d %d\n", b.x1, b.x2, b.y1, b.y2);
	fscanf(in, "%d %d %d %d\n", c.x1, c.x2, c.y1, c.y2);

	fclose(in);
	fclose(out);
}
