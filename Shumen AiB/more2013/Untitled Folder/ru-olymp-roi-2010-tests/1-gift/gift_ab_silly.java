import java.io.*;
import java.util.*;
import java.math.*;

public class gift_ab_silly implements Runnable {

	private void solve() throws IOException {
		long n = in.nextLong();
		long ans = 0;
		for (long a = 1; 6 * a * a <= n; ++a) {
			for (long b = a; 4 * a * b + 2 * b * b <= n; ++b) {
				for (long c = b; 2 * a * b + 2 * b * c + 2 * a * c <= n; ++c) {
					ans = Math.max(ans, a * b * c);
				}
			}
		}
		out.println(ans);
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
		new Thread(new gift_ab_silly()).start();
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