#include<iostream>
#include<string>
using namespace std;
long i,n,k,k1,j;
long s[100],b[100],br;
int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
    cin>>s[i];
    b[i]=s[i];
    }
    i=0;
    s[k]=0;
    k1=s[k];
    while (1!=1)
    {
          i=i+k1;
          if(i+k1>n) {i=i+k1-n;}
          k1=s[i];
          s[i]=0;
          for(i=1;i<=100;i++)
          {
                             if (s[i]>0) {br++;}
          }
    if (br==1) break;
    }
    for(i=1;i<=100;i++)
    {
                       if (s[i]==b[i]) {cout<<i<<endl;break;}
    }
    return 0;
}
