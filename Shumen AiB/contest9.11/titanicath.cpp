/*
TASK: titanic
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <map>

using std::make_pair;

const int WORST = INT_MIN;
enum go_t { LEFT, RIGHT } go;

int n, m; // board size
int x, y; // bottom left corner of current region
int xn, yn; // size of current region - initially the hole board
int xm, ym, vm; // location and value of current optimum
bool flip;

bool xcmp(int d1, int d2) {
	return d1 > d2;
}

void init(int *n, int *m) {
	scanf("%d %d", n, m);
}

int tell(int x, int y) {
	printf("%d %d %d\n", 0, x, y); fflush(stdout);
	scanf("%d", &x);
	return x;
}

void answer(int x, int y) {
	printf("1 %d %d\n", x, y); fflush(stdout);
	exit(0);
}


int xtell(int x, int y) {
	static std::map <std::pair <int, int>, int> db;
	static std::map <std::pair <int, int>, int> :: iterator it;
	if (flip) { int t = x; x = y; y = t; }
	if (x < 0 || x >= n
	 || y < 0 || y >= m)
		return WORST;

	if ((it = db.find (make_pair (x, y))) != db.end ())
		return it->second;
	else
		return db[make_pair (x, y)] = tell (x, y);
}

void xanswer(int x, int y) {
	if (flip) { int t = x; x = y; y = t; }
	answer(x, y);
}

void step(int &x, int &y, int &xn, int &yn, int &xm, int &ym) {
	int cx, cy; // current optimum
	int cut; // offset of cutting line
	int cvm; // value of current optimum

	cut = x + xn / 2;
	cx = cut, cy = -1;
	cvm = WORST;
	for (int i = 0; i < yn; ++i) {
		if (xcmp(xtell(cut, y + i), cvm)) {
			cvm = xtell(cut, y + i);
			cy = y + i;
		}
	}

	if (xcmp(cvm, vm)) {
		xm = cx;
		ym = cy;
		vm = cvm;
		if (xcmp(xtell(cx - 1, cy), cvm)) {
			go = LEFT;
		} else if (xcmp(xtell(cx + 1, cy), cvm)) {
			go = RIGHT;
		} else {
			xanswer(cx, cy);
		}
	} else {
		if (xm < cut) {
			go = LEFT;
		} else {
			go = RIGHT;
		}
	}
	if (go == LEFT) {
		xn = cut - x;
	} else {
		xn -= cut - x + 1;
		x = cut + 1;
	}
}

int main() {
	setvbuf(stdout, NULL, _IOLBF, 0);
	init(&n, &m);
	x = y = 0;
	xn = n; yn = m;
	xm = ym = -1;
	vm = WORST;
	while (xn * yn >= 1) {
		if (xn > yn) {
			flip = 0;
			step(x, y, xn, yn, xm, ym);
		} else {
			flip = 1;
			step(y, x, yn, xn, ym, xm);
		}
	}
	answer(x, y);

	return 0;
}
