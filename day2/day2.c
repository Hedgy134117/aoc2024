#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int report[], int maxReportN) {
    int isIncreasing = report[1] > report[0];
    int isSafe = 1;
    for (int i = 1; i < maxReportN && isSafe; i++) {
        if (report[i] == -1) {
            break;
        }

        int diff = abs(report[i] - report[i - 1]);
        if (!(diff > 0 && diff < 4)) {
            isSafe = 0;
        }

        if (isIncreasing && !(report[i] > report[i - 1])) {
            isSafe = 0;
        } else if (!isIncreasing && !(report[i] < report[i - 1])) {
            isSafe = 0;
        }
    }

    return isSafe;
}

int main() {
    FILE* f = fopen("day2.txt", "r");
    int n = 1000;
    int maxReportN = 8;

    int reports[n][maxReportN + 1];

    char line[256];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), f);

        int j = 0;
        char* tok = strtok(line, " ");
        reports[i][j] = atoi(tok);
        while (1) {
            j++;
            tok = strtok(NULL, " ");
            if (tok == NULL) {
                break;
            }
            reports[i][j] = atoi(tok);
        }
        reports[i][j] = -1;  // this is almost certainly a memory leak
    }

    int nSafe = 0;
    for (int i = 0; i < n; i++) {
        int safe = isSafe(reports[i], maxReportN);

        // If not safe, check every report until the first safe report with skipping some level
        for (int skip = 0; !safe && skip < maxReportN && reports[i][skip] != -1; skip++) {
            int report[maxReportN];
            report[maxReportN - 1] = -1;

            int skipped = 0;
            for (int copy = 0; copy < maxReportN; copy++) {
                if (copy == skip) {
                    skipped = 1;
                    continue;
                }

                if (skipped) {
                    report[copy - 1] = reports[i][copy];
                } else {
                    report[copy] = reports[i][copy];
                }
            }

            safe = isSafe(report, maxReportN);
        }

        nSafe += safe;
    }

    printf("%d\n", nSafe);
    fclose(f);

    return 0;
}