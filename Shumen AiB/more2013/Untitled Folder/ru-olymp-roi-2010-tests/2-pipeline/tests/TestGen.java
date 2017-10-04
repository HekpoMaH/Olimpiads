import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class TestGen implements Runnable {
	Random rand;

	class Test {
		int n, k;
		ArrayList<Edge> edges;

		public Test(int k) {
			this.n = 0;
			this.k = k;
			this.edges = new ArrayList<Edge>();
		}

		void shuffle() {
			ArrayList<Integer> numbers = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				numbers.add(i);
			}
			Collections.shuffle(numbers, rand);
			for (Edge e : edges) {
				int x = numbers.get(e.a);
				int y = numbers.get(e.b);
				if (rand.nextBoolean()) {
					e.a = x;
					e.b = y;
				} else {
					e.a = y;
					e.b = x;
				}
			}
			Collections.shuffle(edges, rand);
		}

		void addHedgehog(int cnt) {
			for (int i = 0; i < cnt - 1; i++) {
				add(n, n + 1 + i);
			}
			n += cnt;
		}

		void addDoubleHedgehog(int cnt) {
			if (cnt % 2 != 1) {
				throw new AssertionError("cnt % 2 != 1");
			}
			int x = cnt / 2;
			for (int i = 0; i < x; i++) {
				add(n, n + i + 1);
				add(n + 1 + i, n + 1 + x + i);
			}
			n += cnt;
		}

		void addCycle(int cnt) {
			addCycle(n, cnt);
		}

		void addCycle(int vfrom, int cnt) {
			n += cnt;
			for (int i = 0; i < cnt; i++) {
				add(vfrom + i, vfrom + (i + 1) % cnt);
			}
		}

		void addClique(int cnt) {
			addClique(n, cnt);
		}

		void addClique(int vfrom, int cnt) {
			n += cnt;
			for (int i = 0; i < cnt; i++) {
				for (int j = i + 1; j < cnt; j++) {
					add(vfrom + i, vfrom + j);
				}
			}
		}

		void addRandom(int N, int M) {
			addRandom(n, N, M);
		}

		void addRandom(int vfrom, int N, int M) {
			n += N;
			boolean[][] e = new boolean[N][N];
			for (int i = 0; i < M; i++) {
				int x, y;
				do {
					x = rand.nextInt(N);
					y = rand.nextInt(N);
				} while (x == y || e[x][y]);
				e[x][y] = e[y][x] = true;
				add(vfrom + x, vfrom + y);
			}
		}

		private void add(int x, int y) {
			if (x == y)
				throw new AssertionError("x == y");
			edges.add(new Edge(x, y));
		}

		void addAntiMaxDegree1() {
			add(n, n + 1);
			add(n, n + 2);
			add(n, n + 3);
			add(n, n + 4);
			add(n + 1, n + 5);
			add(n + 1, n + 6);
			add(n + 2, n + 5);
			add(n + 2, n + 6);
			add(n + 3, n + 7);
			add(n + 3, n + 8);
			add(n + 4, n + 7);
			add(n + 4, n + 8);
			n += 9;
		}

		ArrayList<Integer> addAntiMaxDegree2(int inD, int outD) {
			ArrayList<Integer> base = new ArrayList<Integer>();
			for (int i = 0; i < inD; i++) {
				base.add(n + i + 1);
				add(n + 0, n + i + 1);
				for (int j = 0; j < outD; j++) {
					int x = inD + 1 + (outD * i) + j;
					add(n + i + 1, n + x);
					add(n + (i + 1) % inD + 1, n + x);
				}
			}
			n += 1 + inD + inD * outD;
			return base;
		}

		void addPattern3(int N) {
			for (int i = 0; i < N; i++) {
				add(n, n + 2 + i);
				add(n + 1, n + 2 + i);
			}
			n += 2 + N;
		}

		void addWithAnswerK(int k, int N, int M) {
			boolean[][] e = new boolean[N][N];

			for (int i = 0; i < M; i++) {
				int x, y;
				do {
					x = rand.nextInt(k);
					y = rand.nextInt(N);
				} while (x == y || e[x][y]);
				e[x][y] = e[y][x] = true;
				add(n + x, n + y);
			}
			n += N;
		}

		ArrayList<Integer> addWithAnswerKAndLimitOfDegree(int k, int N, int M,
				int maxDegree) {
			return addWithAnswerKAndLimitOfDegree(k, N, M, maxDegree, false);
		}

		ArrayList<Integer> addWithAnswerKAndLimitOfDegree(int k, int N, int M,
				int maxDegree, boolean lotOfSmall) {
			boolean[][] e = new boolean[N][N];
			int[] deg = new int[N];
			int[] maxDeg = new int[N];
			for (int i = 0; i < maxDeg.length; i++) {
				maxDeg[i] = rand.nextInt(maxDegree) + 1;
			}
			if (lotOfSmall) {
				for (int i = 0; i < maxDeg.length; i++) {
					if (rand.nextInt(5) != 0) {
						maxDeg[i] = 2 + rand.nextInt(2);
					}
				}
			}
			for (int i = k; i < N; i++) {
				int x, y;
				do {
					x = rand.nextInt(k);
					y = rand.nextInt(k);
				} while (x == y || deg[x] >= maxDeg[x] || deg[y] >= maxDeg[y]);

				deg[x]++;
				deg[y]++;
				add(n + i, n + x);
				e[x][i] = e[i][x] = true;
				add(n + i, n + y);
				e[y][i] = e[i][y] = true;
			}
			System.err.println(edges.size());
			int it = 0;
			fori: for (int i = 0; i < M; i++) {
				int x, y;
				do {
					x = rand.nextInt(k);
					y = rand.nextInt(N);
					it++;
					if (it > 1e6) {
						break fori;
					}
				} while (x == y || e[x][y] || deg[x] >= maxDeg[x]);
				deg[x]++;
				deg[y]++;
				e[x][y] = e[y][x] = true;
				add(n + x, n + y);
			}
			System.err.println(edges.size());
			ArrayList<Integer> base = new ArrayList<Integer>();
			for (int i = 0; i < k; i++) {
				base.add(n + i);
			}
			n += N;
			return base;
		}

		// TODO rename
		void genX(int k, int N) {
			int x = k / 3;
			System.err.println("x = " + x + " k = " + k + " N = " + N);
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < k; j++) {
					add(n + i, n + x + j);
				}
			}
			int[] deg = new int[k];
			for (int j = 0; j < deg.length; j++) {
				deg[j] = k / 2;
			}
			boolean[][] e = new boolean[x + k + N][x + k + N];
			for (int i = 0; i < N; i++) {
				int a, b;
				do {
					a = rand.nextInt(k);
					b = rand.nextInt(k);
				} while (a == b || deg[a] == 0 || deg[b] == 0);
				add(n + x + a, n + x + k + i);
				e[x + a][x + k + i] = e[x + k + i][x + a] = true;
				add(n + x + b, n + x + k + i);
				e[x + b][x + k + i] = e[x + k + i][x + b] = true;
				deg[a]--;
				deg[b]--;
			}
			for (int i = 0; i < k; i++) {
				if (deg[i] != k / 2) {
					continue;
				}
				System.err.println("BOTVEEEEE");
				if (true)
					continue;
				int r;
				do {
					r = rand.nextInt(N);
				} while (e[x + i][x + k + r]);
				add(n + x + i, n + x + k + r);
			}
			n += N + x + k;
		}

		void addOnes(int k, ArrayList<Integer> base) {
			for (int i = 0; i < k; i++) {
				int x = base.get(rand.nextInt(base.size()));
				add(n + i, x);
			}
			n += k;
		}

		void write(int testNum) {
			System.err.println("write test " + testNum);
			System.out.println(name + " (n = " + n + ", m=" + edges.size()
					+ ", k=" + k+")");
			String filename = String.format("%02d", testNum);
			try {
				PrintWriter out = new PrintWriter(new FileWriter(filename));
				out.println(n + " " + edges.size() + " " + k);
				for (Edge e : edges) {
					out.println((e.a + 1) + " " + (e.b + 1));
				}
				out.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public void addSimpleVertexes(int count, int degree) {
			for (int i = 0; i < count; i++) {
				boolean[] u = new boolean[n];
				for (int j = 0; j < degree; j++) {
					int x;
					do {
						x = rand.nextInt(n);
					} while (u[x]);
					u[x] = true;
					add(n + i, x);
				}
			}
			n += count;
		}

		String name;

		public Test setName(String string) {
			name = string;
			return this;
		}

	}

	class Edge {
		int a, b;

		public Edge(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}

	final int MAXN = 2000;
	final int MAXM = 100000;
	final int MAXK = 40;

	public void run() {
		rand = new Random(2);
		gen31_35(30);
		rand = new Random(1);
		gen36_40(35);
		rand = new Random(2);
		gen41_45(40);
		rand = new Random(2);
		gen46_50(45);
	}

	void gen1(int num, boolean shuffle) {
		Test t = new Test(40);
		t.addAntiMaxDegree1();
		for (int i = 0; i < 18; i++) {
			t.addCycle(3);
		}
		if (shuffle) {
			t.shuffle();
		}
		t.write(num);
	}

	void gen31_35(int q) {
		{
			Test t = new Test(40);
			t.addAntiMaxDegree2(30, 14);
			t.addSimpleVertexes(10, 50);
			t.shuffle();
			t.setName("Несколько станций более чем с k трубопроводами.");
			t.write(q + 1);
		}
		{
			Test t = new Test(40);
			t.addAntiMaxDegree2(35, 14);
			t.addSimpleVertexes(5, 50);
			t.shuffle();
			t.setName("Несколько станций более чем с k трубопроводами.");
			t.write(q + 2);
		}
		{
			Test t = new Test(40);
			t.addAntiMaxDegree2(25, 9);
			t.addSimpleVertexes(15, 40);
			t.setName("Несколько станций более чем с k трубопроводами.");
			t.shuffle();
			t.write(q + 3);
		}
		{
			Test t = new Test(40);
			t.addAntiMaxDegree2(30, 10);
			t.addSimpleVertexes(10, 40);
			t.setName("Несколько станций более чем с k трубопроводами.");
			t.shuffle();
			t.write(q + 4);
		}
		{
			Test t = new Test(10);
			t.addAntiMaxDegree2(8, 3);
			t.addSimpleVertexes(2, 6);
			t.setName("Несколько станций более чем с k трубопроводами.");
			t.shuffle();
			t.write(q + 5);
		}
	}

	void gen36_40(int q) {
		{
			Test t = new Test(40);
			ArrayList<Integer> base = t.addWithAnswerKAndLimitOfDegree(5, 10,
					100, 60);
			t.addOnes(5, base);
			t.addAntiMaxDegree2(35, 15);
			t.setName("Несколько станций с 1 трубопроводом.");
			t.shuffle();
			t.write(q + 1);
		}
		{
			Test t = new Test(40);
			ArrayList<Integer> base = t.addAntiMaxDegree2(36, 17);
			t.addOnes(14, base);
			t.addAntiMaxDegree1();
			t.setName("Несколько станций с 1 трубопроводом.");
			t.shuffle();
			t.write(q + 2);
		}
		{
			Test t = new Test(40);
			ArrayList<Integer> base = t.addAntiMaxDegree2(28, 7);
			t.addOnes(14, base);
			base.addAll(t.addWithAnswerKAndLimitOfDegree(8, 10, 6000, 20));
			t.addAntiMaxDegree1();
			t.setName("Несколько станций с 1 трубопроводом.");
			t.shuffle();
			t.write(q + 3);
		}
		{
			Test t = new Test(40);
			t.addDoubleHedgehog(71);
			t.addAntiMaxDegree1();
			t.setName("Несколько станций с 1 трубопроводом.");
			t.shuffle();
			t.write(q + 4);
		}
		{
			Test t = new Test(10);
			t.addDoubleHedgehog(21);
			t.setName("Несколько станций с 1 трубопроводом.");
			t.shuffle();
			t.write(q + 5);
		}

	}

	void gen41_45(int q) {
		{
			Test t = new Test(40);
			t.genX(40, 60);
			t.shuffle();
			t.setName("Полный двудольный граф с дополнительными вершинами.");
			t.write(q + 1);
		}
		{
			Test t = new Test(40);
			t.genX(30, 60);
			t.addAntiMaxDegree2(10, 4);
			t.shuffle();
			t.setName("Полный двудольный граф с дополнительными вершинами.");
			t.write(q + 2);
		}
		{
			Test t = new Test(40);
			t.genX(20, 40);
			t.addAntiMaxDegree2(20, 9);
			t.shuffle();
			t.setName("Полный двудольный граф с дополнительными вершинами.");
			t.write(q + 3);
		}
		{
			Test t = new Test(40);
			t.genX(40, 50);
			t.shuffle();
			t.setName("Полный двудольный граф с дополнительными вершинами.");
			t.write(q + 4);
		}
		{
			Test t = new Test(10);
			t.addWithAnswerKAndLimitOfDegree(8, 10, 20, 20, false);
			t.genX(4, 4);
			t.shuffle();
			t.setName("Полный двудольный граф с дополнительными вершинами.");
			t.write(q + 5);
		}

	}

	void gen46_50(int q) {
		genCutting2(10)
				.setName(
						"Набор треугольников с дополнениями против жадных и переборных решений.")
				.write(q + 1);
		genCutting2(12)
				.setName(
						"Набор треугольников с дополнениями против жадных и переборных решений.")
				.write(q + 2);
		genCutting2(15)
				.setName(
						"Набор треугольников с дополнениями против жадных и переборных решений.")
				.write(q + 3);
		genCutting2(16)
				.setName(
						"Набор треугольников с дополнениями против жадных и переборных решений.")
				.write(q + 4);
		genCutting2(17)
				.setName(
						"Набор треугольников с дополнениями против жадных и переборных решений.")
				.write(q + 5);
	}

	Test genCutting2(int triangles) {
		Test t = new Test(40);
		t.addPattern3(30 + rand.nextInt(10));
		int x = 40 - 2 - 2 * triangles;
		System.err.println(x);
		t.addAntiMaxDegree2(x, x / 2 - 1 - x % 2);
		for (int i = 0; i < triangles; i++) {
			t.addCycle(3);
		}
		t.shuffle();
		return t;
	}

	void gen4(int num) {
		Test t = new Test(40);
		t.shuffle();
		t.write(num);
	}

	public static void main(String[] args) {
		new TestGen().run();
	}
}
