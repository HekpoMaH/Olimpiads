#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    int v=1,p=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-v;j++)
        if (a[i][j]!=a[n-1-j][n-1-i])
        {
            p=1;
            break;
        }
        if (p==1) break;
        v++;
    }
    if (p==0)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if ((a[i][j]%3==0)&&(a[i][j]!=0)) cout<<a[i][j]<<' ';
    }
    else
    {
        int s=0;
        for(int i=0;i<n;i+=2)
        for(int j=0;j<n;j++)
        s+=a[i][j];
        cout<<s;
    }
    cout<<endl;
    return 0;    
}
        
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
                                 
