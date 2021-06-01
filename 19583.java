import java.util.*;
import java.io.*;

public class Main{
    static int ans = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Boolean> list = new HashMap<String, Boolean>();
        StringTokenizer stk = new StringTokenizer(br.readLine(), (": "));
        int start = Integer.parseInt(stk.nextToken())*100+Integer.parseInt(stk.nextToken());
        int end = Integer.parseInt(stk.nextToken())*100+Integer.parseInt(stk.nextToken());
        int fin = Integer.parseInt(stk.nextToken())*100+Integer.parseInt(stk.nextToken());
        String input = null;
        while((input = br.readLine()) != null){
            stk = new StringTokenizer(input, ": ");
            int t = Integer.parseInt(stk.nextToken())*100+Integer.parseInt(stk.nextToken());
            String s = stk.nextToken();
            if(t<=start){
                if(!list.containsKey(s)) list.put(s, false);
            } else if(t>=end && t<=fin){
                if(list.containsKey(s) && list.get(s)==false){
                    list.replace(s, true); ans++;
                }
            } else if(t>fin) break;
        }
        System.out.println(ans);
    }
}
