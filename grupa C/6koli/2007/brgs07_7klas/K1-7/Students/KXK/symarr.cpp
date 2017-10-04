#include<iostream>
using namespace std;
int main()
{
    int c[25][25],b[420],a[25][25],n,p=0,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        cin>>a[i][j];
        c[i][j]=a[i][j];
    }
    i=n-1;
    j=0;
    while(j<n)
    {
        a[i][j]=1200;
        i--;
        j++;
    }
    bool sym=1;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(a[i][j]==1200)continue;
        if(a[i][j]!=a[n-1-j][n-1-i])sym=0;
    }
    if(sym)
    {
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(c[i][j]!=0&&c[i][j]%3==0)
        {
            b[p]=c[i][j];
            p++;
        }
        for(i=0;i<p;i++)
        cout<<b[i]<<' ';
        cout<<'\n';
    }
    else
    {
        int sum=0;
        for(i=0;i<n;i++)
        {
            if((i+1)%2==1)
            for(j=0;j<n;j++)
            sum+=c[i][j];
        }
        cout<<sum<<'\n';
    }
    return 0;
}

    
        
