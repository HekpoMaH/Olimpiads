#include<iostream>
using namespace std;
int main()
{
    int n,a[100],i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    int pom;
    for(i=1;i<=n-1;i++)
    {
            for(int k=1;k<=n-i;k++)
            {
                    if(a[k]>a[k+1]){
                                    pom=a[k];
                                    a[k]=a[k+1];
                                    a[k+1]=pom;
                                    }
            }
    }
    int x;
    cin>>x;
    int l=1,r=n;
    int m;
    int flag=0;
    while(l<=r&&flag==0)
    {
               m=(l+r)/2;
               if(a[m]==x)flag=1;
               if(x<a[m])r=m-1;
               else l=m+1;
    }
    if(flag==0)cout<<"No"<<endl;
    if(flag==1)cout<<"Yes"<<endl;
    system("pause");
    return 0;
}
