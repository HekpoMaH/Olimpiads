#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int c[24],br=-1,br2,m;
int main()
{
  string a;
  getline(cin,a);
  int n=a.size();
  for(int i=0;i<n;i++)if(a[i]>='0'&&a[i]<='9'){br++;c[br]=a[i]-'0';}
  sort(c,c+br+1);
  int a1[24],b1[24];
  for(int i=0;i<=br;i++)
  {
    a1[i]=c[i];
    b1[br-i]=c[i];
  }
  //|for(int i=0;i<=br;i++)cout<<b1[i];
  //cout<<" ";
  if(a1[0]==0){for(int i=0;i<=br;i++)if(a1[i]>0){br2=i;break;}swap(a1[br2],a1[0]);}
  int t,o=0;
  for(int i=br;i>=0;i--)
  {
    //cout<<"a["<<i<<"]="<<a1[i]<<" ";
    //cout<<"b["<<i<<"]="<<b1[i]<<" ";
    if(b1[i]<a1[i])
    {
      for(int j=i-1;j>=0;j--){if(b1[j]>0){b1[j]--;b1[i]+=10;break;}if(b1[j]==0)b1[j]=9;}
    }
    t=b1[i]-a1[i];
    //cout<<"t="<<t<<endl;
    c[i]=t;
  }//for(int i=0;i<=br;i++)cout<<c[i];
  //cout<<" ";
  if(br<3){m=3-br;br+=m;for(int i=br-m;i>=0;i--){c[i+m]=c[i];}for(int i=m-1;i>=0;i--)c[i]=0;}
  //for(int i=0;i<=br;i++)cout<<c[i];
  //for(int i=0;i<=br;i++)cout<<c[i];
  long long int c1=0;
  for(int i=0;i<=br;i++)c1=c1*10+c[i];
  //cout<<c1<<endl;
  if(c1<2010){c1+=2010;cout<<c1<<endl;}
  else
  {
    c1=(c1-2010)%3015+1005;
    cout<<c1<<endl;
  }
  return 0;
}
