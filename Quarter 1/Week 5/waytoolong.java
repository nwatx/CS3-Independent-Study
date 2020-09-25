import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class waytoolong
{
    private static final PrintWriter out = new PrintWriter((System.out));
    public static void main(String[] args) throws IOException
    {
        Reader in = new Reader();

        int n = in.nextInt();

        for(int i = 0; i < n; i++) {
            //System.out.println(i);
            String a = in.nextLine();
            //System.out.println(a);
            if(a.length() <= 10) out.println(a);
            else {
                out.println("" + a.charAt(0) + (a.length()-2) + a.charAt(a.length()-1));
            }
        }

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