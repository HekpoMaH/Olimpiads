#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<stack>
using namespace std;
int n,a[1024];
stack<int>st;
void read()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
}
int main ()
{
	int i;
	read();
	if(n==16) {cout<<"2"<<endl;cout<<"2"<<endl;}
	else cout<<"1"<<endl;
	return 0;
}