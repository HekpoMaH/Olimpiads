#include<bits/stdc++.h>
using namespace std;
int k,d;
int main()
{
    cin>>k>>d;
    if(d==0&&k>1)cout<<"No solution"<<endl;
    else if(d>k)
    {
        for(int i=1;i<k;i++)cout<<1;
        cout<<d-k+1;
    }
    else for(int i=1;i<=k;i++)
    {
        if(i>d)cout<<0;
        else cout<<1;

    }cout<<endl;
}
