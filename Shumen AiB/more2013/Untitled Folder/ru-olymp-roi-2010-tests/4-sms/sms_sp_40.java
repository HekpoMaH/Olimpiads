// Решение динамикой с двоичным поиском и деревом отрезков

import java.io.*;
import java.util.*;

public class sms_sp_40 implements Runnable {

	public static void main(String[] args) {
		new Thread(new sms_sp_40()).start();
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

	void myAssert(boolean e, String s) {
		if (!e) {
			throw new Error("Assertion failure " + s);
		}
	}

	private static final String FILENAME = "sms";

//	class Person implements Comparable<Person> {
//		String number;
//		int timezone;
//
//		public Person(String nextToken, int i) {
//			number = nextToken;
//			myAssert(number.length() == numberslength, "Wrong length of number");
//			timezone = i;
//		}
//
//		@Override
//		public int compareTo(Person o) {
//			return number.compareTo(o.number);
//		}
//	}

	int myStrCmp(String s1, String s2, int len) {
		for (int i = 0; i < len; i++) {
			if (s1.charAt(i) < s2.charAt(i)) {
				return -1;
			}
			if (s1.charAt(i) > s2.charAt(i)) {
				return 1;
			}
		}
		return 0;
	}

	int lcp(String s1, String s2) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) != s2.charAt(i)) {
				return i;
			}
		}
		return s1.length();
	}

	class RMQ {
		int[] a;
		int[] x;
		int n;

		RMQ(int[] y) {
			n = 1;
			while (n < y.length) {
				n *= 2;
			}
			x = new int[n];
			Arrays.fill(x, Integer.MAX_VALUE / 10);
			for (int i = 0; i < y.length; i++) {
				x[i] = y[i];
			}
			a = new int[2 * n];
			for (int i = n; i < 2 * n; i++) {
				a[i] = i - n;
			}
			for (int i = n - 1; i > 0; i--) {
				if (x[a[2 * i]] < x[a[2 * i + 1]]) {
					a[i] = a[2 * i];
				} else {
					a[i] = a[2 * i + 1];
				}
			}
		}

		int min(int l, int r, int ll, int rr, int y) {
			if (r < ll || l > rr)
				return -1;
			if (ll >= l && rr <= r) {
				return a[y];
			}
			int x1 = min(l, r, ll, (rr + ll) / 2, 2 * y);
			int x2 = min(l, r, (rr + ll) / 2 + 1, rr, 2 * y + 1);
			if (x2 == -1 || (x1 != -1 && x[x1] < x[x2])) {
				return x1;
			} else {
				return x2;
			}
		}

		int min(int l, int r) {
			return min(l, r, 0, n - 1, 1);
		}
	}

	int timezonesnumber = 5;
	public static final int numberslength = 10;
	int[] cost = new int[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	public void solve() {
		String PETYA = nextToken();
		String VASYA = nextToken();
		String[][] pers = new String[timezonesnumber][];
		int[][] c = new int[timezonesnumber][];
		int sum = 0;
		for (int i = 0; i < pers.length; i++) {
			int n = nextInt();
			sum += n;
			pers[i] = new String[n];
			c[i] = new int[n];
			Arrays.fill(c[i], Integer.MAX_VALUE / 10);
			for (int j = 0; j < n; j++) {
				pers[i][j] = nextToken();
			}
		}
		myAssert(sum <= 500, "Too much friends");
		for (int i = 1; i < pers.length - 1; i++) {
			Arrays.sort(pers[i]);
		}
		for (int i = 0; i < pers[1].length; i++) {
			c[1][i] = cost[lcp(PETYA, pers[1][i])];
		}
		for (int i = 0; i < pers[3].length; i++) {
			c[3][i] = cost[lcp(VASYA, pers[3][i])];
		}
		RMQ[] rmq = new RMQ[5];
		rmq[1] = new RMQ(c[1]);
		rmq[3] = new RMQ(c[3]);
		int[] nl = new int[pers[2].length];
		int[] nr = new int[pers[2].length];
		for (int i = 0; i < pers[2].length; i++) {
			Pair left = getBest(rmq[1], pers[1], pers[2][i], c[1]);
			Pair right = getBest(rmq[3], pers[3], pers[2][i], c[3]);
			c[2][i] = left.a + right.a;
			nl[i] = left.b;
			nr[i] = right.b;
		}
		int ibest = 0;
		for (int i = 0; i < pers[2].length; i++) {
			if (c[2][i] < c[2][ibest]) {
				ibest = i;
			}
		}
		if (c[2][ibest] >= Integer.MAX_VALUE / 10) {
			out.println("No solution");
		} else {
			out.println(c[2][ibest] + " " + 5);
			out.println(PETYA);
			out.println(pers[1][nl[ibest]]);
			out.println(pers[2][ibest]);
			out.println(pers[3][nr[ibest]]);
			out.println(VASYA);
		}
	}

	private Pair getBest(RMQ rmq, String[] p1, String p, int[] c) {
		int lc = Integer.MAX_VALUE / 10;
		int ln = -1;
		for (int j = 0; j < numberslength; j++) {
			int ll = -1;
			int rl = p1.length;
			while (rl - ll > 1) {
				int x = (ll + rl) / 2;
				if (myStrCmp(p1[x], p, j) < 0) {
					ll = x;
				} else {
					rl = x;
				}
			}
			int lr = -1;
			int rr = p1.length;
			while (rr - lr > 1) {
				int x = (lr + rr) / 2;
				if (myStrCmp(p1[x], p, j) <= 0) {
					lr = x;
				} else {
					rr = x;
				}
			}
			if (rl <= lr && rl >= 0 && rl < p1.length && lr >= 0 && lr < p1.length && lcp(p1[rl], p) >= j && lcp(p1[lr], p)>= j) {
				int t = rmq.min(rl, lr);
				if (lc > c[t] + cost[j]) {
					lc = c[t] + cost[j];
					ln = t;
				}
			}
		}
		return new Pair(lc, ln);
	}

	class Pair {
		int a, b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
}
