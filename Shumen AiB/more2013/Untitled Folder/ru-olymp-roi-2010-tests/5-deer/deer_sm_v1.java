import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class deer_sm_v1 {
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

	// угол a - b - c
	double angle(Point a, Point b, Point c) {
		double ac = a.dist(c);
		double ab = a.dist(b);
		double bc = b.dist(c);
		return Math.acos((-ac * ac + ab * ab + bc * bc) / (2 * ab * bc));
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

	double angle(Point v1, Point v2) {
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
		System.err.println("center = " + center);
		Point goat = new Point(nextInt(), nextInt());
		int length = nextInt();
		boolean cross = 2 * length > P;
		int pos = -1;
		for (int j = 0; j < p.length; j++) {
			if (new Line(p[j], p[(j + 1) % n]).contain(goat)) {
				pos = j;
				break;
			}
		}
		System.err.println(p[pos] + " " + p[(pos + 1) % n]);
		System.err.println(center);
		double R = Math.atan2(p[(pos + 1) % n].y - center.y, p[(pos + 1) % n].x - center.x) + EPS;
		double L = Math.atan2(p[pos % n].y - center.y, p[pos % n].x - center.x) - EPS;
		if (L > R) {
			L -= 2 * Math.PI;
		}
		System.err.println("L = " + R + " R = " + L);
		if (R < L)
			throw new AssertionError();
		Point crossPoint = null;
		for (int it = 0; it < 200; it++) {
			System.err.println(L + " " + R);
			double M = (L + R) / 2;
			Line ray = new Line(center, new Point(center.x + 100 * Math.cos(M), center.y + 100
					* Math.sin(M)));
			Point cross1 = center;
			{
				Point prev = goat;
				double r = length;
				int i = (pos + 1) % n;
				wh: while (r >= 0) {
					Circle c = new Circle(prev, r);
					// Line thisLine = new Line(prev, p[i]);
					// Point cp = thisLine.crossNear(c, p[i]);
					int px = (i + 1) % n;
					Point[] ps = ray.crossRay(c);
					for (Point candidate : ps) {
						Line line = new Line(prev, p[i]);
						double vect = line.v.vect(candidate.subtract(prev));
						if (vect >= 0) {
							cross1 = candidate;
							break wh;
						}
					}
					r -= prev.dist(p[i]);
					prev = p[i];
					i = px;
				}
			}
			Point cross2 = center;
			{
				Point prev = goat;
				double r = length;
				int i = pos;
				wh: while (r >= 0) {
					Circle c = new Circle(prev, r);
					// Line thisLine = new Line(prev, p[i]);
					// Point cp = thisLine.crossNear(c, p[i]);
					int px = (i + n - 1) % n;
					Point[] ps = ray.crossRay(c);

					for (Point candidate : ps) {
						Line line = new Line(prev, p[i]);
						double vect = line.v.vect(candidate.subtract(prev));
						System.err.println("candidate = " + candidate + " vect = " + vect);

						if (vect <= 0) {
							cross2 = candidate;
							crossPoint = candidate;
							break wh;
						}
					}
					System.err.println("cut " + prev.dist(p[i]));
					r -= prev.dist(p[i]);
					prev = p[i];
					i = px;
				}
			}
			System.err
					.println("dist1 = " + cross1.dist(center) + " dist2 = " + cross2.dist(center));
			// System.err.println("!!!!! " + cross1);
			double x = cross1.dist(center) - cross2.dist(center);
			// if (x > prevAns) {
			// throw new AssertionError();
			// }
			// prevAns = x;
			if (x > 0) {
				R = M;
			} else {
				L = M;
			}
			System.err.println("M = " + M + " x = " + x + "  ray = " + ray);
		}
		double M = L;
		System.err.println(R);
		Line ray = new Line(center, new Point(center.x + 100 * Math.cos(M), center.y + 100
				* Math.sin(M)));
		double SL = 0;
		int lastl = -1;
		{
			Point prev = goat;
			double r = length;
			int i = (pos + 1) % n;
			r -= p[i].dist(goat);
			wh: while (r >= 0) {
				int px = (i + 1) % n;
				System.err.println("See at " + p[i] + " " + p[px]);
				if (cross) {
					Circle c = new Circle(p[i], r);
					Point[] ps = ray.cross(c);
					System.err.println(Arrays.toString(ps));
					for (Point candidate : ps) {
						Line line = new Line(p[i], p[px]);
						double vect = line.v.vect(candidate.subtract(p[i]));
						if (vect >= 0) {
							double angle = angle(p[i].subtract(prev), candidate.subtract(p[i]));
							System.err.println("add SL += " + r * r * angle / 2);
							SL += r * r * angle / 2;
							lastl = i;
							System.err.println("stop");
							break wh;
						}
					}
				}

				Point vec1 = p[i].subtract(prev);
				Point vec2 = p[px].subtract(p[i]);
				double angle = angle(vec1, vec2);
				System.err.println("prev = " + prev + " p[i] = " + p[i] + " p[px] = " + p[px]);
				System.err.println("vec1 = " + vec1 + " vec2 = " + vec2);
				System.err.println("angle " + angle);
				System.err.println("add SL += " + r * r * angle / 2);
				SL += r * r * angle / 2;

				r -= p[px].dist(p[i]);
				prev = p[i];
				i = px;
			}

		}
		System.err.println(" ---- ");
		double SR = 0;
		int lastr = -1;
		{
			Point prev = goat;
			double r = length;
			int i = pos;
			r -= p[i].dist(goat);
			wh: while (r >= 0) {
				int px = (i + n - 1) % n;
				System.err.println("See at " + p[i] + " " + p[px]);
				if (cross) {
					Circle c = new Circle(p[i], r);
					Point[] ps = ray.cross(c);
					System.err.println(Arrays.toString(ps));
					for (Point candidate : ps) {
						Line line = new Line(p[i], p[px]);
						double vect = line.v.vect(candidate.subtract(p[i]));
						if (vect <= 0) {
							double angle = angle(p[i].subtract(prev), candidate.subtract(p[i]));
							System.err.println("add SR += " + r * r * angle / 2);
							SR += r * r * angle / 2;
							lastr = i;
							System.err.println("stop");
							break wh;
						}
					}
				}
				Point vec1 = p[i].subtract(prev);
				Point vec2 = p[px].subtract(p[i]);
				double angle = angle(vec1, vec2);
				System.err.println("vec1 = " + vec1 + " vec2 = " + vec2);
				System.err.println("angle = " + angle);
				System.err.println("add SR += " + r * r * angle / 2);
				SR += r * r * angle / 2;

				r -= p[px].dist(p[i]);
				prev = p[i];
				i = px;
			}

		}
		double STR = 0;
		if (crossPoint != null) {
			for (int i = lastl; i != lastr; i = (i + 1) % n) {
				double S = Math.abs(p[i].subtract(crossPoint).vect(
						p[(i + 1) % n].subtract(crossPoint))) / 2;
				System.err.println("Str  += " + S);
				STR += S;
			}
		}
		double ans = SL + SR + STR + length * length * Math.PI / 2;
		System.err.println(ans);
		out.println(ans);
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
		new deer_sm_v1().run();
	}
}
