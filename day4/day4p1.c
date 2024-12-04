#include <stdio.h>

#define n 140
#define lineN 140
char grid[n][lineN];
int total = 0;

char get_next_letter(char letter) {
    switch (letter) {
        case 'X':
            return 'M';
        case 'M':
            return 'A';
        case 'A':
            return 'S';
    }
    return '\0';
}

void search(int x, int y, char search_letter, int x_inc, int y_inc) {
    if (grid[y][x] != search_letter || y >= n || x >= lineN || y < 0 || x < 0) {
        return;
    }

    if (grid[y][x] == search_letter) {
        if (search_letter == 'S') {
            total++;
            return;
        }

        char nextLetter = get_next_letter(search_letter);
        search(x + x_inc, y + y_inc, nextLetter, x_inc, y_inc);
    }
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
            search(x, y, 'X', -1, -1);
            search(x, y, 'X', 0, -1);
            search(x, y, 'X', 1, -1);
            search(x, y, 'X', -1, 0);
            search(x, y, 'X', 1, 0);
            search(x, y, 'X', -1, 1);
            search(x, y, 'X', 0, 1);
            search(x, y, 'X', 1, 1);
        }
    }

    printf("%d\n", total);

    fclose(f);

    return 0;
}