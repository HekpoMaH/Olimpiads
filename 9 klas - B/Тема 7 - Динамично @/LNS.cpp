#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <stack>
#include <list>
#include <bitset>
#include <queue>
#include <ctime>
using namespace std;
int a[1024]; 
int n;
int DP[1024];
int prev[1020000];
void solve()
{
	
	memset(prev, -1 , sizeof(prev));
	cin>>n;
	cin>>a[0];		
	DP[0] = 0;
		
	int k = 1;
	int i ;	
	for(i = 1 ; i < n ;i++)
	{
		cin >> a[i];
		
		if(a[i] > DP[k-1])
		{
			DP[k] = i; 
			prev[i] = DP[k-1];
			k++;
		}
		else
		if(a[i] < DP[0])
		{
			DP[0]=i; 
			prev[i] = -1;
		}
		else
		{
			int f = 0, l= k,mid;
			while (f<l-1)
			{
				mid=(f+l)/2;
		
				if(a[DP[mid]] < a[i])
					f = mid;
		  		else
		  			l = mid;
			}
			DP[l] = i;		
			prev[i] = DP[l-1];
		}
		
	}
	
	cout<<k<<endl;
	
	int temp = DP[k-1];

		
	while (temp>=0&&temp!=prev[temp])
	{
		cout<<temp<<" ";
		temp = prev[temp];

	}
		
	cout<<endl;
}

int main()
{
	solve();
	return 0;
}
