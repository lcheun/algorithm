#include <stdio.h>

int N, cnt1 = 0, cnt2 = 0, cnt3 = 0;
int paper[2187][2187];

int check(int x, int y, int size) {
    int num = paper[x][y];
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (paper[i][j] != num) return 0;
    return 1;
}

void divide(int x, int y, int size) {
    if (size == 1 || check(x, y, size) == 1) {
        switch (paper[x][y]) {
        case -1: cnt1++; break;
        case 0: cnt2++; break;
        case 1: cnt3++;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            divide(x + i * size / 3, y + j * size / 3, size / 3);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &paper[i][j]);

    divide(0, 0, N);
    printf("%d\n%d\n%d", cnt1, cnt2, cnt3);
}

/*
문제
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

예제 입력 1 
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1
예제 출력 1 
10
12
11
*/
