#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int LCS[1001][1001];
int sol[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                sol[i][j] = 1;
            }
            else {
                if (LCS[i][j - 1] > LCS[i - 1][j]) {
                    LCS[i][j] = LCS[i][j - 1];
                    sol[i][j] = 2;
                }
                else {
                    LCS[i][j] = LCS[i - 1][j];
                    sol[i][j] = 3;
                }
            }
        }
    }
    int ans = LCS[l1][l2];
    cout << ans << "\n";
    if (ans != 0) {
        string res;
        while (sol[l1][l2] != 0) {
            if (sol[l1][l2] == 1) {
                res += s1[--l1];
                l2--;
            }
            else if (sol[l1][l2] == 2) {
                l2--;
            }
            else if(sol[l1][l2]==3) {
                l1--;
            }
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }

}

/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4
ACAK
*/
