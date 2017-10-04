import java.io.*;
import java.util.*;

public class TestsGen {
	static int testcount = 0;

	static Random random = new Random(823472387);

	static int len = 10;

	static void write(String[][] s, String v, String p) throws IOException {
		PrintWriter out = new PrintWriter(String.format("%02d", ++testcount));
		System.out.println("Generating test #" + testcount);
		out.println(v);
		out.println(p);
		for (int i = 0; i < s.length; i++) {
			out.println(s[i].length);
			for (int j = 0; j < s[i].length; j++) {
				out.println(s[i][j]);
			}
		}
		out.close();
	}

	static HashSet<String> hs;
	static long curNum;

	static String nextNumber() {
		String ret = String.format("%010d", curNum++);
		hs.add(ret);
		return ret;
	}

	static String randNumber() {
		String ret;
		do {
			ret = "";
			for (int i = 0; i < len; i++) {
				ret += (char) (random.nextInt(10) + '0');
			}
		} while (hs.contains(ret));
		hs.add(ret);
		return ret;
	}

	static String randNumber(int n) {
		String ret;
		do {
			ret = "";
			for (int i = 0; i < len; i++) {
				ret += (char) (random.nextInt(10) + '0');
			}
		} while (hs.contains(ret) || ret.charAt(0) - '0' == n);
		hs.add(ret);
		return ret;
	}
	
	static String randNumber2(int n) {
		String ret;
		do {
			ret = (char) (n + '0') + "";
			for (int i = 1; i < len; i++) {
				ret += (char) (random.nextInt(10) + '0');
			}
		} while (hs.contains(ret));
		hs.add(ret);
		return ret;
	}
	
	static void writeGood(int n) throws IOException {
		hs = new HashSet<String>();
		curNum = 0;
		String[][] nums = new String[5][1];
		for (int i = 1; i < nums.length - 1; i++) {
			nums[i] = new String[n];
		}
		for (int j = 0; j < n; j++) {
			for (int i = 1; i < nums.length - 1; i++) {
				nums[i][j] = nextNumber();
			}
		}
		nums[0][0] = randNumber();
		nums[4][0] = randNumber();
		write(nums, randNumber(), randNumber());
	}
	
	static String last(ArrayList<String> al) {
		String ret = al.get(al.size() - 1);
		al.remove(al.size() - 1);
		return ret;
	}

