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


public class teamworkSol {
    public static void main(String[] args) throws IOException {
        final String TASK = "teamwork";
        InputReader in = new InputReader(TASK);
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int n = in.nextInt();
        int k = in.nextInt();

        int[] A = new int[n];
        int[] dp = new int[n];

        for(int i = 0; i < n; i++) {
            A[i] = in.nextInt();
        }

        for(int i = 1; i < n; i++) {
            int mx = A[i];
            for(int j = i; j >= 0 && i+1-j <= k; j--) {
                mx = Math.max(mx, A[j]);
                //System.out.println(Arrays.toString(dp));
                if(j==0) dp[i] = Math.max(dp[i], mx * (i + 1 - j));
                else dp[i] = Math.max(dp[i], dp[j - 1] + mx * (i + 1 - j));
            }
            //System.out.println(Arrays.toString(dp));
        }

        out.println(dp[n-1]);

        out.close();
    }

    private static class InputReader
    {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(String fileName)
        {
            try
            {
                reader = new BufferedReader(new FileReader(new File(fileName + ".in")), 32768);
            } catch (Exception ex)
            {
                throw new NullPointerException("Input file does not exist! Put it in the project folder.");
            }
            tokenizer = null;
        }

        public String next()
        {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e)
                {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt()
        {
            return Integer.parseInt(next());
        }

        public double nextDouble()
        {
            return Double.parseDouble(next());
        }

        public long nextLong()
        {
            return Long.parseLong(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }

        /**
         * When you call next(), that entire line will be skipped.
         * No flushing buffers.
         * Doesn't work when you want to scan the remaining line.
         * @return entire line
         */
        public String nextLine()
        {
            String str = "";
            try
            {
                str = reader.readLine();
                tokenizer = null;
            } catch (IOException e)
            {
                throw new RuntimeException(e);
            }
            return str;
        }


    }
}
