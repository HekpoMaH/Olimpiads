#include<iostream>
using namespace std;
int n,a[100009];

int main()
{
    cin>>n;
    if(n%4==0||n%4==1)
    {
        int i=1,j=n;
        int p1=1,p2=n;
        for(i=i;i<=n/2;i+=0)
        {
            //cout<<p1<<" "<<p2<<endl;
            a[i]=p1+1;
            a[i+1]=p2;
            a[j]=p2-1;
            a[j-1]=p1;
            i+=2;j-=2;
            p1+=2;p2-=2;
        }
        if(n%4==1)a[n/2+1]=n/2+1;
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
}
