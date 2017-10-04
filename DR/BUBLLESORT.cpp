#include<iostream>
using namespace std;
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int p;
    for(int i=1;i<n;i++)
    {
            for(int j=1;j<=n-i;j++)
            {
                        if(a[j]>a[j+1]){
                                        p=a[j];
                                        a[j]=a[j+1];
                                        a[j+1]=p;
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
