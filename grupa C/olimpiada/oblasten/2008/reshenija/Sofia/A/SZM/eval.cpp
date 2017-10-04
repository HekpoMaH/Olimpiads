#include <cstdio>
#include <cstring>

int comp (char *a) {
	int rslt = 1;
	int n = 0, p = 0;
	for (int i = 0; i < strlen (a); ++i) {
		if (a[i] == '/' && a[i+2] == '*') {++p; ++n;}
		if ((a[i] == '*') || (a[i] == '/' && a[i+2] != '*' && a[i+2] != '/')) ++n;
	}
	for (int i = 0; i < p; ++i)
		rslt *= (n-2*i) * (n-2*i - 1) / 2;
	for (int i = n - 2*p; i > 1; --i)
		rslt *= i;
		
	n = 0, p = 0;
	for (int i = 0; i < strlen (a); ++i) {
		if (a[i] == '-' && a[i+2] == '+') {++p; ++n;}
		if ((a[i] == '+') || (a[i] == '-' && a[i+2] != '+' && a[i+2] != '-')) ++n;
	}
	for (int i = 0; i < p; ++i)
		rslt *= (n-2*i) * (n-2*i - 1) / 2;
	for (int i = n - 2*p; i > 1; --i)
		rslt *= i;
		
	return rslt;
}

int main () {
	char eval[32];
	scanf ("%s", eval);
	int li = 0;
	long long answ = 1;
	
	printf ("%d\n", comp (eval));
	return 0;
}
	
	
