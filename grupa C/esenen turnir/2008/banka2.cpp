#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k,p,r,m,used[14],numbers[14]={1,2,3,4,5,6,7,8,9,10,11,12,13},res[14],br;
long long fact[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
struct pe
{
  int r[14];
};
pe perm;
void gen(int broi,pe per,int k)
{
  long long fp,mxl,pl;
  while(broi>0)
  {
    //cout<<"broi="<<broi<<endl;
    broi--;
    mxl=9999;
    pl=-1;
    for(fp=k-1;fp>=1;fp--)
    {
      //cout<<per.r[fp]<<" "<<per.r[fp-1]<<endl;
      if(per.r[fp]>per.r[fp-1])
      {
        break;
      }
    }
    for(int i=fp;i<k;i++)
    {
      if(per.r[i]>per.r[fp-1]&&per.r[i]<mxl)
      {
        mxl=per.r[i];
        pl=i;
      }
    }
    //cout<<mxl<<" "<<pl<<endl;
    swap(per.r[fp-1],per.r[pl]);
    //for(int i=0;i<k;i++)cout<<per.r[i]<<" ";
    //cout<<endl;
    sort(per.r+fp,per.r+k);
    for(int i=0;i<k;i++)printf("%d ",per.r[i]);
    printf("\n");
    //system("pause");
  }
}
int main()
{
  cin>>k>>n>>m;
  int br2,k1=k,n1=n;
  n1--;
  while(n1!=0)
  {
    p=n1/fact[k-1];
    r=n1%fact[k-1];
    br2=0;
    for(int i=0;i<k1;i++)
    {
      if(used[i]==0)br2++;
      if(br2==p+1)
      {
        res[br]=numbers[i];
        used[i]=1;
        br++;
        break;
      }
    }
    n1=r;
    k--;
  }
  for(int i=0;i<k1;i++)
  {
    if(used[i]==0)
    {
      res[br]=numbers[i];
      used[i]=1;
      br++;
    }
  }
  for(int i=0;i<br;i++)printf("%d ",res[i]);
  for(int i=0;i<br;i++)perm.r[i]=res[i];
  printf("\n");
  gen(m-n,perm,k1);
  return 0;
}
