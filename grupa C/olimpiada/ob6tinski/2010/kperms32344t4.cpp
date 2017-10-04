#include<iostream>
using namespace std;
int n,k;
int gen(int broi)
{
  int fp;
  int pr[10];
  for(int i=0;i<n;i++)pr[i]=i+1;
  int cnt=0,mx,pl,l;
  l=1;
  for(int i=0;i<n;i++)
  {
    if(abs(pr[i]-pr[i-1])>k){l=0;break;}
  }
  if(l==1)cnt++;
  while(broi>0)
  {
    broi--;
    mx=14;
    l=0;
    for(int i=n-1;i>=1;i--)
    {
      if(pr[i]>pr[i-1]){l=1;}
      if(l==1){fp=i;break;}
    }
    for(int i=fp;i<n;i++)
    {
      if(pr[i]>pr[fp-1]&&pr[i]<mx)
      {
        mx=pr[i];pl=i;
      }
    }
    swap(pr[fp-1],pr[pl]);
    sort(pr+fp,pr+n);
    l=1;
    for(int i=0;i<n-1;i++)
    {
      if(abs(pr[i]-pr[i+1])>k){l=0;break;}
    }
    if(l==1)cnt++;
  }
  return cnt;
}
int main()
{
  cin>>n>>k;
  int br=1;
  for(int i=2;i<=n;i++)br*=i;
  int kp=gen(br-1);
  cout<<kp<<endl;
  return 0;
}
