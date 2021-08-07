import java.util.Scanner;
import java.util.Arrays;

public class Main{
	static class pair implements Comparable{
		long val = 0;
		boolean first = false;
		
		public int compareTo(Object obj) {
			pair p = (pair) obj;
			if(this.val>p.val) return 1;
			else return -1;
		}
	}
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] arr = new String[N];
        for(int i=0; i<N; i++){
            arr[i] = sc.next();
        }
        
        pair[] count = new pair[10];
        for(int i=0; i<10; i++)
        	count[i] = new pair();
        
        for(int i=0; i<N; i++){
            char[] temp = arr[i].toCharArray();
            for(int j=0; j<arr[i].length(); j++){
            	int al = temp[j]-'A';
            	if(j==0) count[al].first = true;
            	count[al].val += power(10, temp.length-j-1);
            }
        }
        
        Arrays.sort(count);
        if(count[0].first) {
        	int chk = 1;
        	while(count[chk].first)
        		chk++;
        	for(int i=chk; i>0; i--) {
        		pair swap = count[i];
        		count[i] = count[i-1];
        		count[i-1] = swap;
        	}
        }
        
        long sum=0, num=9;
        for(int i=9; i>=0; i--) {
        	sum += count[i].val*num;
        	num--;
        }
        System.out.println(sum);
        sc.close();
    }
    
    public static long power(int b, int e){
    	long num=1;
        for(int i=0; i<e; i++)
            num *= b;
        return num;
    }
}

/*
문제
N개의 숫자가 주어진다. 이 숫자는 모두 자연수이고, 알파벳 A부터 J가 자리수를 대신해서 쓰여 있다. 이 알파벳은 모두 한 자리를 의미한다. 그리고, 각 자리수는 정확하게 알파벳 하나이다. 0으로 시작하는 숫자는 없다. 이때, 가능한 숫자의 합 중 최댓값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 각 숫자가 주어진다. 숫자의 길이는 최대 12이다.

적어도 한 알파벳은 숫자의 가장 처음에 주어지지 않는다.

출력
첫째 줄에 합의 최댓값을 출력한다.

예제 입력 1 
2
ABC
BCA
예제 출력 1 
1875
*/
