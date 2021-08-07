#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>

using namespace std;

int N, L, R, cnt;
bool flag;
int A[50][50];
bool visit[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void move(int x, int y) {
    visit[x][y] = true;
    set<pair<int, int>> s;
    queue<pair<int, int>> q;
    int sum = A[x][y];
    q.push({ x, y });
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        visit[p.first][p.second] = true;
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
                int gap = abs(A[p.first][p.second] - A[nx][ny]);
                if (gap >= L && gap <= R) {
                    visit[nx][ny] = true;
                    q.push({ nx, ny });
                    s.insert({ nx, ny });
                    sum += A[nx][ny];
                    flag = true;
                }
            }
        }
    }
    if (!flag) return;
    s.insert({ x, y });
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        pair<int, int> p = *iter;
        A[p.first][p.second] = sum / s.size();
    }
}

int main() {
    scanf("%d%d%d", &N, &L, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    while (true) {
        flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j]) continue;
                move(i, j);
            }
        }
        if (!flag) break;
        cnt++;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visit[i][j] = false;
    }
    printf("%d", cnt);
}

/*
문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.

오늘부터 인구 이동이 시작되는 날이다.

인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)

둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)

인구 이동이 발생하는 일수가 2,000번 보다 작거나 같은 입력만 주어진다.

출력
인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.

예제 입력 1 
2 20 50
50 30
20 40
예제 출력 1 
1
초기 상태는 아래와 같다.



L = 20, R = 50 이기 때문에, 모든 나라 사이의 국경선이 열린다. (열린 국경선은 점선으로 표시)



연합은 하나 존재하고, 연합의 인구는 (50 + 30 + 20 + 40) 이다. 연합의 크기가 4이기 때문에, 각 칸의 인구수는 140/4 = 35명이 되어야 한다. 



예제 입력 2 
2 40 50
50 30
20 40
예제 출력 2 
0
경계를 공유하는 나라의 인구 차이가 모두 L보다 작아서 인구 이동이 발생하지 않는다.

예제 입력 3 
2 20 50
50 30
30 40
예제 출력 3 
1
초기 상태는 아래와 같다.



L = 20, R = 50이기 때문에, 아래와 같이 국경선이 열린다.



인구 수는 합쳐져있는 연합의 인구수는 (50+30+30) / 3 = 36 (소수점 버림)이 되어야 한다.



예제 입력 4 
3 5 10
10 15 20
20 30 25
40 22 10
예제 출력 4 
2
예제 입력 5 
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
예제 출력 5 
3
*/
