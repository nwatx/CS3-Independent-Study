import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class wifipoints
{
    private static PrintWriter out = new PrintWriter((System.out));
    public static void main(String[] args) throws IOException
    {
        Reader in = new Reader();

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        char[][] h = new char[n][m];

        ArrayList<Pair<Integer, Integer>> starts = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            h[i] = in.nextLine().toCharArray();

            for(int j = 0; j < h[i].length; j++) {
                if(h[i][j] == 'X' || h[i][j] == 'S') starts.add(new Pair<>(i,j));
            }
        }

        int ret = Integer.MAX_VALUE;

        int[][] dist = new int[n][m];

        for(int[] b : dist) {
            Arrays.fill(b, -1);
        }

        for(Pair<Integer, Integer> p : starts) {
            System.out.println(bfs(k,dist.clone(),p.getKey(),p.getValue(),h));
            //ret = Math.min(ret,bfs(k, dist.clone(), p.getKey(), p.getValue(), h));
        }

        out.println(ret);

        out.close();
    }

    private static int bfs(int k, int[][] dist, int i, int j, char[][] h) {
        int ret = 0;
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        dist[i][j] = 0;
        q.add(new Pair<>(i,j));

        while(!q.isEmpty() && k > 0) {
            Pair<Integer, Integer> v = q.poll();

            int key = v.getKey();
            int value = v.getValue();
            if(dist[key][value] == '*') continue;
            if(h[v.getKey()][v.getValue()] == 'X' || h[key][value] == 'S') ret += dist[key][value];

            if(key-1>=0 && dist[key-1][value] == -1) {
                q.add(new Pair<>(key - 1, value));
                dist[key-1][value] = dist[key][value]+1;
            }
            if(key+1<dist.length && dist[key+1][value] == -1) {
                q.add(new Pair<>(key+1,value));
                dist[key+1][value] = dist[key][value]+1;
            }
            if (value - 1 >= 0 && dist[key][value-1] == -1) {
                dist[key][value-1] = dist[key][value]+1;
                q.add(new Pair<>(key, value - 1));
            }
            if (value + 1 < dist[0].length && dist[key][value+1] == -1) {
                dist[key][value+1] = dist[key][value]+1;
                q.add(new Pair<>(key, value + 1));
            }
        }
        System.out.println(Arrays.deepToString(dist));
        if(ret == 0) return Integer.MAX_VALUE;
        return ret;
    }

    static class Reader
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        public String next()
        {
            while(!st.hasMoreTokens())
            {
                try
                {
                    st=new StringTokenizer(br.readLine());
                }
                catch(Exception e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        public int nextInt()
        {
            return Integer.parseInt(next());
        }
        public long nextLong()
        {
            return Long.parseLong(next());
        }
        public double nextDouble()
        {
            return Double.parseDouble(next());
        }
        public String nextLine()
        {
            try
            {
                return br.readLine();
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
            return null;
        }
        public boolean hasNext()
        {
            String next=null;
            try
            {
                next=br.readLine();
            }
            catch(Exception e)
            {
            }
            if(next==null)
            {
                return false;
            }
            st=new StringTokenizer(next);
            return true;
        }
    }
}