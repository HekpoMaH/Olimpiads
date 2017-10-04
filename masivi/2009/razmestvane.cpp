#include<iostream>
using namespace std;
int main()
{
    int a[9];
    int m;
    cin>>m;
    for(int i=1;i<=9;i++)a[i]=i;
    for(int i=1;i<=9;i++){
                          if(i==9)cout<<a[i]<<endl;
                          else cout<<a[i]<<" ";
                          }
    int d;
    for(int i=2;i<=m;i++)
    {
            d=a[1];
            for(int k=1;k<=8;k++)a[k]=a[k+1];
            a[9]=d;
            for(int k=1;k<=9;k++){
                                  if(k==9)cout<<a[k]<<endl;
                                  else cout<<a[k]<<" ";
                                  }
    }
    system("pause");
    return 0;
}
