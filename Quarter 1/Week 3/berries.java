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

public class berries {
    public static void main(String[] args) throws IOException {
        final String TASK = "berries";
        InputReader in = new InputReader(TASK);
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int n = in.nextInt();
        int k = in.nextInt();

        int[] t = new int[n];

        for(int i = 0; i < n; i++) {
            t[i] = in.nextInt();
        }

        Arrays.sort(t);

        int lhs = 0;
        int rhs = k;

        int mid = -1;
        int search = -1;

        while (lhs <= rhs) {
            mid = lhs + (rhs-lhs)/2;
            search = checkK(t.clone(), mid, k);

            if(search < mid) {
                rhs = mid-1;
            } else if(search > mid) {
                lhs = mid+1;
            }
        }

        out.println(search);

        out.close();
    }

    public static int checkK(int[] t, int size, int k) {
        int[] arr = new int[k];
        int ind = arr.length-1;
        for(int i = t.length-1; i>=0;) {
            if(ind < 0) break;
            if(k <= t[i]) {
                arr[ind] = k;
                t[i] -= k;
                ind--;
            } else {
                arr[ind] = t[i];
                i--;
            }
        }

        int ret = 0;

        for(int i = 0; i < arr.length/2; i++) {
            ret += arr[i];
        }
        System.out.println(size + " " + Arrays.toString(arr));

        return ret;
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
