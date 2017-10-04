#include<iostream>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int a[100][100],m,n,x,y,p,q;
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)x+=a[0][i];
    for(int i=1;i<m;i++)
    {
        y=0;
        for(int j=0;j<n;j++)y+=a[i][j];
        x=nod(x,y);
    }
    for(int i=0;i<n;i++)
    {
        y=0;
        for(int j=0;j<m;j++)y+=a[j][i];
        x=nod(x,y);
    }
    p=x;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    x=0;
    for(int i=0;i<n;i++)x+=a[0][i];
    for(int i=1;i<m;i++)
    {
        y=0;
        for(int j=0;j<n;j++)y+=a[i][j];
        x=nod(x,y);
    }
    for(int i=0;i<n;i++)
    {
        y=0;
        for(int j=0;j<m;j++)y+=a[j][i];
        x=nod(x,y);
    }
    if(p==1||x==1||nod(p,x)!=1)
    {
        cout<<p<<" "<<x<<endl;
        cout<<"Y"<<endl;
    }
    else
    {
        cout<<p<<" "<<x<<endl;
        cout<<"N"<<endl;
    }
    return 0;
}