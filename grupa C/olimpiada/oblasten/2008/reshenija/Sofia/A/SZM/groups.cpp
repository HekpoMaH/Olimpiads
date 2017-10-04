#include <cstdio>

int n, p;
double a[500];
int f[500];
int fl;

double d(int i, int j) {
	double result = 0;
	for (int p = i; p < j; ++p) {
		result += a[p];
	}
	result *= result;
	result /= (j-i);
	result = -result;
	for (int p = i; p < j; ++p) {
		result += a[p]*a[p];
	}	
	return result;
}

void insert (int x, int i) {
	for (int k = fl; k >= i; --k)
		f[k] = f[k-1];
	f[i] = x;
	fl++;
}

int main () {
	
	scanf ("%d %d", &n, &p);
    for (int i = 0; i < n; ++i)
		scanf ("%lf", &a[i]);

	double intrvl = (a[n-1] - a[0] + 1) / p;
	
	f[0] = 0;
	int c = a[0] + intrvl;
	
	int nxt = 1;
	
	for (int i = 0; i < n; ++i)
		if (a[i] > c) {
			f[nxt++] = i;
			c += intrvl;
			if (nxt == p) break;
		}
	f[p] = n;
	
	double D = 0;
	
	for (int i = 0; i < p; ++i)
		D += d(f[i], f[i+1]);
		
	printf ("%.4lf\n", D);	

	return 0;
}
