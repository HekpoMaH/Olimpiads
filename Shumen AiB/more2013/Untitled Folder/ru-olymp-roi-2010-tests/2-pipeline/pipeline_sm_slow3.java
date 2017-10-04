// решение за 2 ^ k * n ^ 2
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class pipeline_sm_slow3 {

	int n, m, k;
	boolean[][] e;

	int[] ans;

	void gen(int cnt) {
		if (cnt > k) {
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (e[i][j]) {
					for (int x : new int[] { i, j }) {
						ArrayList<Integer> neib = new ArrayList<Integer>();
						for (int k = 0; k < n; k++) {
							if (e[x][k]) {
								neib.add(k);
								e[x][k] = e[k][x] = false;
							}
						}
						ans[cnt] = x;
						gen(cnt + 1);
						for (int r : neib) {
							e[x][r] = e[r][x] = true;
						}
					}
					return;
				}
			}
		}

		wh: while (cnt < k) {
			fori: for (int i = 0; i < n; i++) {
				for (int j = 0; j < cnt; j++) {
					if (ans[j] == i)
						continue fori;
				}
				ans[cnt] = i;
				cnt++;
				continue wh;
			}
			throw new AssertionError("k >= n");
		}
		out.println("Yes");
		for (int i = 0; i < k; i++) {
			out.print((ans[i] + 1) + " ");
		}
		out.println();
		out.flush();
		System.exit(0);
	}

	void solve() {
		n = nextInt();
		m = nextInt();
		k = nextInt();
		e = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			e[x][y] = e[y][x] = true;
		}
		ans = new int[k + 1];
		gen(0);
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
		new pipeline_sm_slow3().run();
	}
}
