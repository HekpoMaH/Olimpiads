#include <iostream.h>
#include <math.h>
int main (void)
 {
 int i, j, groupunits;
 double a[500], s[500], sa[500], sum = 0, n, p;

 cin >>n>>p;
 for(i = 0; i < n; i++) cin>>a[i];
 groupunits = ceil(n/p);
// cout<<"google:"<<groupunits;

 i = 0;
 while(i<p) {
	j = 0;
	while(j<groupunits) {
		s[i] += a[i * groupunits + j];
		j++;
	}

	if (i == p - 1) {
		s[i] = s[i] / (int(n) % int(groupunits));
	}
	else s[i] /= groupunits;

	j = 0;
	while(j < groupunits) {
		if ((i * groupunits + j) < n) sa[i] += (a[i * int(groupunits) + j] - s[i])*(a[i * int(groupunits) + j] - s[i]);
		j++;
	}
	i++;
}

i = 0;
while(i < n) {
	sum += sa[i];
	i++;
}

cout<<sum;
 return 0;
 }