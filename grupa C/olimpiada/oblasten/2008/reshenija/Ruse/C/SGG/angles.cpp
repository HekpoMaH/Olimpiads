#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)cin>>a[i][j];
    }
    
    int s[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)s[i][j]=0;
    }
    //                  BEGIN
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)      
        {
            for(int p=j+1; p<=(j+k); p++)
            {
                s[i][j]+=a[i][p];
                if(p==n)break;
            }
            for(int p=i+1; p<=(i+k); p++)
            {
                s[i][j]+=a[p][j];
                if(p==n)break;
            }
            s[i][j]+=a[i][j];
        }
    }
    //                  END
    int br=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)if(s[i][j]>br)br=s[i][j];
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)if(s[i][j]==br){ cout<<i+1<<" "<<j+1<<endl; break; break; }
    }
    return 0;
}
