// жадность: делает безопасные операции, если их нет, то берет вершину максимальной степени 
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class pipeline_sm_greed1 {
	TreeSet<Integer>[] neib;
	Set<Integer> ans;
	int n, m, k;

	void select(int x) {
		for (int j : neib[x]) {
			neib[j].remove(x);
		}
		neib[x].clear();
		ans.add(x);
		k--;
	}

	@SuppressWarnings("unchecked")
	void solve() {
		n = nextInt();
		m = nextInt();
		k = nextInt();
		neib = new TreeSet[n];
		for (int i = 0; i < n; i++) {
			neib[i] = new TreeSet<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			neib[x].add(y);
			neib[y].add(x);
		}
		ans = new TreeSet<Integer>();
		while (true) {
			boolean change = true;
			while (change) {
				change = false;
				for (int i = 0; i < n; i++) {
					if (neib[i].size() == 1) {
						int x = neib[i].first();
						select(x);
						change = true;
					}
					if (k > 0 && neib[i].size() > k) {
						select(i);
						change = true;
					}
				}
			}
			int max = 0;
			int maxi = -1;
			for (int i = 0; i < n; i++) {
				if (neib[i].size() > max) {
					max = neib[i].size();
					maxi = i;
				}
			}
			if (max == 0) {
				if (k >= 0) {
					out.println("Yes");
					for (int i = 0; i < n && k > 0; i++) {
						if (!ans.contains(i)) {
							ans.add(i);
							k--;
						}
					}
					for (int i : ans) {
						out.print((i + 1) + " ");
					}
					return;
				} else {
					out.println("No");
					return;
				}
			} else {
				select(maxi);
			}
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
		new pipeline_sm_greed1().run();
	}
}
