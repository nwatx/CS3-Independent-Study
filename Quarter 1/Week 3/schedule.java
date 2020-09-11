import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
 
public class schedule
{
    private static PrintWriter out = new PrintWriter((System.out));
    private static boolean[] visited;
    private static int end;
 
    public static void main(String[] args) throws IOException
    {
        Reader in = new Reader();
        int n = in.nextInt();
        int m = in.nextInt();
 
        visited = new boolean[n];
        int[] ret = new int[n];
        end = n-1;
 
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
 
        for(int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
        }
 
        for(int i = 0; i < m; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            adj.get(a).add(b);
        }
 
        for(int a : adj.keySet()) {
            if(!visited[a]) {
                dfs(a, adj, ret);
            }
        }
 
        for(int i = 0; i < ret.length; i++) {
            if(i == 0) System.out.print(ret[i]+1);
            else System.out.print(" " + (ret[i]+1));
        }
        out.close();
    }
 
    private static void dfs(int a, HashMap<Integer, ArrayList<Integer>> adj, int[] ret) {
        visited[a] = true;
 
        for(int e : adj.get(a)) {
            if(!visited[e]) {
                dfs(e, adj, ret);
            }
        }
        ret[end] = a;
        end--;
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