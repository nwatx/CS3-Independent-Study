/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wanggda1
LANG: JAVA
TASK: test
*/

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class fenceplan {
    public static void main(String[] args) throws IOException {
        final String TASK = "fenceplan";
        BufferedReader br = new BufferedReader(new FileReader(new File(TASK + ".in")));
        PrintWriter out = new PrintWriter(new File(TASK + ".out"));

        StringTokenizer tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int m = Integer.parseInt(tk.nextToken());

        Cow[] cows = new Cow[n];

        for(int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(tk.nextToken());
            int y = Integer.parseInt(tk.nextToken());

            cows[i] = new Cow(x, y);
        }

        ArrayList[] adj = new ArrayList[n];

        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for(int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken())-1;
            int b = Integer.parseInt(tk.nextToken())-1;

            adj[a].add(b);
            adj[b].add(a);
        }

        int minimum = Integer.MAX_VALUE;
        boolean[] visited = new boolean[n];

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                Output o = new Output();
                areaDfs(adj, visited, cows, i, o);
                minimum = Math.min(minimum, o.getPerimeter());
            }
        }
        out.println(minimum);
        out.close();
    }

    private static void areaDfs(ArrayList<Integer>[] adj, boolean[] visited, Cow[] cows, int i, Output output) {
        //System.out.println(i);
        visited[i] = true;

        output.update(cows[i].x, cows[i].y);

        for(int j : adj[i]) {
            if(!visited[j]) {
                areaDfs(adj, visited, cows, j, output);
            }
        }
    }

    private static class Cow {
        int x;
        int y;

        public Cow(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class Output {
        int lX = Integer.MAX_VALUE;
        int lY = Integer.MAX_VALUE;
        int hX = Integer.MIN_VALUE;
        int hY = Integer.MIN_VALUE;

        public void update(int x, int y) {
            lX = Math.min(lX, x);
            lY = Math.min(lY, y);
            hX = Math.max(hX, x);
            hY = Math.max(hY, y);
        }

        public int getPerimeter() {
            return 2 * ((hX - lX) + (hY - lY));
        }
    }
}
