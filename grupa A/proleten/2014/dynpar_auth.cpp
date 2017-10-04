#include<bits/stdc++.h>
using namespace std;
// box structure
struct box{
	int sum,low,high;
	box(int sum=0, int low= 0, int high = 0)
	  : sum(sum), low(low), high(high) {}

	box flip() const {
		return box(-sum, -high, -low);
	}

	bool is_balanced() const {
		return sum == 0 && low == 0;
	}
};

box fix(const box& data, bool flip) {
	return flip ? data.flip() : data;
}

// node - a box that can be flipped
struct node {
	bool flip;
	box data;

	node(bool flip = false, box data = box())
	  : flip(flip), data(data) {}

	box real_data() const {
		return fix(data, flip);
	}
};

box combine(const box& a, const box& b) {
	return box(a.sum + b.sum,
			min(a.low, a.sum + b.low),
			max(a.high, a.sum + b.high));
}

// interval tree
const int max_n = 1 << 19;
int n;
int offset;
int lvl;

node nodes[max_n];

int left(int n, int l) {
	return n << l;
}

int right(int n, int l) {
	return left(n+1, l);
}

// interval bounds
int a, b;

void update(int n, int l) {
	if (a <= left(n, l) && right(n, l) <= b) {
		nodes[n].flip ^= 1;
	} else if (b <= left(n, l) || right(n, l) <= a) {
		// outside
	} else {
		update(n*2, l-1);
		update(n*2+1, l-1);
		nodes[n].data = combine(nodes[2*n].real_data(), nodes[2*n+1].real_data());
	}
}

box get(int n, int l) {
	if (a <= left(n, l) && right(n, l) <= b) {
		return nodes[n].real_data();
	} else if (b <= left(n, l) || right(n, l) <= a) {
		// outside
		return box();
	} else {
		box b_left = get(2*n, l-1);
		box b_right = get(2*n+1, l-1);
		box b = combine(b_left, b_right);
		return fix(b, nodes[n].flip);
	}
}

void print_tree() {
	for (int i = 1; i < 2*offset; ++i) {
		node& n = nodes[i];
		printf("[%2d %2d %2d %2d] ", n.flip, n.data.sum, n.data.low, n.data.high);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	offset = 1;
	lvl = 0;

	while (offset < n) {
		offset *= 2;
		++lvl;
	}

	for (int i = 0; i < n; ++i) {
		char c; scanf(" %c", &c);
		int s = (c == '(') ? 1 : -1;
		nodes[offset + i].data = box(s, min(0, s), max(0, s));
	}

	for (int i = offset - 1; i >= 1; --i) {
		nodes[i].data = combine(nodes[2*i].data, nodes[2*i+1].data);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		char c;
		scanf(" %c%d%d", &c, &a, &b);
		a += offset - 1;
		b += offset;
		if (c == 'u') {
			update(1, lvl);
		} else {
			box g = get(1, lvl);
			printf("%d\n", g.is_balanced());
		}
	}

	return 0;
}
