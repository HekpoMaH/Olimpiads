#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x,y,n,d;
    cin>>x>>y>>n;
    if(x==y){cout<<"0\n";return 0;}
    d=n*(x-y-1)/y+1;
    cout<<d<<"\n";
}
