#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **prefM = malloc(n * sizeof(int *));
    int **prefW = malloc(n * sizeof(int *));
    int *matchM = malloc(n * sizeof(int));
    int *matchW = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        prefM[i] = malloc(n * sizeof(int));
        prefW[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &prefM[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &prefW[i][j]);

    for (int i = 0; i < n; i++)
        scanf("%d", &matchM[i]);

    for (int i = 0; i < n; i++)
        matchW[matchM[i]] = i;

    int stable = 1;

    for (int m = 0; m < n && stable; m++) {
        for (int w = 0; w < n; w++) {

            if (matchM[m] == w)
                continue;

            if (prefM[m][w] < prefM[m][matchM[m]]) {

                if (prefW[w][m] < prefW[w][matchW[w]]) {
                    stable = 0;
                    break;
                }
            }
        }
    }

    if (stable)
        printf("Устойчивое\n");
    else
        printf("Неустойчивое\n");

    for (int i = 0; i < n; i++) {
        free(prefM[i]);
        free(prefW[i]);
    }
    free(prefM);
    free(prefW);
    free(matchM);
    free(matchW);

    return 0;
}
