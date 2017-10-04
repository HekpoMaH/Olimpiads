// решение за 2 ^ n * m  с багами
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class pipeline_sm_wrong {

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
		int best = n + 1;
		boolean[] r = null;
		fori: for (int i = 0; i < (1 << n); i++) {
			if (Integer.bitCount(i) >= best)
				continue;
			boolean[] u = new boolean[n];
			for (int j = 0; j < u.length; j++) {
				u[j] = (i & (1 << j)) > 0;
			}
			for (int j = 0; j < e.length; j++) {
				if (u[e[j][0]] || u[e[j][0]]) {
					// ok
				} else {
					continue fori;
				}
			}
			best = Integer.bitCount(i);
			r = u;
		}
		if (best > k) {
			out.println(-1);
		} else {
			out.println(best);
			for (int i = 0; i < r.length; i++) {
				if (r[i]) {
					out.print((i + 1) + " ");
				}
			}
			out.println();
		}

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
		new pipeline_sm_wrong().run();
	}
}
