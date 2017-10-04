#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;
string a;
int n,m;
double t[505][505];
void solve()
{
	int i,j,br=0;
	cin>>a;
	for(i=0;i<a.size();i++)
		if(a[i]==')')
			br++;
	if(br)
		cout<<"2"<<endl;
	else cout<<"1"<<endl;
}
int main()
{
	solve();
	return 0;
}