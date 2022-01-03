#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
char map[3072][6144];

void star(int y, int x, int size) {
    if (size == 3) {
        map[y][x] = '*';
        map[y + 1][x - 1] = '*';
        map[y + 1][x + 1] = '*';

        for (int i = 0; i < 5; i++)
            map[y + 2][x - 2 + i] = '*';
        return;
    }

    star(y, x, size / 2);
    star(y + size / 2, x - size / 2, size / 2);
    star(y + size / 2, x + size / 2, size / 2);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = ' ';

    star(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
