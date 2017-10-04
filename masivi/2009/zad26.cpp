#include<iostream>
using namespace std;
int main()
{
    int n;
    double a[100];
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    double pom;
    for(int i=1;i<=n-1;i++)
    {
            for(int k=1;k<=n-i;k++)
            {
                    if(a[k]<a[k+1]){
                                    pom=a[k];
                                    a[k]=a[k+1];
                                    a[k+1]=pom;
                                    }
            }
    }
    for(int i=1;i<=n;i++){
                          if(i==n)cout<<a[i]<<endl;
                          else cout<<a[i]<<" ";
                          }
    system("pause");
    return 0;
}
