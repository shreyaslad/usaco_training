/*
ID: slad0711
LANG: C
TASK: gift1
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	FILE* in = fopen("gift1.in", "r");
	FILE* out = fopen("gift1.out", "w");

	int np;
	fscanf(in, "%d\n", &np);

	printf("NP: %d\n", np);

	char names[np][20];
	int money[np];

	printf("Names: ");

	for (int i = 0; i < np; i++) {
		fscanf(in, "%s\n", names[i]);
		money[i] = 0;

		printf("%s, ", names[i]);
	}

	printf("\n");

	int get_idx(char* name) {
		int name_len = strlen(name);

		for (int i = 0; i < np; i++) {
			if (!strncmp(names[i], name, name_len)) {
				return i;
			}
		}

		return -1;
	}

	while (1) {
		char gift_giver[1][20];
		fscanf(in, "%s\n", gift_giver[0]);

		int amount;
		int n;

		if (fscanf(in, "%d %d\n", &amount, &n) == -1) {
			break; // EOF
		}

		printf("%s gives %d to %d people: ", gift_giver[0], amount, n);

		for (int i = 0; i < n; i++) {
			char current[20];
			fscanf(in, "%s\n", current);

			if (amount)
				money[get_idx(current)] += amount / n;

			printf("%s ", current);
		}

		printf("\n\n");

		money[get_idx(gift_giver[0])] -= amount;

		if (amount)
			money[get_idx(gift_giver[0])] += (amount % n);
	}

	for (int i = 0; i < np; i++) {
		fprintf(out, "%s %d\n", names[i], money[i]);
	}

	return 0;
}
