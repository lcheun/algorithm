#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int N, M, s, ans = 64;
int room[8][8];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> CCTV;

void copy(int tmp1[8][8], int tmp2[8][8]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp1[i][j] = tmp2[i][j];
}

void check(int ex[][8], int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while (true) {
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || ex[nx][ny] == 6)
            return;
        else if (ex[nx][ny] == 0)
            ex[nx][ny] = 7;
        nx += dx[dir];
        ny += dy[dir];
    }
}

void simul(int cnt, int ex[][8]) {
    if (cnt == s) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (ex[i][j] == 0) cnt++;

        if (cnt < ans) ans = cnt;
        return;
    }
    pair<int, int> p = CCTV[cnt];
    switch (room[p.first][p.second]) {
    case 1:
        for (int i = 0; i < 4; i++) {
            int tmp[8][8];
            copy(tmp, ex);
            check(tmp, p.first, p.second, i);
            simul(cnt + 1, tmp);
        }
        break;
    case 2:
        for (int i = 0; i < 4; i+=2) {
            int tmp[8][8];
            copy(tmp, ex);
            for(int j=i; j<i+2; j++)
                check(tmp, p.first, p.second, j);
            simul(cnt + 1, tmp);
        }
        break;
    case 3:
        for (int i = 0; i < 2; i++) {
            int tmp1[8][8];
            copy(tmp1, ex);
            check(tmp1, p.first, p.second, i);
            for (int j = 2; j < 4; j++) {
                int tmp2[8][8];
                copy(tmp2, tmp1);
                check(tmp2, p.first, p.second, j);
                simul(cnt + 1, tmp2);
            }
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++) {
            int tmp[8][8];
            copy(tmp, ex);
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                check(tmp, p.first, p.second, j);
            }
            simul(cnt + 1, tmp);
        }
        break;
    case 5:
        for (int i = 0; i < 4; i++)
            check(ex, p.first, p.second, i);
        simul(cnt + 1, ex);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &room[i][j]);
            if (room[i][j] != 0 && room[i][j] != 6)
                CCTV.push_back(pair<int, int>(i, j));
        }
    }
    s = CCTV.size();
    simul(0, room);
    printf("%d", ans);
}
