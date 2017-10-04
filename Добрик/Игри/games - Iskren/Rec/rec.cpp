/*
TASK: rec
LANG: C++

FROM: IOI 2005 day 2
PROB: rec
KEYW: sum of games, sg theory
*/

#include "creclib.h"

int sg (int x) {return x & 1 ? sg (x / 2) : x / 2;}
int fnd (int x, int y) {int c; for (c = x * 2; c < y; c = c * 2 + 1); return c / 2;}

int main () {
	int x, y;
	int sgx, sgy;
	for (;;) {
		sgx = sg (x = dimension_x ());
		sgy = sg (y = dimension_y ());
		if (sgx > sgy)
			cut (vertical, fnd (sgy, x));
		else
			cut (horizontal, fnd (sgx, y));
	}
	return 0;
}
