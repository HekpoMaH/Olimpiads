#include <cstdio>
#include <cstring>
#include <map>
using std::map;

int m, n;

inline int get_bit(int i, int b) {
	return (i >> b) & 1;
}
inline void set_bit(int& i, int b, int val) {
	if(val) {
		i |= 1 << b;
	} else {
		i &= ~(1 << b);
	}
}

char inbuf[32];
struct matrix {
	int rows[32];
	int cols[32];
	
	void read() {
		int j;
		
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));
		
		for(int i = 0; i < n; ++i) {
			scanf("%s", inbuf);
			for(j = 0; j < n; ++j) {
				inbuf[j] -= '0';
				
				rows[i] <<= 1;
				rows[i] |= inbuf[j];
				
				cols[j] <<= 1;
				cols[j] |= inbuf[j];
			}
		}
	}
	
	void rotate() {
		matrix old = *this;
		for(int i = 0; i < n; ++i) {
			rows[i] = old.cols[n-i-1];
			cols[i] = old.rows[i];
		}
	}
	
	void transpond() {
		int tmp, t, l = n>>1;
		for(int i = 0; i < l; ++i) {
			t = n-i-1;
			
			tmp = rows[i];
			rows[i] = rows[t];
			rows[t] = tmp;
		}
	}
	
	bool operator< (const matrix b) const {
		for(int i = 0; i < n; ++i) {
			if(rows[i] > b.rows[i])
				return false;
			if(rows[i] < b.rows[i])
				return true;
		}
		return false;
	}
	
	void minimize() {
		matrix cur = *this;
		
		for(int i = 0; i < 3; ++i) {
			cur.rotate();
			//cur.print();
			if(cur < *this) *this = cur;
		}
		
		cur.transpond();
		//cur.print();
		if(cur < *this) *this = cur;
		
		for(int i = 0; i < 3; ++i) {
			cur.rotate();
			//cur.print();
			if(cur < *this) *this = cur;
		}                
	}
	
	void print() {
		for(int i = 0; i < n; ++i) {
			printf("%d ", rows[i]);
		}
		printf("\n");
	}
};

map<matrix, int> matrices;

int main() {
	scanf("%d%d", &m, &n);
	matrix cm;
	for(int i = 0; i < m; ++i) {
		cm.read();
		cm.minimize();
		++matrices[cm];
	}
	int max = 0;
	for(map<matrix, int>::iterator i = matrices.begin(); i != matrices.end(); ++i) {
		if(i->second > max)
			max = i->second;
	}
	printf("%d\n", max);
	return 0;
}
