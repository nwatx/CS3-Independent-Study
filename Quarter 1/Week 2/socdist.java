/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wanggda1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class socdist {
    public static void main(String[] args) throws IOException {
        final String TASK = "socdist";
        InputReader in = new InputReader(TASK);
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int n = in.nextInt();
        int m = in.nextInt();
        long[][] pairs = new long[n][2];

        long lhs = 0;
        long rhs = Long.MAX_VALUE;

        for(int i = 0; i < m; i++) {
            pairs[i][0] = in.nextInt();
            pairs[i][1] = in.nextInt();
        }

        Arrays.sort(pairs, (o1, o2) -> (int) (o1[0] - o2[0]));

        long d = 1;

        while(lhs <= rhs) {
            long mid = (lhs + rhs)/2;
            //System.out.println(mid);

            boolean valid = ok(pairs, mid, n);

            if(valid) {
                lhs = mid + 1;
                d = Math.max(d, mid);
            } else {
                rhs = mid-1;
            }
        }

        out.println(d);


        //System.out.println(checkD(pairs, 2, n));

        out.close();
    }

    private static boolean ok(long[][] pairs, long d, int n) {
        long prev = Long.MIN_VALUE;

        long cnt = 0;
        for (long[] pair : pairs) {
            while (Math.max(prev + d, pair[0]) <= pair[1]) {
                prev = Math.max(prev + d, pair[0]);
                cnt++;
                if (cnt >= n) break;
            }
            if (cnt >= n) break;
        }

        return (cnt >= n);
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
