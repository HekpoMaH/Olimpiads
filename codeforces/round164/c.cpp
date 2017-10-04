#include<iostream>
using namespace std;
int n,m;

int main()
{
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    int i=0,j=m;
    while(i<=n&&j>=0)cout<<i<<" "<<j<<endl,i++,j--;
    return 0;
}