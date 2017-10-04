#include<iostream>
using namespace std;
int n,t[10009],c[10009][3],pal[10009][3];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int k=-1;int j;
    int x,y;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n;i++)
    {
        j=1;
        while(i-j>=1&&i+j<=n)
        {
            if(t[i-j]!=t[i+j])break;
            else j++;
        }
        j--;
        k++;
        pal[k][0]=i-j;pal[k][1]=i+j;
    }
    for(int i=1;i<n;i++)
    {
        j=1;
        while(i-j+1>=1&&i+j<=n)
        {
            if(t[i-j+1]!=t[i+j])break;
            else j++;
        }
        j--;
        if(j!=0){k++;
        pal[k][0]=i-j+1;pal[k][1]=i+j;}
    }
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        c[i][0]=i;c[i][1]=i;
        for(j=0;j<=k;j++)
        {
            x=pal[j][1]-i;y=pal[j][0]+i;
            if(x>=0&&y<=n)if(c[i][1]>c[y-1][1]+1){c[i][1]=c[y-1][1]+1;c[i][0]=y;}
        }
    }
    cout<<c[n][1]<<endl;k=c[n][1];
    if(k!=1)
    {
        j=n;k=c[n][1];
        while(k>1)
        {
            k--;
            t[k]=c[j][0]-1;
            j=c[j][0]-1;
        }
        for(int i=1;i<c[n][1];i++)
        {
            cout<<t[i]<<" ";
        }
        cout<<endl;
    }
}
