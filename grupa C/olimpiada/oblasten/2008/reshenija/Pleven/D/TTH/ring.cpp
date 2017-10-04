#include<iostream>
#include<string>
using namespace std;
string k;
long n,x,b[10000],a[10000];
int main()
{
    cin>>n>>a[0];
    for(long i=1;i<=n;i++)
    {
            cin>>a[i];
            b[i]=i;
    }
    for(int i=0;i<=n;i++)
    {
            if(a[i]>n){a[i]=n-a[i];}
            b[a[i]]=0;
    }
     for(int i=0;i<=n;i++)
     {
            if(b[i]!=0){cout<<b[i]<<endl;break;}
     }
    //system("PAUSE");
    return 0;
}
