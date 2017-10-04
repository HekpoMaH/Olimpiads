#include<iostream>
#include<string>
using namespace std;
int a[100005];
int n,br=3;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    if(n==3){cout<<210<<endl;return 0;}
    if(n<br){cout<<-1<<endl;return 0;}

    n-=4;
    if(n%6==0)
    {
        cout<<1;
        for(int i=0;i<=n;i++)cout<<0;cout<<50<<endl;return 0;
    }
    if(n%6==1)
    {
        cout<<1;
        for(int i=0;i<=n;i++)cout<<0;cout<<80<<endl;return 0;
    }
    if(n%6==2)
    {
        cout<<1;
        for(int i=0;i<n;i++)cout<<0;cout<<170<<endl;return 0;
    }
    if(n%6==3)
    {
        cout<<1;
        for(int i=0;i<=n;i++)cout<<0;cout<<20<<endl;return 0;
    }
    if(n%6==4)
    {
        cout<<1;
        for(int i=0;i<n;i++)cout<<0;cout<<200<<endl;return 0;
    }
    if(n%6==5)
    {
        cout<<1;
        for(int i=0;i<n;i++)cout<<0;cout<<110<<endl;return 0;
    }
}
//1050,10080,100170,1000020,1000200,10000200,1000000050,10000000080,100...0170
