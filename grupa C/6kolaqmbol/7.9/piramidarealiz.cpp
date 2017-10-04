#include<iostream>
#include<algorithm>
using namespace std;
int x[100],nx;
void sito(int *x,int k,int n)
{
  int i=k,j;
  int y=x[i];
  while((j=2*i+1)<n)
  {
    if(j<n-1&&x[j]>x[j+1])j++;
    if(y<x[j])break;
    x[i]=x[j];i=j;
  }
  x[i]=y;
}
int main()
{
  cin>>nx;
  for(int i=0;i<nx;i++)cin>>x[i];
  for(int i=nx/2-1;i>=0;i--)sito(x,i,nx);//=make_heap(x,x+nx);
  for(int i=0;i<nx;i++)cout<<x[i]<<" "<<i<<endl;
  int n=nx;
  cout<<"-----------------------"<<endl;
  while(--n>0)
  {
    cout<<x[0]<<endl;
    swap(x[0],x[n]);
    sito(x,0,n);
  }

  return 0;
}
