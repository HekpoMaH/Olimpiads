#include<iostream>
#include<vector>
using namespace std;
int a,b,p,q,br;
int main()
{
    cin>>a>>b>>p>>q;
    for(int i=a;i<=b;i++)if(i%p==q)br++;
    cout<<br<<endl;
    return 0;
}