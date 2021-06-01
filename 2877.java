import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder("");
        int K = sc.nextInt(); K++;
        while(K>1){
            if(K%2==0) sb.append("4");
            else sb.append("7");
            K/=2;
        }
        System.out.println(sb.reverse().toString());
        sc.close();
    }
}
