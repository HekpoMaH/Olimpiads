#include <iostream>
#include <map>
using namespace std;
int n,m,l=0;
unsigned long long s[901];
class tsetsy
{
	public:
		unsigned long long x;
		int y;
};
struct ltstr
{
  bool operator()(const tsetsy s1, const tsetsy s2) const
  {
		if(s1.x==s2.x && s1.y==s2.y)
    	return false;
    	return true;
  }
};
map<const tsetsy, int, ltstr> g;
void func()
{
	tsetsy t;
	unsigned long long a[32],b[32],c1=0,k,b1=1,a1=1;
	for (int i=0;i<32;i++)
		{a[i]=0; b[i]=0;}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			cin >> k;
			b[j]+=k;
			a[i]+=k;
			c1+=k;
		}
	for(int i=0;i<n;i++) {
		b1*=b[i];
		a1*=a[i];
	}
	a1+=b1;
	t.x=a1;
	t.y=c1;
	if(g[t]==0) {g[t]=1; l++; }
	return;
}
int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++)
		func();
	cout << l << '\n';
	return 0;
}
