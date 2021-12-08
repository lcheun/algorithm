import java.io.*;

public class Main{
    static int T;
    static StringBuilder ans = new StringBuilder();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; i++){
            char[] func = br.readLine().toCharArray();
            int n = Integer.parseInt(br.readLine());
            String[] x = br.readLine().split("\\]|,|\\[");
            int start = 0, end = 0;
            boolean isFront = true;
            for(char c : func){
                if(c == 'R') isFront = !isFront;
                else if(isFront) start++;
                else end++;
            }
            
            if(start + end > n) ans.append("error");
            else if (isFront) {
                ans.append("[");
                for(int j = start + 1; j <= n - end; j++){
                    ans.append(x[j]);
                    if(j == n-end);
                    else ans.append(",");
                }
                ans.append("]");
            } else {
                ans.append("[");
                for(int j = n - end; j > start; j--){
                    ans.append(x[j]);
                    if(j == start + 1);
                    else ans.append(",");
                }
                ans.append("]");
            }
            
            ans.append("\n");
        }
        
        System.out.println(ans.toString());
    }
}
