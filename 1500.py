S, K = map(int, input().split())
q = S // K
r = S % K
ans = 1
while K > 0:
    if r > 0:
        ans *= q + 1
        r -= 1
    else:
        ans *= q
    K -= 1
print(ans)

'''
문제
세준이는 정수 S와 K가 주어졌을 때, 합이 S인 K개의 양의 정수를 찾으려고 한다. 만약 여러개일 경우 그 곱을 가능한 최대로 하려고 한다.

가능한 최대의 곱을 출력한다.

만약 S=10, K=3이면, 3,3,4는 곱이 36으로 최대이다.

입력
첫째 줄에 두 수 S와 K가 주어진다. K는 20보다 작거나 같고, S는 100보다 작거나 같으며 K보다 크거나 같다.

출력
첫째 줄에 정답을 출력한다. 답은 9223372036854775807보다 작다.

예제 입력 1 
10 3
예제 출력 1 
36
예제 입력 2 
10 1
예제 출력 2 
10
예제 입력 3 
10 10
예제 출력 3 
1
예제 입력 4 
13 8
예제 출력 4 
32
예제 입력 5 
7 2
예제 출력 5 
12
'''
