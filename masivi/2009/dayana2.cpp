#include<iostream>
using namespace std;
int main()
{
    double a[1000],n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    int l=0;
    i=1;
    while(l==0&&i<n)
    {
                     if(a[i]>=a[i+1])l=1;
                     i++;
    }
    if(l==0)cout<<"Yes"<<endl;
    double pom;
    if(l==1){
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
         }
    system("pause");
    return 0;
}
