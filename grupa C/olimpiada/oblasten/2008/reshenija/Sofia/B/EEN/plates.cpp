/*
NAME:	Emil Evgeniev Nikolov
SCHOOL:	SMG
TASK:	stamps
LANG:	C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <algorithm>

int m, n;
//char plates[1024][32][32];
char **plate;
int ct;
char **types[1024];
char c;

char** rotate1(char **a) {
	char **res = (char**)malloc(sizeof(char*) * n);
	for(int i = 0; i < n; ++i) {
		res[i] = (char*)malloc(sizeof(char) * n);
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			res[i][j] = a[j][i];
		}
		res[i][n] = 0;
	}
	
	return res;
}

char** rotate2(char **a) {
	char **res = (char**)malloc(sizeof(char*) * n);
	for(int i = 0; i < n; ++i) {
		res[i] = (char*)malloc(sizeof(char) * n);
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			res[i][j] = a[n - i - 1][n - j - 1];
		}
		res[i][n] = 0;
	}
	
	return res;
}

char** rotate3(char **a) {
	char **res = (char**)malloc(sizeof(char*) * n);
	for(int i = 0; i < n; ++i) {
		res[i] = (char*)malloc(sizeof(char) * n);
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			res[i][j] = a[n - j - 1][i];
		}
		res[i][n] = 0;
	}
	
	return res;
}

char** swap(char **a) {
	char **res = (char**)malloc(sizeof(char*) * n);
	for(int i = 0; i < n; ++i) {
		res[i] = (char*)malloc(sizeof(char) * n);
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			res[i][j] = a[n - i - 1][j];
		}
		res[i][n] = 0;
	}
	
	return res;
}

bool equal2(char **a, char **b) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(a[i][j] != b[i][j]) return false;
		}
	}
	
	return true;
}

bool equal(char **a, char **b) {
	if(equal2(a, b)) return true;
	
	else if(equal2(swap(a), b)) return true;
	
	else if(equal2(rotate1(a), b)) return true;
	else if(equal2(rotate2(a), b)) return true;
	else if(equal2(rotate3(a), b)) return true;

	else if(equal2(rotate1(swap(a)), b)) return true;
	else if(equal2(rotate2(swap(a)), b)) return true;
	else if(equal2(rotate3(swap(a)), b)) return true;
	
	else return false;
	
}

void copy(char **from) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
//			puts(from[i]);
//			printf("%c\n", from[i][j]);
			types[ct][i][j] = from[i][j];
		}
		
		types[ct][i][n] = 0;
	}
	
	++ct;
}

int main() {
//	freopen("plates.in", "r", stdin);
//	freopen("plates.out", "w", stdout);
	bool eq = 0;
	scanf("%d%d", &m, &n);
	
	types[1024] = (char**)malloc(sizeof(char*) * 32);
	for(int i = 0; i < 32; ++i) {
		types[1024][i] = (char*)malloc(sizeof(char) * 32);
	}
	
	plate = (char**)malloc(sizeof(char*) * 32);
	for(int i = 0; i < 32; ++i) {
		plate[i] = (char*)malloc(sizeof(char) * 32);
	}
	
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				c = getc(stdin);
				if(c == '\n') c = getc(stdin);
				plate[j][k] = c;
//				printf("%c", c);
			}
			plate[i][n] = 0;
//			printf("\n");
//			puts(plate[i]);
		}
//		printf("here...");
		for(int j = 0; j < ct; ++j) {
			if(!equal(plate, types[j])) {
				eq = false;
			}
			else {
				eq = true;
				break;
			}
		}
		if(eq == false) {
			copy(plate);
			//types[ct++] = plate;
		}
	}
	
	printf("%d\n", ct);
	
	return 0;
}
