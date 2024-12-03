#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b) { return *((int*)a) > *((int*)b) ? 1 : -1; }

int main() {
    FILE* f = fopen("day1.txt", "r");
    int n = 1000;
    int maxNum = 99999;

    int a[n];
    int b[n];
    int bCount[maxNum + 1];

    char line[256];
    int i = 0;
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), f);
        a[i] = atoi(strtok(line, "   "));
        int val = atoi(strtok(NULL, "   "));
        b[i] = val;
        bCount[val] += 1;
    }

    qsort(a, sizeof(a) / sizeof(*a), sizeof(*a), comp);
    qsort(b, sizeof(b) / sizeof(*b), sizeof(*b), comp);

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += abs(a[i] * bCount[a[i]]);
    }

    printf("%d\n", total);

    fclose(f);
    return 0;
}