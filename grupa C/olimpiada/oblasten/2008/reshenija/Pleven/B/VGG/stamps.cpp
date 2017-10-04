#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int s,n,a[5002];
int main()
{
    int i,j,x;
	cin >> s >> n;
	for (i=0; i<n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	a[0]=0;
	sort(v.begin(), v.end());
	int minn;
	for (i=1; i<=s; i++)
	{
		minn=s;
		for (j=0; j<n; j++)
		{
			if (v[j]>i) break;
			if (a[i-v[j]]<minn) minn=a[i-v[j]];
		}
		a[i]=minn+1;
	}
	cout << a[s] << "\n";
	return 0;
}
	
