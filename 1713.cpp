#include <stdio.h>
#include <queue>
#include <tuple>
#define tp tuple<int, int, int>

using namespace std;

int N, T, clk;
bool exist[101];

struct cmp {
    bool operator()(tp a, tp b) {
        if (get<1>(a) == get<1>(b)) {
            return get<2>(a) > get<2>(b);
        }
        else return get<1>(a) > get<1>(b);
    }
};

int main() {
    scanf("%d %d", &N, &T);
    priority_queue<tp, vector<tp>, cmp> pq;
    for (int i = 0; i < T; i++) {
        int s;
        scanf("%d", &s);
        if (!exist[s]) {
            exist[s] = true;
            if (pq.size() == N) {
                int num, cnt, time;
                tie(num, cnt, time) = pq.top(); pq.pop();
                exist[num] = false;
            }
            pq.push(make_tuple(s, 1, clk));
        }
        else {
            queue<tp> q;
            while (true) {
                int num, cnt, time;
                tie(num, cnt, time) = pq.top(); pq.pop();
                if (num == s) {
                    q.push(make_tuple(num, cnt + 1, time));
                    break;
                }
                else
                    q.push(make_tuple(num, cnt, time));
            }
            while (!q.empty()) {
                pq.push(q.front()); q.pop();
            }
        }
        clk++;
    }
    for (int i = 1; i < 101; i++)
        if (exist[i]) printf("%d ", i);
}
