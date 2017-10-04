#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n,pl,k,gl;
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    cin>>n>>k;
    if(n*(n-1)/2<=k)
    {
        cout<<"no solution"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<0<<" "<<i<<endl;
    }
}

