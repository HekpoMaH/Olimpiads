#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
string a;
int sbor[55],b[55],c[55];
bool cmp(int a,int b)
{
  if(a>b)return true;
  return false;
}
int main()
{
  cin>>a;
  int n=a.length();
  for(int i=0;i<n;i++){b[i]=a[i]-'0';c[i]=a[i]-'0';}
  sort(b,b+n);
  for(int i=0;i<n;i++)if(b[i]!=0){swap(b[0],b[i]);break;}
  sort(c,c+n,cmp);
  //for(int i=0;i<n;i++)cout<<c[i];
  //cout<<endl;
  //for(int i=0;i<n;i++)cout<<b[i];
  //cout<<endl;
  for(int i=n;i>=1;i--)
  {
    sbor[i]+=b[i-1]+c[i-1];
    if(sbor[i]>9){sbor[i]-=10;sbor[i-1]++;}
    //cout<<sbor[i]<<" "<<b[i-1]<<" "<<c[i-1]<<endl;
  }
  if(sbor[0]>0)printf("%d",sbor[0]);
  for(int i=1;i<=n;i++)printf("%d",sbor[i]);
  printf("\n");
  return 0;
}
