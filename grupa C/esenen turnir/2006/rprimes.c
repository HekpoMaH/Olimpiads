#include<iostream>
#include<cmath>
using namespace std;
int prime(long long p)
{
  for(long long i=2;i<=sqrt(p);i++)
  {
    if(p%i==0){return 0;break;}
  }
  if(p!=1)return 1;
  else return 0;
}
int br=3,i,br2;
int main()
{
  long long a,b,k,rpr[100]={2, 3, 5, 7};
  cin>>a>>b;
  if(2>=a&&2<=b)br2++;
  if(3>=a&&3<=b)br2++;
  if(5>=a&&5<=b)br2++;
  if(7>=a&&7<=b)br2++;
  while(i<=br)
  {
    k=rpr[i]*10+1;
    if(prime(k)==1)
    {
      br++;
      rpr[br]=k;if(k>b)break;
      else if(k>a)br2++;

    }
    k=rpr[i]*10+3;
    if(prime(k)==1)
    {
      br++;
      rpr[br]=k;if(k>b)break;
      else if(k>a)br2++;

    }
    k=rpr[i]*10+7;
    if(prime(k)==1)
    {
      br++;
      rpr[br]=k;if(k>b)break;
      else if(k>a)br2++;

    }
    k=rpr[i]*10+9;
    if(prime(k)==1)
    {
      br++;
      rpr[br]=k;if(k>b)break;
      else if(k>a)br2++;

    }
    i++;
  }
  //for(int j=0;j<=br;j++)if(rpr[j]>=a&&rpr[j]<=b)br2++;
  cout<<br2<<endl;
  return 0;
}
