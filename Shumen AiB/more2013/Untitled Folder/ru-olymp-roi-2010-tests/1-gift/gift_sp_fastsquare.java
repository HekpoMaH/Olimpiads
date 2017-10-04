import java.io.*;
import java.util.*;

public class gift_sp_fastsquare implements Runnable {

	public static void main(String[] args) {
		new Thread(new gift_sp_fastsquare()).start();
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
	
	final int cc = 2000;

	public void solve() {
		long n = nextLong();
		n /= 2;
		long x = Math.round(Math.floor(Math.sqrt(n / 3)));
		long ans = x * x * x;
		long ansa = x;
		long ansb = x;
		long ansc = x;
		for (long a = x - cc; a <= x; a++) {
			for (long b = x; b <= x + cc; b++) {
				if (a * b + a + b > n) break;
				long c = Math.round(Math.floor(1.0 * (n - a * b) / (a + b)));
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
