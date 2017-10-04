#include<iostream>
using namespace std;
int main()
{
    int a[36],n;
    cin>>n;
    int br=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    int j,c[36];
    for(int i=1;i<=n;i++)
    {
            j=a[i];
            while(j%2==0&&j>1)
            {
                       j/=2;
            }
            if(j==1){c[br]=a[i];br++;}
    }
    int p;
    for(int i=1;i<=br-1;i++)
    {
            for(int k=1;k<=br-i;k++)
            {
                    if(c[k]>c[k+1])
                    {
                                   p=c[k];
                                   c[k]=c[k+1];
                                   c[k+1]=p;
                    }
            }
    }
    for(int i=1;i<br;i++){
                           if(i==br-1)cout<<c[i]<<endl;
                           else cout<<c[i]<<" ";
                           }
    system("pause");
    return 0;
}
