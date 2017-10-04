#include<iostream>
using namespace std;
int n,m,a[55],idx;
int main()
{
    cin>>n>>m;
    idx=1;
    while(1)
    {
        m-=idx;
        idx=idx%n+1;
        if(m<idx)break;
    }
    cout<<m<<endl;
    return 0;
}