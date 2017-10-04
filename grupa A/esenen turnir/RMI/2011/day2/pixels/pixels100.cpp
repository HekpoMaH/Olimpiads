#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 111

using namespace std;

int N, flow;

#define oo (1<<30)
#define SOURCE 0
#define PIXEL(XX,YY) ((XX-1)*N + YY)
#define SINK (N * N + 1)

int q[MAX_N*MAX_N+1];
int u[MAX_N*MAX_N+1];
int min_flow[MAX_N*MAX_N+1];
int prec[MAX_N*MAX_N+1];

int MATR[MAX_N][MAX_N][4];
int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];

vector<int> g[MAX_N*MAX_N+1];
vector<int> cap[MAX_N*MAX_N+1];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void add_uni_edge(int x, int y, int c) {
	g[x].push_back(y);
	cap[x].push_back(c);
}

void add_edge(int x, int y, int c) {
	g[x].push_back(y);
	g[y].push_back(x);
	cap[x].push_back(c);
	cap[y].push_back(c);
}
int merge() {
	int l, r;
	memset(u, 0, sizeof(u));
	memset(min_flow, 0, sizeof(min_flow));
	memset(prec, -1, sizeof(prec));
	
	q[l=r=0] = SOURCE;
	u[SOURCE] = 1;
	min_flow[SOURCE] = oo;
	
	for (; l <= r; ++l) {
		int el = q[l];
		
		
		for (int i = 0; i < g[el].size(); ++i) {
			int nel = g[el][i];
			int ncap = cap[el][i];
			
			if (!u[nel] && ncap > 0) {
				min_flow[nel] = min(min_flow[el], ncap);
				prec[nel] = el;
				u[nel] = 1;
				q[++r] = nel;
			}
		}
	}
	
	if (min_flow[SINK]) {
		return 1;
	}
	
	return 0;
}

inline int get_index(int x, int nx) {
	if (x == SINK) {
		return nx - 1;
	}
	if (x == SOURCE)
		return nx - 1;
	int index = -1;
	for (index = 0; index < g[x].size(); ++index)
		if (g[x][index] == nx)
			return index;
}

void baga() {	
	for (int i = 0; i < g[SINK].size(); ++i) {
	  int el = g[SINK][i];
		int in = get_index(el, SINK);
		int max_cap = cap[ el ][ in ];
		
		if (max_cap == 0)
			continue;
		
		for (int x = el; prec[x] >= 0; x = prec[x]) {
			int index = get_index(prec[x], x);
			max_cap = min(max_cap, cap[prec[x]][index]);
		}
		
		if (max_cap == 0)
			continue;
		
		for (int x = el; prec[x] >= 0; x = prec[x]) {
			int nx = prec[x];
			int index = get_index(x, nx);
			cap[x][index] += max_cap;
			index = get_index(nx, x);
			cap[nx][index] -= max_cap;
		}
		
		cap[ g[SINK][i] ][ in ] -= max_cap;
		cap[ SINK ][ i ] += max_cap;
		
		flow += max_cap;
	}
}

int main() {
	int tot_sum = 0;
	
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A[i][j]);
			tot_sum += A[i][j];
		}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &B[i][j]);
			tot_sum += B[i][j];
		}
		
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 0; k < 4; ++k)
				scanf("%d", &MATR[i][j][k]);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			add_edge(SOURCE, PIXEL(i, j), A[i][j]);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			add_edge(PIXEL(i, j), SINK, B[i][j]);
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 0; k < 4; ++k)
				if (i + dx[k] >= 1 && i + dx[k] <= N && j + dy[k] >= 1 && j + dy[k] <= N)
					add_uni_edge(PIXEL(i, j), PIXEL(i + dx[k], j + dy[k]), MATR[i][j][k]); 
	
	while(merge())
		baga();
		
			
	printf("%d\n", tot_sum - flow);
	
	return 0;
}

