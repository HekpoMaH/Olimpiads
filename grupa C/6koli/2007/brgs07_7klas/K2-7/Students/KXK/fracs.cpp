#include<iostream>
using namespace std;
int main()
{
    int j,i,n,a[25][2];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i][0]>>a[i][1];
    for(i=0;i<n;i++)
    for(j=0;j<n-1;j++)
    {
        if(a[j][0]*a[j+1][1]>a[j+1][0]*a[j][1])
        {
            int f;
            f=a[j][0];
            a[j][0]=a[j+1][0];
            a[j+1][0]=f;
            f=a[j][1];
            a[j][1]=a[j+1][1];
            a[j+1][1]=f;
        }
    }
    cout<<n<<'\n';
    for(i=0;i<n;i++)
    {
        for(j=2;j<=min(a[i][0],a[i][1]);j++)
        {
            while(a[i][0]%j==0&&a[i][1]%j==0)
            {
                a[i][0]/=j;
                a[i][1]/=j;
            }
        }
        cout<<a[i][0]<<' '<<a[i][1]<<'\n';
    }
    return 0;
}

                
    
