#include<iostream>
using namespace std;
int a[1020][1020],r[1020],c[1020],n,m,k,x,y;
char o;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        r[i]=i;
        for(int j=1;j<=m;j++)
        {c[j]=j;
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin>>o>>x>>y;
        if(o=='c')
        {
            swap(c[x],c[y]);
        }
        if(o=='r')
        {
            swap(r[x],r[y]);
        }
        if(o=='g')
        {
            cout<<a[r[x]][c[y]]<<endl;
        }
    }
    return 0;
}
