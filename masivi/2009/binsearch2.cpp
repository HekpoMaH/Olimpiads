#include<iostream>
using namespace std;
int main()
{
    int a[100],n;
    int l,r,m;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int p;
    for(int i=1;i<=n-1;i++)
    {
            for(int k=1;k<=n-i;k++)
            {
                    if(a[k]>a[k+1]){
                                    p=a[k];
                                    a[k]=a[k+1];
                                    a[k+1]=p;
                                    }
            }
    }
    int x;
    cin>>x;
    l=1;r=n;
    m=(l+r)/2;
    int flag=0;
    while(l<r&&flag==0)
    {
              if(a[m]==x)flag=1;
              if(x>a[m])l=m+1;
              if(x<a[m])r=m-1;
              m=(r+l)/2;
    }
    if(flag==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
}
