#include<iostream>
using namespace std;
int main()
{
    int n,a[36];
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int b[36],br=1,j;
    for(int i=1;i<=n;i++)
    {
            j=a[i];
            while(a[i]%2==0&&a[i]>1)
            {
                                    a[i]/=2;
            }
            if(a[i]==1){b[br]=j;br++;}
    }
    int p;
    for(int i=1;i<=br-1;i++)
    {
            for(int k=1;k<=br-i;k++)
            {
                    if(b[k]>b[k+1]){
                                      p=b[k];
                                      b[k]=b[k+1];
                                      b[k+1]=p;
                                      }
            }
    }
    for(int i=1;i<br;i++){
                           if(i==br-1)cout<<b[i]<<endl;
                           else cout<<b[i]<<" ";
                           }
    system("pause");
    return 0;
}
