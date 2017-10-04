#include <iostream>
using namespace std;
int n,k;
int a[1024][1024],mx=-999999999,i1,j1;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        int s=0;
        int q;
        if(k+i<n)q=k+i;
        if(k+i>=n)q=n-1;
        int w;
        if(j+k<n)w=j+k;
        if(j+k>=n)w=n-1;
        for(int x=i+1;x<=q;x++)
        s+=a[x][j];
        for(int y=j+1;y<=w;y++)
        s+=a[i][y];s+=a[i][j];
        if(s>mx){mx=s;i1=i;j1=j;}
    }
    cout<<i1+1<<" "<<j1+1<<endl;
            
        return 0;
}
