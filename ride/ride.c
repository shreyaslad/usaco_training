/*
ID: slad0711
LANG: C
PROG: ride
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

int get_pos(char c) {
	return c - 'A' + 1;
}

int main() {
	FILE* in = fopen("ride.in", "r");
	FILE* out = fopen("ride.out", "w");

	char buffer[255];

	int nums[2] = {1, 1};

	for (int i = 0; i < 2; i++) {
		fgets(buffer, 255, in);
		printf("%s", buffer);

		for (int j = 0; j < strlen(buffer) - 1; j++) {
			nums[i] *= get_pos(buffer[j]);
		}
	}

	if ((nums[0] % 47) == (nums[1] % 47)) {
		fprintf(out, "GO\n");
	} else {
		fprintf(out, "STAY\n");
	}

	fclose(in);
	fclose(out);
}
