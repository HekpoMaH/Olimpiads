#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
int a[100009];int b[100009],c[100009];
int used[100009];
int main()
{
    cin>>n;if(n==1){cout<<0<<endl<<0<<endl<<0<<endl;return 0;}
    if(n%2==0){cout<<-1<<endl;return 0;}
    for(int i=1;i<=n-2;i++)a[i]=b[i]=i-1;
    a[n]=b[n]=n-2;
    a[n-1]=b[n-1]=n-1;
    for(int i=1;i<=n;i++)c[i]=(a[i]+b[i])%n;
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<c[i]<<" ";
    cout<<endl;
}

//497

