#include<iostream>
using namespace std;
struct s{int x,y;};int n,m,a=0,u[7];s c[7];
void core(int x,int y,int o,int j)
{int i;if(j==n){if(a==0||a>o)a=o;}else if(j<n)
for(i=0;i<m;i++)if(!u[i]){if(abs(x-c[i].x)>abs(y-c[i].y))o+=abs(x-c[i].x);
else o+=abs(y-c[i].y);u[i]=1;j++;core(c[i].x,c[i].y,o,j);u[i]=0;j--;}}
int main()
{int i;cin>>n;for(i=0,m=n*2;i<m;i++)cin>>c[i].x>>c[i].y;
core(0,0,0,0);cout<<a<<endl;}


/*
2
1 1 
3 5 
4 6 
8 2

5
*/



