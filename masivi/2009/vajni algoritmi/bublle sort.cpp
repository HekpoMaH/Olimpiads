//bublle sort
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
    for(i=1;i<=n;i++){
                      if(i==n)cout<<a[i]<<endl;
                      else cout<<a[i]<<" ";
                      }
    system("pause");
    return 0;
}
