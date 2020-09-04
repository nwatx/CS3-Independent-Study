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


public class cerealSol {
    public static void main(String[] args) throws IOException {
        final String TASK = "cereal";
        InputReader in = new InputReader(TASK);
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int N = in.nextInt();
        int M = in.nextInt();

        int[][] cows = new int[100001][2];
        int[] occ = new int[100001];

        for(int i = 0; i < N; i++) {
            cows[i][0] = in.nextInt();
            cows[i][1] = in.nextInt();
        }

        int cnt = 0;
        int[] ans = new int[N];

        for(int i = N-1; i >= 0; i--) {
            int j = i;
            int pos = cows[i][0];

            while(true) {
                if(occ[pos] == 0) {
                    occ[pos] = j; //the cow at position pos takes cereal at j
                    cnt++;
                    break;
                } else if(occ[pos] < j) {
                    break;
                } else {
                    int k = occ[pos];
                    occ[pos] = j;
                    if (pos == cows[k][1]) {
                        break;
                    }
                    j = k;
                    pos = cows[k][1];
                }
            }
            ans[i] = cnt;
        }

        /* for(int remove = 0; remove < N; remove++) {
            int max = 0;
            Arrays.fill(cereal, true);
            for(int i = remove; i < N; i++) {
                if(cereal[cows[i][0]]) {
                    max++;
                    cereal[cows[i][0]] = false;
                }
                else if (cereal[cows[i][1]]) {
                    max++;
                    cereal[cows[i][1]] = false;
                }
            }
            out.println(max);
        } */

        //System.out.println(Arrays.toString(ans));

        for(int a : ans) {
            out.println(a);
        }

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
