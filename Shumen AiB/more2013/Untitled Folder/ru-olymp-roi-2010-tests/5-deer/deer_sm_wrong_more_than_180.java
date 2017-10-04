import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class deer_sm_wrong_more_than_180 {
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

		Point crossNear(Circle c, Point p) {
			Point[] ps = cross(c);
			if (Math.abs(ps[0].dist(p) - ps[1].dist(p)) < EPS) {
				throw new AssertionError();
			}
			if (ps[0].dist(p) < ps[1].dist(p)) {
				return ps[0];
			} else {
				return ps[1];
			}
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

	// правда ли, что p внутри угла a-b-c
	boolean inside(Point p, Point a, Point b, Point c) {
		p = p.subtract(b);
		a = a.subtract(b);
		c = c.subtract(b);
		b = b.subtract(b);
		double v1 = a.vect(p);
		double v2 = c.vect(p);
		return v1 - EPS <= 0 && v2 + EPS >= 0;
	}

	double angle(Point v1, Point v2, int dir) {
		return Math.abs(Math.atan2(v1.vect(v2), v1.scal(v2)));
	}

	void solve() {
		int n = nextInt();
		Point[] p = new Point[n];
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
		Point center = new Point(sx / n, sy / n);

		Point goat = new Point(nextInt(), nextInt());
		int length = nextInt();

//		for (int j = 0; j < p.length; j++) {
//			if (p[j].equals(goat)) {
//				return;
//			}
//		}

		boolean cross = 2 * length > P;
		int pos = -1;
		for (int j = 0; j < p.length; j++) {
			if (new Line(p[j], p[(j + 1) % n]).contain(goat) && !p[(j + 1) % n].equals(goat)) {
				pos = j;
				break;
			}
		}
		double R = Math.atan2(p[(pos + 1) % n].y - center.y, p[(pos + 1) % n].x - center.x) + EPS;
		double L = Math.atan2(p[pos % n].y - center.y, p[pos % n].x - center.x) - EPS;
		if (L > R) {
			L -= 2 * Math.PI;
		}
		if (R < L)
			throw new AssertionError();
		if (cross) {
			for (int it = 0; it < 200; it++) {
				double M = (L + R) / 2;
				Line ray = new Line(center, new Point(center.x + 100 * Math.cos(M), center.y + 100
						* Math.sin(M)));
				Point[] crosses = new Point[2];
				Arrays.fill(crosses, center);
				for (int dir = -1; dir <= 1; dir += 2) {
					double r = length;
					int i;
					if (dir == -1) {
						i = pos;
					} else {
						i = (pos + 1) % n;
					}
					r -= p[i].dist(goat);
					// if (prev.equals(p[i])) {
					// if (dir != 1) {
					// throw new AssertionError();
					// }
					// prev = p[(i + n - 1) % n];
					// }
					wh: while (r > 0) {
						int px;
						if (dir == -1) {
							px = (i + n - 1) % n;
						} else {
							px = (i + 1) % n;
						}
						if (cross) {
							Circle c = new Circle(p[i], r);
							Point[] ps = ray.crossRay(c);
							for (Point candidate : ps) {
								Line line = new Line(p[i], p[px]);
								double vect = line.v.vect(candidate.subtract(p[i]));
								if (vect * dir >= 0) {
									crosses[dir == 1 ? 0 : 1] = candidate;
									break wh;
								}
							}
						}

						r -= p[px].dist(p[i]);
						i = px;
					}

				}

				double x = crosses[0].dist(center) - crosses[1].dist(center);
				if (x > 0) {
					R = M;
				} else {
					L = M;
				}
			}
		}

		double M = L;
		Line ray = new Line(center, new Point(center.x + 100 * Math.cos(M), center.y + 100
				* Math.sin(M)));
		double S = 0;
		int[] last = new int[2];
		Arrays.fill(last, -1);
		Point crossPoint = null;
		for (int dir = -1; dir <= 1; dir += 2) {
			double r = length;
			int i;
			Point pp1 = p[(pos + 1) % n].subtract(p[pos]);
			Point prevvect = new Point(-pp1.y, pp1.x);
			Point prev = goat;
			if (dir == -1) {
				if (!goat.equals(p[pos])) {
					i = (pos + 1) % n;
				} else {
					i = (pos) % n;
				}
			} else {
				if (!goat.equals(p[pos])) {
					i = pos % n;
				} else {
					i = pos;
				}
			}
			if (DEBUG) {
				System.err.println("?" + p[i] + " prevvec = " + prevvect);
				System.err.println(" " + r);
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
				if (cross) {
					Circle c = new Circle(prev, r);
					Point[] ps = ray.crossRay(c);
					if (DEBUG)
						System.err.println(Arrays.toString(ps));
					for (Point candidate : ps) {
						Line line = new Line(prev, p[nx]);
						double vect = line.v.vect(candidate.subtract(prev));
						if (vect * dir >= 0) {
							crossPoint = candidate;
							double angle = angle(prevvect, candidate.subtract(prev), dir);
							if (DEBUG)
								System.err.println("add2 S += " + r * r * angle / 2 + " angle = "
										+ angle);
							S += r * r * angle / 2;
							last[dir == 1 ? 0 : 1] = i;
							if (DEBUG)
								System.err.println("stop");
							break wh;
						}
					}
				}

				Point vec1 = prevvect;
				Point vec2 = p[nx].subtract(prev);
				double angle = angle(vec1, vec2, dir);
				S += r * r * angle / 2;
				if (DEBUG)
					System.err.println("add1 S += " + r * r * angle / 2 + " angle = " + angle);
				r -= p[nx].dist(prev);
				prevvect = vec2;
				i = nx;
				prev = p[nx];
			}

			if (DEBUG)
				System.err.println("----");
		}

		if (DEBUG)
			System.err.println(last[0] + " " + last[1]);
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
		double ans = S + STR;
		if (DEBUG)
			System.err.println(p[pos] + " -- " + goat);
		if (DEBUG)
			System.err.println(ans);
		System.out.println(ans);
		out.println(ans);
		// System.err.println(M + " " + ray);
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
		new deer_sm_wrong_more_than_180().run();
	}
}
