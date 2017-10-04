#include <iostream>
#include <vector>
using namespace std;
vector <int> c;
unsigned long long b,d;
bool f=false,z1=false;
long long d1=0,d2=0;
void cif(int k)
{
	if (k==0) {
		if (c[c.size()-1]==0) { f=true; return; }
		c.push_back(0);
		return;
	}
	if (c.size()>10 && z1==false) {
			for(int l=0;l<10;l++)
				d1=d1*10+c[l]; z1=true; }
	unsigned long long p[10],z=0;
	while (k) {
		p[z]=k%10;
		k/=10;
		z++;
	}
	for (int i=z-1;i>=0;i--){
		int g=c.size();
		c.push_back(p[i]);
		if (g>10)
		{
		d2=0;
		for (int l=c.size()-10;l<c.size();l++)
			d2=d2*10+c[l];
		if(d2==d1 && d1!=0) f=true; 
	}
	return;
}
return;
}
void func(int k)
{
	if(k!=0)
	while (k<b) { k*=10;
		if(k<b) c.push_back(0);
	}
	cif(k/b);
	if(k%b!=d && f==false) 
		func(k%b);
	return;
}
int main()
{
	long long a,p,k,k1;
	cin >> a >> b >> k >> p;
	d=a%b;
	func(d);
	k1=k/c.size();
	k=k%c.size();
	k--;
	if(k==-1) k=c.size()-1;
	if (f==false)
	{
		int h=c.size();
		for(int i=k;i<h;i++) {
			if (p>0)
			cout << c[i];
			p--;
		}
		int i=0;
		while(p>0) {
			cout << c[i];
			p--;
			i++;
			if (i==h) i=0;
		}
	}
	if (f)
	{
		int h=c.size();
		if(k1>0)
			for (int i=0;i<p;i++)
				cout << c[h-1];
		else 
			for (int i=0;i<p;i++)
				if(k+i<h ) cout << c[k+i];
				else cout << c[h-1];
	}		
	cout << '\n';	
	return 0;
}
