/*
ID: qoob
LANG: C++
TASK: billboard
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int x;
	int y;
} coord_t;

typedef struct {
	coord_t bl;
	coord_t br;
	coord_t tl;
	coord_t tr;
} rect_t;

void create_rect(rect_t* ret, coord_t bl, coord_t tr) {
	coord_t br = {tr.x, bl.y};
	coord_t tl = {bl.x, tr.y};

	ret->bl = bl;
	ret->br = br;
	ret->tl = tl;
	ret->tr = tr;
}

// checks if the two rectangles intersect cleanly
// this is pure torture
int in_bounds(rect_t* a, rect_t* b) {
	if (a->bl.x <= b->bl.x) {
		// either coming in from right or covering
		if (a->bl.x >= b->bl.x && a->br.x <= b->br.x) {
			// b is covering a
		} else if (a->bl.x >= b->bl.x && !(a->br.x <= b->br.x)) {
			// b is coming in from right, but not coverimg
		}
	} else if (a->bl.x > b->bl.x) {
		// either coming in from left or covering
		if (a->bl.x <= b->br.x && a->br.x >= b->br.x) {
			// b is coming in from left
		}
		// TODO: check if b is covering a
	}
}

int calculate_intersection(rect_t* a, rect_t* b) {

}

int main() {
	FILE* in = fopen("billboard.in", "r");
	FILE* out = fopen("billboard.out", "w");

	rect_t boards[2];

	for (int i = 0; i < 2; i++) {
		coord_t bl;
		coord_t tr;

		fscanf(in, "%d %d %d %d\n", bl.x, bl.y, tr.x, tr.y);

		create_rect(&boards[i], bl, tr);
	}

	fclose(in);
	fclose(out);
}