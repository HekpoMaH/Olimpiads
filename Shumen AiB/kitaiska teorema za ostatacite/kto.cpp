//re6enie na kitaiska teorema za ost.
#include<iostream>
using namespace std;
int a[100],m[100],n,pr=1,mm[100],nn[100];
long long sum;
int find(int a,int b)
{
    for(int i=1;i<b;i++)
    {
        if((a*i)%b==1)return i;
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>m[i];
        pr*=m[i];
    }
    for(int i=1;i<=n;i++)
    {
        mm[i]=pr/m[i];
    }
    for(int i=1;i<=n;i++)
    {
        nn[i]=find(mm[i],m[i]);
    }
    for(int i=1;i<=n;i++)sum+=a[i]*mm[i]*nn[i];
    cout<<sum%pr<<endl;
    return 0;
}