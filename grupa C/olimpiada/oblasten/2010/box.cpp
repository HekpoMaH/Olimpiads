#include<iostream>
using namespace std;
unsigned long long a[6][2],k[10000],a1[3],b[3],br;
int main()
{
  for(int i=0;i<6;i++)
  {
    cin>>a[i][0]>>a[i][1];
    k[a[i][0]]++;
    k[a[i][1]]++;
  }
  for(int i=0;i<=10000;i++)
  {
    if(k[i]>=4)
    {
      br++;
      a1[br]=i;
      b[br]=k[i];

    }
  }//cout<<"br="<<br<<endl;
  if(br-1==3)cout<<a1[1]*a1[2]*a1[3]<<endl;
  if(br==1&&b[1]==12)cout<<a1[1]*a1[1]*a1[1]<<endl;

  if(br==2)
  {
    long long v=0,o=0;
    if(b[1]==4)v=a1[1];
    if(b[1]==8)o=a1[1];
    if(b[2]==4)v=a1[2];
    if(b[2]==8)o=a1[2];
    //cout<<v<<" "<<o<<endl;
    if(v!=0&&o!=0)cout<<v*o*o<<endl;
    if(v==0&&o==0)cout<<0<<endl;
  }
  if(br==1&&b[1]!=12)cout<<0<<endl;
  if(br==0)cout<<0<<endl;
  return 0;
}
