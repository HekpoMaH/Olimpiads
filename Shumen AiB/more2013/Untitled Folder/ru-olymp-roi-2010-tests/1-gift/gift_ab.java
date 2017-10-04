import java.io.*;
import java.util.*;
import java.math.*;

public class gift_ab implements Runnable {

  private void solve() throws IOException {
    long n = in.nextLong();
    out.println(getAns(n));
    out.println(ra + " " + rb + " " + rc);
  }

	long ra = 0, rb = 0, rc = 0;

  long getAns(long n) {
    double ac = Math.sqrt(n / 6.0);
    double a0 = Math.floor(ac);
    long a = Math.round(a0);
    long ans = 0;
    while (true) {
      double bc = Math.sqrt(a * a + n / 2.0) - a;
      if (a * bc * bc < a0 * a0 * a0)
        break;
      double b0 = Math.floor(bc);
      long b = Math.round(b0);
      while (true) {
        double cc = (n - 2 * a * b) / 1.0 / (2 * a + 2 * b);
        long c = (n - 2 * a * b) / (2 * a + 2 * b);
        if (ans < a * b * c) {
          ra = a;
          rb = b;
          rc = c;
        }
        ans = Math.max(ans, a * b * c);
        if (a * b * cc < a * b0 * b0)
          break;
        --b;
      }
      --a;
    }
    return ans;
  }
  final String FILE_NAME = "gift";

  SimpleScanner in;
  PrintWriter out;

  @Override
  public void run() {
    try {
      in = new SimpleScanner(new FileReader(FILE_NAME + ".in"));
      out = new PrintWriter(FILE_NAME + ".out");
      solve();
      out.close();
    } catch (Throwable e) {
      e.printStackTrace();
      System.exit(-1);
    }
  }

  public static void main(String[] args) {
    new Thread(new gift_ab()).start();
  }

  class SimpleScanner extends BufferedReader {

    private StringTokenizer st;
    private boolean eof;

    public SimpleScanner(Reader a) {
      super(a);
    }

    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(readLine());
        } catch (Exception e) {
          eof = true;
          return "";
        }
      }
      return st.nextToken();
    }

    boolean seekEof() {
      String s = next();
      if ("".equals(s) && eof)
        return true;
      st = new StringTokenizer(s + " " + st.toString());
      return false;
    }

    private String cnv(String s) {
      if (s.length() == 0)
        return "0";
      return s;
    }

    int nextInt() {
      return Integer.parseInt(cnv(next()));
    }

    double nextDouble() {
      return Double.parseDouble(cnv(next()));
    }

    long nextLong() {
      return Long.parseLong(cnv(next()));
    }
  }
}
