#include <iostream>
using namespace std;
bool cmp(int f1,int f2)
{
	if (f1>f2) return true;
	return false;
}
int s,n,a[3000],m=10000;
void func(int k,int e)
{
	if(k==0){
		m=min(m,e);
		return;
	}
	for (int i=0;i<n;i++)
		if (k-a[i]>=0)
			func(k-a[i],e+1);
	return;
}
int main()
{
	cin >> s >> n;
	for (int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n,cmp);
	func(s,0);
	cout << m << '\n';
	return 0;
}
