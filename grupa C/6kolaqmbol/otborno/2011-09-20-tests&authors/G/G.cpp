#include <iostream>
using namespace std;

void solve() {
int a, b, br = 1, p;

scanf("%d%d", &a, &b);
if(a == b) { printf("1\n"); return; }

b /= a;

//barzo reshenie
for(p = 2; p * p <= b && b > 1; p++) 
        while (b > 1 && b % p == 0) b /= p, br++;
if(b == 1) printf("%d\n", br);
else printf("%d\n", br+1);

//bavno reshenie:
/*
for(p = 2; p <= b; p++)
while(b > 1 && b % p == 0) b /= p, br++;
printf("%d\n", br);
*/
}

int main()
{
int T;

scanf("%d", &T);
for(; T; --T) solve();
return 0;    
}
