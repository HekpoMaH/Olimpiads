#include <iostream>
#include <string.h>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

struct Meadow {
	int n, m, vn, lowerLayer, source, sink;
	bool **edge;
	bool **flow;

	Meadow(vector<string>& cats) {
		n = cats.size();
		m = 0;
		for (vector<string>::iterator i = cats.begin(); i != cats.end(); i++) {
			m = max(m, (int) i->size());
		}
		// 2 vertices per meadow cell, one source, one sink
		vn = n * m * 2 + 1 + 1;
		lowerLayer = n * m;
		source = lowerLayer + n * m;
		sink = source + 1;
		// initialize edge and flow arrays
		edge = new bool*[vn];
		flow = new bool*[vn];
		for (int i = 0; i < vn; i++) {
			edge[i] = new bool[vn];
			memset(edge[i],0,vn);
			flow[i] = new bool[vn];
			memset(flow[i],0,vn);
		}
		// create edges
		int c = 0;
  	for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k1 = i * m + j;
				int k2 = lowerLayer + k1;
				// edge from the upper layer vertex to the lower layer vertex
				edge[k1][k2] = true;
				// edges from lower layer vertex to neightbors' upper layer vertices
				if ((i > 0) && (cats[i - 1][j] == '0')) edge[k2][(i - 1) * m + j] = true;
				if ((j > 0) && (cats[i][j - 1] == '0')) edge[k2][i * m + j - 1] = true;
				if ((i < n - 1) && (cats[i + 1][j] == '0')) edge[k2][(i + 1) * m + j] = true;
				if ((j < m - 1) && (cats[i][j + 1] == '0')) edge[k2][i * m + j + 1] = true;
				// edge from source to cell with cat
				if (cats[i][j] == '1') { edge[source][k1] = true; c++; }
				// edge from border cell to sink
				if ((i == 0) || (j == 0) || (i == n - 1) || (j == m - 1)) edge[k2][sink] = true;
			}
		}
	}

	~Meadow() {
		for (int i = 0; i < vn; i++) {
			delete[] edge[i];
			delete[] flow[i];
		}
		delete[] edge;
		delete[] flow;
	}

	// depth-first search for a path from v to the sink in the residual flow graph
	bool findPathToSink(hash_set<int>& visited, int v) {
		if (v == sink) return true;
		if (visited.find(v) != visited.end()) return false;
		visited.insert(v);
		// first try going straight to the sink
		if ((v >= lowerLayer) && (v < source)) {
			if (goForward(visited, v, sink)) return true;
		}
		if (v >= lowerLayer) {
			// go forward from a lower layer cell or source to an upper layer one
			for (int w = 0; w < lowerLayer; w++) {
				if (goForward(visited, v, w)) return true;
			}
			// go backward from a lower layer cell to its higer layer one
			if ((v < source) && (goBackward(visited, v, v - lowerLayer))) return true;
		} else {
			// go forward from an upper layer cell to its corresponding lower layer one
			if (goForward(visited, v, v + lowerLayer)) return true;
			// go backward to neighboring lower layer cells, but not the source
			for (int w = lowerLayer; w < source; w++) {
				if (goBackward(visited, v, w)) return true;
			}
		}
		return false;
	}

	// try going forward along an edge from v to w that currently has no flow
	bool goForward(hash_set<int>& visited, int v, int w) {
		if ((edge[v][w]) && (!flow[v][w])) {
			flow[v][w] = true;
			if (findPathToSink(visited, w)) return true;
			flow[v][w] = false;
		}
		return false;
	}

	// try going backward along an edge from w to v that currently has flow
	bool goBackward(hash_set<int>& visited, int v, int w) {
		if ((edge[w][v]) && (flow[w][v])) {
			flow[w][v] = false;
			if (findPathToSink(visited, w)) return true;
			flow[w][v] = true;
		}
		return false;
	}

	// returns the maximum number of cats that can escape the meadow
	int solve() {
		int count = 0;
		hash_set<int> visited;
		while (findPathToSink(visited, source)) {
			count++;
			visited.clear();
		}
		return count;
	}
};

void readLines(istream& input, vector<string>& lines) {
	string s;
	lines.clear();
  int n;
  input>>n;
	for (int i = 0; i < n; i++) {
    input>>s;
		lines.push_back(s);
	}
}

int main(void) {
	vector<string> cats;
	readLines(cin, cats);
	cout << Meadow(cats).solve()<<endl;
	return 0;
}
