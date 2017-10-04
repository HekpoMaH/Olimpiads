/*
TASK:money
LANG:C++
*/
#include<iostream>
using namespace std;
int n,a[200001];
int i=1,l;
int f()
{
    while(a[i]<=a[n]/2)
    {
        i++;
    }
    if(a[i]+a[i-1]>a[n]) return n-i+2;
    else return n-i+1;
}

int f1(int m)
{
    while(a[i]>=a[m]/2)
    {
        i--;
    }
    if(a[i]+a[i+1]>a[m]) return m-i+1;
    else return m-i;
}

main()
{
    cin>>n;
    for(int j=1; j<=n; j++)
    {
        cin>>a[j];
    }
    sort(a+1,a+n+1);
    l=f();
    for(int d=n-1;d>=3;d--)
    {
        int z=f1(d);
        if(l<z) {
            l=z;
            }
        }
    if(l==2) cout<<"1";
    else cout<<l;
    cout<<endl;
    return 0;
    }
