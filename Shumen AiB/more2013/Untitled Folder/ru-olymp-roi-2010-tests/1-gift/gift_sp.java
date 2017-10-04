import java.io.*;
import java.util.*;

public class gift_sp implements Runnable {

	public static void main(String[] args) {
		new Thread(new gift_sp()).start();
	}

	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FILENAME + ".in"));
			out = new PrintWriter(FILENAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() {
		return Long.parseLong(nextToken());
	}

	void myAssert(boolean e, String s) {
		if (!e) {
			throw new Error("Assertion failure " + s);
		}
	}

	private static final String FILENAME = "gift";

	public void solve() {
		long n = nextLong();
		n /= 2;
		long aa = Math.round(Math.floor(Math.sqrt(n / 3)));
		long ans = aa * aa * aa;
		long ansa = aa;
		long ansb = aa;
		long ansc = aa;
		for (long a = aa; ; a++) {
			double bb = Math.sqrt(a * a + n) - a;
			if (a * bb * bb < ans) break;
			for (long b = Math.round(Math.floor(bb)); ; b--) {
				double cc = 1.0 * (n - a * b) / (a + b);
				if (a * b * cc < ans) break;
				long c = Math.round(Math.floor(cc));
				if (a * b * c > ans) {
					ans = a * b * c;
					ansa = b;
					ansb = a;
					ansc = c;
				}
				
			}
		}
		out.println(ans);
		out.println(ansa + " " + ansb + " " + ansc);
	}
}
