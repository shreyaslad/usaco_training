/*
ID: qoob
LANG: C++
TASK: homework
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	FILE* in = fopen("homework.in", "r");
	FILE* out = fopen("homework.out", "w");

	int n;
	fscanf(in, "%d", &n);

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int cur;
		fscanf(in, "%d", &cur);
		v.push_back(cur);
	}

	int total[n - 2];

	for (int i = 0; i < n - 2; i++) {
		vector<int> vcpy = v;
		sort(vcpy.begin(), vcpy.end());

		total[i] = accumulate(vcpy.begin() + 1, vcpy.end(), 0) / (vcpy.size() - 1);

		v.erase(v.begin());
	}

	int greatest = 0;
	int idx = 0;

	for (int i = 0; i < n - 2; i++) {
		if (greatest <= total[i]) {
			greatest = total[i];
			idx = i;
		}
	}

	fprintf(out, "%d", idx);

	fclose(in);
	fclose(out);
}