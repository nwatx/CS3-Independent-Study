/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wanggda1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.StringTokenizer;


public class pails {
    public static void main(String[] args) throws IOException {
        final String TASK = "pails";
        InputReader in = new InputReader(TASK);
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int x = in.nextInt();
        int y = in.nextInt();
        int k = in.nextInt();
        int m = in.nextInt();

        boolean[][] can = new boolean[x+1][y+1];
        can[0][0] = true;

        for(int op = 0; op < k; op++) {
            boolean[][] next = new boolean[x+1][y+1];

            for(int i = 0; i < can.length; i++) {
                for(int j = 0; j < can[i].length; j++) {
                    if(!can[i][j]) continue;
                    next[i][j] = true;
                    next[0][j] = true;
                    next[x][j] = true;
                    next[i][0] = true;
                    next[i][y] = true;
                    int moveRight = Math.min(i,y-j);
                    next[i-moveRight][j+moveRight] = true;
                    int moveLeft = Math.min(x-i,j);
                    next[i+moveLeft][j-moveLeft] = true;
                }
            }
            can=next;
        }

        int ret = Integer.MAX_VALUE;

        for(int i = 0; i < can.length; i++) {
            for(int j = 0; j < can[i].length; j++) {
                if(!can[i][j]) {
                    continue;
                }

                ret = Math.min(ret, Math.abs(i + j - m));
            }
        }

        out.println(ret);

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
