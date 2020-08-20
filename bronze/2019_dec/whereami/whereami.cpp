#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <set>
#include <string>

int check_k(const char* str,
            const int   n,
            const int   k) {

    std::set<std::string> s;
    std::string str_cpy(str);

    for (int i = 0; i <= (n - k); i++) {
        if (s.count(str_cpy.substr(i, k))) {
            return 1;
        }

        s.insert(str_cpy.substr(i, k));
    }

    return 0;
}

int main() {
    FILE* in = fopen("whereami.in", "r");
    FILE* out = fopen("whereami.out", "w");

    int n;
    fscanf(in, "%d\n", &n);

    char* str = (char *)malloc(n);
    fscanf(in, "%s", str);

    int k = 1;

    while (check_k(str, n, k)) {
        k++;
    }

    fprintf(out, "%d\n", k);

    fclose(in);
    fclose(out);

    return 0;
}
