#include<iostream>
#include<deque>
using namespace std;
int m,n,k,i,j,maxs,sum,br;
int a[1000][1000];
void inc()
{
  cin>>n>>m>>k;
  for(i=0;i<n;i++)
  for(j=0;j<m;j++)
  {cin>>a[i][j];
    //a[i][j]=1000;
  br+=a[i][j];}
}

int sums(int g,int h)
{
  int i,j,aze=0;
  for(i=0;i<k;i++)
  for(j=0;j<k;j++)
  {
    aze+=a[i+g][h+j];
  //  cout<<i+g<<' '<<h+j<<' '<<a[i+g][h+j]<<' '<<aze<<endl;
  }
  return aze;
}


int main()
{
  inc();
  for(i=0;i<n-k+1;i++)
  for(j=0;j<m-k+1;j++)
  {
    sum=0;
    sum=sums(i,j);
    if(sum>maxs)maxs=sum;
  }
  cout<<br-maxs<<endl;
  return 0;
}
