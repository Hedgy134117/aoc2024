#include <stdio.h>

#define n 140
#define lineN 140
char grid[n][lineN];
int total = 0;

void search(int x, int y) {
    if (grid[y][x] != 'A' || y - 1 < 0 || x - 1 < 0 || y + 1 >= n || x + 1 >= lineN) {
        return;
    }

    // Top Left - Bottom Right diagonal
    if (!((grid[y - 1][x - 1] == 'M' && grid[y + 1][x + 1] == 'S') ||
          (grid[y - 1][x - 1] == 'S' && grid[y + 1][x + 1] == 'M'))) {
        return;
    }

    // Top Right - Bottom Left diagonal
    if (!((grid[y - 1][x + 1] == 'M' && grid[y + 1][x - 1] == 'S') ||
          (grid[y - 1][x + 1] == 'S' && grid[y + 1][x - 1] == 'M'))) {
        return;
    }

    total++;
}

int main() {
    FILE* f = fopen("day4.txt", "r");

    char line[256];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), f);
        for (int j = 0; j < lineN; j++) {
            grid[i][j] = line[j];
        }
    }

    for (int y = 0; y < lineN; y++) {
        for (int x = 0; x < n; x++) {
            search(x, y);
        }
    }

    printf("%d\n", total);

    fclose(f);

    return 0;
}