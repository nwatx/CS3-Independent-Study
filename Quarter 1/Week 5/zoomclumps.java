import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class zoomclumps
{
    private static PrintWriter out = new PrintWriter((System.out));
    public static void main(String[] args) throws IOException
    {
        Reader in = new Reader();

        int n = in.nextInt();

        char[] rooms = new char[n];

        for(int i = 0; i < n; i++) {
            rooms[i] = in.next().charAt(0);
        }

        int ret = 1;

        for(int i = 1; i < rooms.length; i++) {
            if(rooms[i] != rooms[i-1]) ret++;
        }

        out.println(ret);

        out.close();
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