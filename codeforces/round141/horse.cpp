#include<iostream>
#include<algorithm>
using namespace std;
long long a[5],n;
int main()
{
    n=4;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int br=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])br++;
    }
    cout<<n-br<<endl;
    return 0;
}