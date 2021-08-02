#include <stdio.h>
#include <queue>

using namespace std;

int R, C, N, cnt = 2;
int time[200][200];
char map[200][200];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
    scanf("%d %d %d", &R, &C, &N);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf(" %c", &map[i][j]);

    while (cnt <= N) {
        if (cnt % 2 == 0) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (map[i][j] == '.') {
                        map[i][j] = 'O';
                        time[i][j] = cnt;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (map[i][j] == 'O' && time[i][j] == cnt - 3) {
                        for (int k = 0; k < 4; k++) {
                            map[i][j] = '.'; time[i][j] = 0;
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] == 'O' && time[nx][ny] > cnt-3) {
                                map[nx][ny] = '.'; time[nx][ny] = 0;
                            }
                        }
                    }
                }
            }
        }
        cnt++;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
