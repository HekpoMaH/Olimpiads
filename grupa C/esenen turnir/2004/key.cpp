#include<iostream>
using namespace std;
int n,k,kasa1[102],kasa2[102],b1=1,e1=1,b2=1,e2=1,isworking2,takt1,takt2,okl1,okl2,kl1,kl2,lobs1,lobs2;
int main()
{
  cin>>k;
  kasa1[1]=-1;kasa2[1]=-1;
  while(cin>>n)
  {
    if(kl1==k)isworking2=1;
    if(isworking2==0)
    {
      if(kasa1[b1]==0)b1++;
      if(n>0)
      {
        kasa1[e1]=n+3;
        e1++;
        kl1++;
        if(lobs1==0)lobs1=n+3;
        //takt1+=n+3;
        //okl1++;
      }
      if(n==0)
      {
        kasa1[e1]=1;
        e1++;
        kl1++;
        if(lobs1==0)lobs1=1;
        //takt1++;
        //okl1++;
      }
    }
    else
    {
      if(kasa1[b1]==0&&kl1>0)
      {
        takt1+=lobs1;
        lobs1=kasa1[b1+1];
        //cout<<takt1<<endl;
        b1++;
        okl1++;
        kl1--;
      }
      if(kasa1[b1]==0&&kl1==0)lobs1=0;
      kasa1[b1]--;
      if(kasa2[b2]==0&&kl2>0)
      {
        takt2+=lobs2;
        lobs2=kasa2[b2+1];
        okl2++;
        b2++;
        kl2--;
      }
      if(kasa2[b2]==0&&kl2==0)lobs2=0;
      kasa2[b2]--;
      if(n>=0)
      {
        if(kl1<=kl2)
        {
          if(n==0)kasa1[e1]=1;
          if(n>0)kasa1[e1]=n+3;
          if(lobs1==0)lobs1=kasa1[e1];
          e1++;
          kl1++;
        }
        else
        {
          if(n==0)kasa2[e2]=1;
          if(n>0)kasa2[e2]=n+3;
          if(lobs2==0)lobs2=kasa2[e2];
          e2++;
          kl2++;
        }
      }
      if(kl1==0&&kl2>1)
      {
          kasa1[e1]=kasa2[e2];
          e1++;
          e2--;
      }
      else if(kl1>1&&kl2==0)
      {
          kasa2[e2]=kasa1[e1];
          e2++;
          e1--;
      }
    }
    if(kl1==0&&kl2==0)isworking2=0;
  }
  cout<<takt1<<" "<<takt2<<endl;
  cout<<okl1<<" "<<okl2<<endl;
  return 0;
}
