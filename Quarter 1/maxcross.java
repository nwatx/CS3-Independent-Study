/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wanggda1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class maxcross {
    public static void main(String[] args) throws IOException {
        final String TASK = "maxcross";
        BufferedReader br = new BufferedReader(new FileReader(new File(TASK + ".in")));
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        StringTokenizer tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int k = Integer.parseInt(tk.nextToken());
        int b = Integer.parseInt(tk.nextToken());

        boolean[] lights = new boolean[n];

        for(int i = 0; i < b; i++) {
            int in = Integer.parseInt(br.readLine())-1;
            lights[in] = true;
        }

        int[] prefix = new int[n+1];

        for(int i = 1; i < n+1; i++) {
            prefix[i] = prefix[i-1] + (lights[i-1] ? 1 : 0);
        }

        int min = Integer.MAX_VALUE;

        for(int i = 1; i < n-k; i++) {
            min = Math.min(prefix[i+k]-prefix[i], min);
        }

        //System.out.println(Arrays.toString(lights));
        //System.out.println(Arrays.toString(prefix));
        out.println(min);

        out.close();
    }
}
