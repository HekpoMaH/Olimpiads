// Решение динамикой с переходом за O(n^2)

import java.io.*;
import java.util.*;

public class sms_sp_n2 implements Runnable {

	public static void main(String[] args) {
		new Thread(new sms_sp_n2()).start();
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

	class Person implements Comparable<Person> {
		String number;
		int timezone;

		public Person(String nextToken, int i) {
			number = nextToken;
			myAssert(number.length() == numberslength, "Wrong length of number");
			timezone = i;
		}

		@Override
		public int compareTo(Person o) {
			return number.compareTo(o.number);
		}
	}

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

	int timezonesnumber = 5;
	public static final int numberslength = 10;
	int[] cost = new int[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	public void solve() {
		Person PETYA = new Person(nextToken(), 0);
		Person VASYA = new Person(nextToken(), 4);
		Person[][] pers = new Person[timezonesnumber][];
		int[][] c = new int[timezonesnumber][];
		for (int i = 0; i < pers.length; i++) {
			int n = nextInt();
			pers[i] = new Person[n];
			c[i] = new int[n];
			Arrays.fill(c[i], Integer.MAX_VALUE / 10);
			for (int j = 0; j < n; j++) {
				pers[i][j] = new Person(nextToken(), i);
			}
		}
		for (int i = 1; i < pers.length - 1; i++) {
			Arrays.sort(pers[i]);
		}
		for (int i = 0; i < pers[1].length; i++) {
			c[1][i] = cost[lcp(PETYA.number, pers[1][i].number)];
		}
		for (int i = 0; i < pers[3].length; i++) {
			c[3][i] = cost[lcp(VASYA.number, pers[3][i].number)];
		}
		int[] nl = new int[pers[2].length];
		int[] nr = new int[pers[2].length];
		for (int i = 0; i < pers[2].length; i++) {
			Pair left = getBest(pers[1], pers[2][i], c[1]);
			Pair right = getBest(pers[3], pers[2][i], c[3]);
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
			out.println(PETYA.number);
			out.println(pers[1][nl[ibest]].number);
			out.println(pers[2][ibest].number);
			out.println(pers[3][nr[ibest]].number);
			out.println(VASYA.number);
		}
	}

	private Pair getBest(Person[] p1, Person p, int[] c) {
		int lc = Integer.MAX_VALUE / 10;
		int ln = -1;
		for (int i = 0; i < p1.length; i++) {
			if (c[i] + cost[lcp(p1[i].number, p.number)] < lc) {
				lc = c[i] + cost[lcp(p1[i].number, p.number)];
				ln = i;
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
