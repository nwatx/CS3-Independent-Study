/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wanggda1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.*;


public class milkvisits {
    static final int N = 100001;
    static Node[] graph = new Node[N];
    static boolean[] visited = new boolean[graph.length];
    static boolean temp = false;

    public static void main(String[] args) throws IOException {
        final String TASK = "milkvisits";
        InputReader in = new InputReader("6");
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        int n = in.nextInt();
        int m = in.nextInt();

        char[] a = in.next().toCharArray();

        for(int i = 0; i < a.length; i++) {
            graph[i] = new Node(a[i]);
        }

        for(int i = 0; i < n-1; i++) {
            int b = in.nextInt()-1;
            int c = in.nextInt()-1;

            graph[b].addNode(c);
            graph[c].addNode(b);
        }

        for(int i = 0; i < m; i++) {
            int s = in.nextInt()-1;
            int e = in.nextInt()-1;
            int v = in.nextChar();

            temp = false;
            visited = new boolean[graph.length];
            dfs(s, v, e, false);
            if(temp) {
                out.print(1);
            } else {
                out.print(0);
            }
        }

        out.println();

        out.close();
    }

    private static void dfs(int node, int s, int e, boolean sat) {
            visited[node] = true;
            if(graph[node].val == s) sat = true;
            if(node == e && sat) temp = true;

            for(int a : graph[node].vertices) {
                //check condition
                if(!visited[a]) {
                    dfs(a, s, e, sat);
                }
            }
    }
    private static class Node {
        List<Integer> vertices;
        int val;

        public Node(int val) {
            this.val = val;
            vertices = new ArrayList<>();
        }

        public void addNode(int edge) {
            vertices.add(edge);
        }
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
