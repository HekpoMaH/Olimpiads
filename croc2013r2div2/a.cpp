#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
int a[100009];
int nod;
int nd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }return a;
}
int main()
{cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    nod=a[1];
    for(int i=2;i<=n;i++)nod=nd(nod,a[i]);
    for(int i=1;i<=n;i++)if(a[i]==nod)
    {
        cout<<a[i]<<endl;
        return 0;
    }
    cout<<-1<<endl;
}
