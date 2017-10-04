// решение за 2 ^ n * m
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class pipeline_sm_slow {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[][] e = new int[m][2];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			e[i][0] = x;
			e[i][1] = y;
		}
		boolean[] u = new boolean[n];
		fori: for (int i = 0; i < (1 << n); i++) {
			// System.err.println(Integer.toBinaryString(i));
			for (int j = 0; j < u.length; j++) {
				u[j] = (i & (1 << j)) > 0;
			}
			for (int j = 0; j < e.length; j++) {
				if (u[e[j][0]] || u[e[j][1]]) {
					// ok
				} else {
					continue fori;
				}
			}
			if (Integer.bitCount(i) != k)
				continue;
			out.println("Yes");
			for (int j = 0; j < u.length; j++) {
				if (u[j]) {
					out.print((j + 1) + " ");
				}
			}
			return;
		}
		out.println("No");
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			br = new BufferedReader(new FileReader("pipeline.in"));
			out = new PrintWriter("pipeline.out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(123);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
			throw new AssertionError();
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) {
		new pipeline_sm_slow().run();
	}
}
