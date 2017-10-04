//ot verijna do obiknovenna
#include<iostream>
using namespace std;
int x,y;
int a[100],n;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }
    return a;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    x=1;y=a[n];
    for(int i=n-1;i>=1;i--)
    {
        x+=a[i]*y;
        swap(x,y);
        //cout<<a[i]<<" "<<x<<" "<<y<<endl;
    }
    swap(x,y);
    int nd=nod(x,y);
    x/=nd;y/=nd;
    cout<<x<<" "<<y<<endl;
}
