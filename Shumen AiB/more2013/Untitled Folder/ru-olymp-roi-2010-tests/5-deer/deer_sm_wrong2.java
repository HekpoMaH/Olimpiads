import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class deer_sm_wrong2 {
	final boolean DEBUG = false;
	final double EPS = 1e-8;

	class Point {
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		double dist2(Point p) {
			return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
		}

		Point subtract(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		Point add(Point p) {
			return new Point(x + p.x, y + p.y);
		}

		Point norm() {
			double len = Math.sqrt(x * x + y * y);
			return new Point(x / len, y / len);
		}

		double vect(Point p) {
			return x * p.y - y * p.x;
		}

		double dist(Point p) {
			return Math.sqrt(dist2(p));
		}

		@Override
		public boolean equals(Object obj) {
			Point other = (Point) obj;
			return (Math.abs(x - other.x) < EPS) && (Math.abs(y - other.y) < EPS);

		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

		public double scal(Point v2) {
			return x * v2.x + y * v2.y;
		}

		@Override
		public int hashCode() {
			return 0;
		}

	}

	public class Line {
		Point a;
		Point b;
		Point v; // = b - a

		public Line(Point a, Point b) {
			this.a = a;
			this.b = b;
			v = new Point(b.x - a.x, b.y - a.y);
		}

		public Line(Point a, Point v, boolean nothing) {
			this.a = a;
			this.b = v;
			b = new Point(a.x + v.x, a.y + v.y);
		}

		Point[] cross(Circle c) {
			double A = v.x * v.x + v.y * v.y;
			double B = 2 * (a.x - c.center.x) * v.x + 2 * (a.y - c.center.y) * v.y;
			double C = (a.x - c.center.x) * (a.x - c.center.x) + (a.y - c.center.y)
					* (a.y - c.center.y) - c.r * c.r;
			double D = Math.sqrt(B * B - 4 * A * C);
			double t1 = (-B + D) / (2 * A);
			double t2 = (-B - D) / (2 * A);
			Point a1 = new Point(a.x + t1 * v.x, a.y + t1 * v.y);
			Point b1 = new Point(a.x + t2 * v.x, a.y + t2 * v.y);
			return new Point[] { a1, b1 };
		}

		public Point[] crossRay(Circle c) {
			Point[] p = cross(c);
			ArrayList<Point> ans = new ArrayList<Point>();
			for (int i = 0; i < p.length; i++) {
				if (!new Line(p[i], b).contain(a)) {
					ans.add(p[i]);
				}
			}
			return ans.toArray(new Point[0]);
		}

		boolean contain(Point p) {
			return Math.abs(a.dist(p) + p.dist(b) - a.dist(b)) < EPS;
		}

		@Override
		public String toString() {
			return "[" + a + " -- " + b + "]";
		}

	}

	class Circle {
		Point center;
		double r;

		public Circle(Point center, double r) {
			super();
			this.center = center;
			this.r = r;
		}

	}

	double angle(Point v1, Point v2, int dir) {
		double a = Math.atan2(v1.vect(v2), v1.scal(v2)) * -dir;
		if (a < 0) {
			a += 2 * Math.PI;
		}
		return a;
	}

	int n;
	Point[] p;
	Point center, goat;
	double length;
	int pos;
	boolean cross;
	Point crossPoint;

	void solve() {
		n = nextInt();
		p = new Point[n];
		double sx = 0;
		double sy = 0;
		double P = 0;
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(nextInt(), nextInt());
			sx += p[i].x;
			sy += p[i].y;
		}

		for (int i = 0; i < p.length; i++) {
			P += p[i].dist(p[(i + 1) % n]);
		}
		center = new Point(sx / n, sy / n);

		goat = new Point(nextInt(), nextInt());
		length = nextInt();
		System.err.println(length);
		System.err.println(P / 2);
		System.err.println(length - P / 2);

		// for (int j = 0; j < p.length; j++) {
		// if (p[j].equals(goat)) {
		// return;
		// }
		// }

		cross = 2 * length > P;
		pos = -1;
		for (int j = 0; j < p.length; j++) {
			if (new Line(p[j], p[(j + 1) % n]).contain(goat) && !p[(j + 1) % n].equals(goat)) {
				pos = j;
				break;
			}
		}
		double R = Math.atan2(p[(pos + 1) % n].y - center.y, p[(pos + 1) % n].x - center.x);
		double L = Math.atan2(p[pos % n].y - center.y, p[pos % n].x - center.x);
		if (L > R) {
			L -= 2 * Math.PI;
		}
		if (R < L)
			throw new AssertionError();
		last = new int[2];
		if (cross) {
			double M = (L + R) / 2;
			while (L != M && R != M) {
				double x = calcDiff(M);
				System.err.println();
				System.err.println("M = " + M + " L = " + L + " R = " + R);
				System.err.println("x = " + x + " " + calcDiff(L) + " " + calcDiff(R));
				calcDiff(L);
				System.err.println(Arrays.toString(last));
				calcDiff(R);
				System.err.println(Arrays.toString(last));

				System.err.println();
				if (DEBUG) {
				}
				if (x > 0) {
					R = M;
				} else {
					L = M;
				}
				M = (L + R) / 2;
			}
		}

		double M = L;
		for (int i = -10; i <= 10; i++) {
			double x = M + 1e-10 * i;
			System.err.println(x + " " + calcDiff(x));
			System.err.println();
			System.err.println();
		}

		last = new int[2];
		Arrays.fill(last, -1);
		crossPoint = null;
		S = 0;
		double xx = calcDiff(M);
		// if (Math.abs(xx) > EPS) throw new AssertionError();
		if (DEBUG) {
			System.err.println(crossPoint + " " + S);
			System.err.println(last[0] + " " + last[1]);
		}
		double STR = 0;
		if (cross) {
			for (int i = last[0]; i != last[1]; i = (i + 1) % n) {
				if (DEBUG) {
					System.err.println(p[i] + " " + p[(i + 1) % n] + " " + crossPoint);
				}
				double Ss = Math.abs(p[i].subtract(crossPoint).vect(
						p[(i + 1) % n].subtract(crossPoint))) / 2;
				if (DEBUG)
					System.err.println("Str  += " + Ss);
				STR += Ss;
			}
		}
		if (DEBUG)
			System.err.println(STR);
		double ans = S + STR;
		if (DEBUG)
			System.err.println(p[pos] + " -- " + goat);
		if (DEBUG)
			System.err.println(ans);
		System.out.printf(Locale.US, "%.5f\n", ans);
		out.printf(Locale.US, "%.5f\n", ans);
		// System.err.println(M + " " + ray);
	}

	double S;
	int[] last;

	private double calcDiff(double M) {
		Line ray = new Line(center, new Point(center.x + Math.cos(M), center.y + Math.sin(M)));
		Point[] crosses = new Point[2];
		Arrays.fill(crosses, center);

		for (int dir = -1; dir <= 1; dir += 2) {
			double r = length;
			int i;
			Point prev = goat;
			Point pp1 = p[(pos + 1) % n].subtract(p[pos]).norm();
			Point prevvect = new Point(-pp1.y, pp1.x).norm();

			if (dir == -1) {
				if (!goat.equals(p[pos])) {
					i = (pos + 1) % n;
				} else {
					i = (pos) % n;
				}
			} else {
				i = pos;
			}
			wh: while (r > 0) {
				if (DEBUG)
					System.err.println("R = " + r);
				int nx;
				if (dir == -1) {
					nx = (i + n - 1) % n;
				} else {
					nx = (i + 1) % n;
				}
				if (DEBUG)
					System.err.println("px " + p[nx]);
				Point curVect = p[nx].subtract(prev).norm();
				if (cross) {
					Circle c = new Circle(prev, r);
					Point[] ps = ray.crossRay(c);
					if (DEBUG)
						System.err.println(Arrays.toString(ps));
					for (Point candidate : ps) {
						Point crossVect = candidate.subtract(prev).norm();
						double vect1 = crossVect.vect(prevvect);
						double vect2 = crossVect.vect(curVect);
						// System.err
						// .println(prevvect + " " + line.v + " " +
						// candidate.subtract(prev));
						// System.err.println(vect1 + " " + vect2);
						if (vect1 * dir >= 0 && vect2 * dir <= 0) {
							// System.err.println("+");
							// System.err.println(vect * dir);
							double angle = angle(prevvect, crossVect, dir);
							S += r * r * angle / 2;
							last[dir == 1 ? 0 : 1] = i;
							crosses[dir == 1 ? 0 : 1] = candidate;
							System.err.println("dir = " + dir + " " + candidate + " on edge "
									+ prev + "-" + p[nx]);
							crossPoint = candidate;
							break wh;
						}
					}
				}

				Point vec1 = prevvect;
				double angle = angle(vec1, curVect, dir);
				S += r * r * angle / 2;
				r -= p[nx].dist(prev);
				i = nx;
				prev = p[nx];
				prevvect = curVect;
			}

			if (DEBUG)
				System.err.println("----");
		}
		System.err.println(Arrays.toString(crosses));
		System.err.println("dist0  = " + crosses[0].dist(center) + " dist1 = "
				+ crosses[1].dist(center));
		double x = crosses[0].dist(center) - crosses[1].dist(center);
		return x;
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			br = new BufferedReader(new FileReader("deer.in"));
			out = new PrintWriter("deer.out");
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
		new deer_sm_wrong2().run();
	}
}
