//Meet-in-the-middle solution
//�������� �� O(10 n)

import java.io.*;
import java.util.*;
import java.math.*;

public class sms_ab_mitm2 implements Runnable {

	final int MAXN = 200000;
	final int SL = 10;
	final String NO_SOL = "No solution";
	
	private void solve() throws IOException {
		String[][] g = new String[5][];
		int sum = 0;
		String st = checkFormat(in.next());
		String fin = checkFormat(in.next());
		for (int i = 0; i < g.length; ++i) {
			int k = in.nextInt();
			assert 0 <= k && k <= MAXN;
			sum += k;
			g[i] = new String[k];
			for (int j = 0; j < g[i].length; ++j) {
				g[i][j] = checkFormat(in.next());
			}
		}
		assert 0 <= sum && sum <= MAXN;
		g[0] = new String[]{st};
		g[4] = new String[]{fin};
		
		for (int i = 1; i <= 3; ++i) {
			if (g[i].length == 0) {
				out.println(NO_SOL);
				return;
			}
		}
		
		for (String[] sa : g) {
			Arrays.sort(sa);
		}
		
		String[] ans = new String[5];
		int ansv = Integer.MAX_VALUE;
		
		String s0 = g[0][0];
		String s5 = g[4][0];
		String s1 = g[1][getNearest(g[1], s0)];	
		String s4 = g[3][getNearest(g[3], s5)];
		
		int pl = 0;
		int pr = 0;
		
		for (String s : g[2]) {
			if ("9408772383".equals(s)) {
				System.out.println(s);
			}
			
			while (pl < g[1].length - 1) {
				int x = F(g[1][pl], s);
				int y = F(g[1][pl + 1], s);
				if (y < x || g[1][pl + 1].compareTo(s) <= 0 && x == y) {
					++pl;
				} else {
					break;
				}
			}
			while (pr < g[3].length - 1) {
				int x = F(g[3][pr], s);
				int y = F(g[3][pr + 1], s);
				if (y < x || g[3][pr + 1].compareTo(s) <= 0 && x == y) {
					++pr;
				} else {
					break;
				}
			}
			
			String s2 = g[1][pl];
			String s3 = g[3][pr];
//			System.out.println(s + " " + s2 + " " + s3);
			if (F(s0, s1) + F(s1, s) < F(s0, s2) + F(s2, s)) {
				s2 = s1;
			}
			if (F(s, s4) + F(s4, s5) < F(s, s3) + F(s3, s5)) {
				s3 = s4;
			}
			int tansv = F(s0, s2) + F(s2, s) + F(s, s3) + F(s3, s5); 
			if (ansv > tansv) {
				ansv = tansv;
				ans[0] = s0;
				ans[1] = s2;
				ans[2] = s;
				ans[3] = s3;
				ans[4] = s5;
			}
		}
		
		out.println(ansv + " 5");
		for (String s : ans) {
			out.println(s);
		}
		
	}
	

	private int getNearest(String[] a, String s) {
		int ans = 0;
		int ansv = F(a[0], s);
		for (int i = 1; i < a.length; ++i) {
			int tv = F(a[i], s); 
			if (tv < ansv) {
				ansv = tv;
				ans = i;
			}
		}
		return ans;
	}


	int lcp(String a, String b) {
		for (int i = 0; i < SL; ++i) {
			if (a.charAt(i) != b.charAt(i)) {
				return i;
			}
		}
		return SL;
	}
	
	int F(String a, String b) {
		return 10 - lcp(a, b);
	}

	String checkFormat(String s) {
		assert s.length() == SL;
		for (int i = 0; i < s.length(); ++i) {
			assert Character.isDigit(s.charAt(i));
		}
		return s;
	}
	
	final String FILE_NAME = "sms";

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
		new Thread(new sms_ab_mitm2()).start();
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
