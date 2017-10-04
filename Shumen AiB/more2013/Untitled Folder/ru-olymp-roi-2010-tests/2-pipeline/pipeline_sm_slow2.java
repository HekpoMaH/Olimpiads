// решение за C(n, k) * m
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class pipeline_sm_slow2 {

	boolean[] u;
	int[][] e;
	int n, m, k;

	void gen(int cnt, int pos) {
		if (cnt == k) {
			boolean ok = true;
			for (int i = 0; i < m; i++) {
				if (!u[e[i][0]] && !u[e[i][1]]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				out.println("Yes");
				for (int i = 0; i < n; i++) {
					if (u[i]) {
						out.print((i + 1) + " ");
					}
				}
				out.println();
				out.flush();
				System.exit(0);
			}
			return;
		}
		for (int i = pos; i < n; i++) {
			if (!u[i]) {
				u[i] = true;
				gen(cnt + 1, i + 1);
				u[i] = false;
			}
		}

	}

	void solve() {
		n = nextInt();
		m = nextInt();
		k = nextInt();
		e = new int[m][2];
		u = new boolean[n];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			e[i][0] = x;
			e[i][1] = y;
		}
		gen(0, 0);
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
		new pipeline_sm_slow2().run();
	}
}
