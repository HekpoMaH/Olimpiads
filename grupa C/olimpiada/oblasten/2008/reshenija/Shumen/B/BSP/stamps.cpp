#include<iostream>
using namespace std;
int main()
{
    unsigned long long int s,n,a[5000],m[3005],j;
    for(j=0;j<3005;j++)m[j]=999999;
     cin>>s>>n;
    for(int i=0;i<n;i++)
     cin>>a[i];
     m[1]=1;
     m[0]=0;
     
     for(int i=1;i<=s;i++)
      for(j=0;j<n;j++)
       if(a[j]<=i&&m[i-a[j]]+1<m[i])
       m[i]=m[i-a[j]]+1;
       cout<<m[s]<<endl;
//system("pause");
return 0;
}