	static void writeGoodRand(int[] n, long start) throws IOException {
		ArrayList<String> al = new ArrayList<String>();
		for (int i = 0; i < n.length; i++) {
			for (int j = 0; j < n[i]; j++) {
				al.add(String.format("%010d", start++));
			}
		}
		al.add(String.format("%010d", start++));
		al.add(String.format("%010d", start++));
		Collections.shuffle(al, random);
		curNum = 0;
		String[][] nums = new String[5][0];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = new String[n[i]];
		}
		for (int i = 0; i < n.length; i++) {
			for (int j = 0; j < n[i]; j++) {
				nums[i][j] = last(al);
			}
		}
		write(nums, last(al), last(al));
	}

	static void writeRand(int[] n) throws IOException {
		hs = new HashSet<String>();
		String[][] nums = new String[n.length][];
		for (int i = 0; i < n.length; i++) {
			nums[i] = new String[n[i]];
			for (int j = 0; j < nums[i].length; j++) {
				nums[i][j] = randNumber();
			}
		}
		write(nums, randNumber(), randNumber());
	}

	static void writeRand2(int[] n) throws IOException {
		int notuse = random.nextInt(10);
		hs = new HashSet<String>();
		String[][] nums = new String[n.length][];
		for (int i = 0; i < n.length; i++) {
			nums[i] = new String[n[i]];
			for (int j = 0; j < nums[i].length; j++) {
				nums[i][j] = randNumber(notuse);
			}
		}
		write(nums, randNumber2(notuse), randNumber2(notuse));
	}

	static void writeRand3(int[] n) throws IOException {
		int notuse = random.nextInt(10);
		while (notuse == 5 && notuse == 6) {
			notuse = random.nextInt(10);
		}
		curNum = 5000000000L;
		hs = new HashSet<String>();
		String[][] nums = new String[n.length][];
		for (int i = 0; i < n.length; i++) {
			nums[i] = new String[n[i]];
		}
		nums[1][0] = nextNumber();
		nums[2][0] = nextNumber();
		curNum = 6000000000L;
		nums[3][0] = nextNumber();
		for (int i = 0; i < n.length; i++) {
			for (int j = (i > 0 && i < 4) ? 1 : 0; j < nums[i].length; j++) {
				nums[i][j] = randNumber(notuse);
			}
		}
		for (int i = 0; i < n.length; i++) {
			List<String> al = Arrays.asList(nums[i]);
			Collections.shuffle(al);
			nums[i] = al.toArray(new String[al.size()]);
		}
		write(nums, randNumber2(notuse), nextNumber());
	}

	static void writeRand4(int[] n) throws IOException {
		int notuse = random.nextInt(10);
		while (notuse == 5 && notuse == 4) {
			notuse = random.nextInt(10);
		}
		curNum = 4000000000L;
		hs = new HashSet<String>();
		String[][] nums = new String[n.length][];
		for (int i = 0; i < n.length; i++) {
			nums[i] = new String[n[i]];
		}
		nums[2][0] = nextNumber();
		nums[3][0] = nextNumber();
		curNum = 5000000000L;
		nums[1][0] = nextNumber();
		for (int i = 0; i < n.length; i++) {
			for (int j = (i > 0 && i < 4) ? 1 : 0; j < nums[i].length; j++) {
				nums[i][j] = randNumber(notuse);
			}
		}
		for (int i = 0; i < n.length; i++) {
			List<String> al = Arrays.asList(nums[i]);
			Collections.shuffle(al);
			nums[i] = al.toArray(new String[al.size()]);
		}
		write(nums, nextNumber(), randNumber2(notuse));
	}
	
	static int randNum(int a, int b) {
		return a + random.nextInt(2 * b + 1) - b;
	}
	
	public static void main(String[] args) throws IOException {
		while (new File(String.format("%02d.t", testcount + 1)).exists()) {
			testcount++;
		}
		writeGood(1);
		writeRand(new int[] {1, 1, 1, 1, 1});
		writeRand(new int[] {1, 3, 2, 3, 1});
		writeGoodRand(new int[] {5, 5, 5, 5, 5}, 0);
		writeGood(10);
		//5
		int t = 50;
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				writeRand4(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			} else if (i % 3 == 1) {
				writeRand3(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			} else {
				writeRand(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			}
			t += 15;
		}
		t = 135;
		writeGoodRand(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)}, random.nextInt(Integer.MAX_VALUE));
		writeRand(new int[]{1, 150, 150, 150, 1});
		writeRand(new int[]{1, 248, 249, 1, 1});
		//15
		writeRand(new int[]{1, 1, 249, 248, 1});
		writeRand(new int[]{1, 1, 496, 1, 1});
		writeRand(new int[]{1, 248, 1, 248, 1});
		writeRand(new int[]{randNum(5, 4), randNum(10, 5), randNum(400, 50), randNum(10, 5), randNum(5, 4)});
		writeGoodRand(new int[]{1, 166, 166, 166, 1}, random.nextInt(Integer.MAX_VALUE));
		//20
		t = 1000;
		for (int i = 0; i < 8; i++) {
			if (i % 3 == 0) {
				writeRand4(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			} else if (i % 3 == 1) {
				writeRand3(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			} else {
				writeRand(new int[] {randNum(10, 5), randNum(t, 20), randNum(t, 20), randNum(t, 20), randNum(10, 5)});
			}
			t += 50;
		}
		writeGood(1500);
		writeRand(new int[]{1, 1666, 1666, 1666, 1});
		//30
		t = 25000;
		int t2 = 30000;
		for (int i = 0; i < 5; i++) {
			if (i % 2 == 0 && i != 4) {
				writeRand3(new int[] {randNum(10, 5), randNum(t, 100), randNum(t, 100), randNum(t, 100), randNum(10, 5)});
			} else if (i != 4) {
				writeRand4(new int[] {randNum(10, 5), randNum(t, 100), randNum(t, 100), randNum(t, 100), randNum(10, 5)});
			} else {
				writeRand2(new int[] {randNum(10, 5), randNum(t, 100), randNum(t, 100), randNum(t, 100), randNum(10, 5)});
			}
			writeRand4(new int[] {randNum(10, 5), randNum(t2, 200), randNum(t2, 200), randNum(10, 5), randNum(10, 5)});
			writeRand3(new int[] {randNum(10, 5), randNum(10, 5), randNum(t2, 200), randNum(t2, 200), randNum(10, 5)});
			t += 2000;
			t2 += 4000;
		}
		//45
		writeRand2(new int[] {1, 33333, 33332, 33333, 1});
		writeRand2(new int[] {1, 1, 49998, 49999, 1});
		writeRand2(new int[] {1, 49998, 49999, 1, 1});
		writeGoodRand(new int[] {1, 33333, 33332, 33333, 1}, 0);
		writeGood(33330);
	}

}
