import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int cnt = 0;
        char[] arr = sc.next().toCharArray();
        boolean[] chk = new boolean[N];
        for(int i=1; i<N; i++){
            int j = i-1;
            while(j>=0 && arr[i]>arr[j] && cnt<K){
                if(!chk[j]) {
                	chk[j] = true; cnt++;
                }
                j--;
            }
            
            if(cnt == K) break;
        }
        
        while(cnt < K) {
        	int idx = 0, min = 10;
        	for(int i=0; i<N; i++) {
        		if(!chk[i] && arr[i]-'0' < min) {
        			idx = i; min = arr[i]-'0';
        		}
        	}
        	chk[idx] = true; cnt++;
        }
        
        StringBuilder ans = new StringBuilder("");
        for(int i=0; i<N; i++)
            if(!chk[i]) ans.append(arr[i]);
        System.out.println(ans.toString());
    }
}

/*
문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

예제 입력 1 
4 2
1924
예제 출력 1 
94
예제 입력 2 
7 3
1231234
예제 출력 2 
3234
예제 입력 3 
10 4
4177252841
예제 출력 3 
775841
오류 발견 테스트케이스
10 5
2938401920
*/
