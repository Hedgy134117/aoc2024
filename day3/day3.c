#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// REGEX? ☹️

int main() {
    FILE* f = fopen("day3.txt", "r");
    int n;

    char line[256];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), f);
    }

    fclose(f);

    return 0;
}