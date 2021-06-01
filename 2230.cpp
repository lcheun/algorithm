#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int arr[100000];

int result() {
    int l = 0, r = 1, gap = 2000000001;
    while (r >= l && r < N) {
        if (arr[r] - arr[l] < M) {
            r++; continue;
        }
        if (arr[r] - arr[l] == M) {
            gap = M; break;
        }
        if (gap > arr[r] - arr[l]) gap = arr[r] - arr[l];
        l++;
    }
    return gap;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    printf("%d", result());
}
