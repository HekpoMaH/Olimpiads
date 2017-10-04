#include<iostream>
using namespace std;
int arr[10][10];
int n,s=-1;
int x[100];
bool way=false;
void writeway()
{
  for(int i=0;i<=s;i++)cout<<x[i]<<" ";
  cout<<endl;
}
bool member(int x,int n,int *a)
{
  if(n==1)return a[0]==x;
  else x==a[0]||member(x,n-1,a+1);
}
void foundallway(int i,int j)
{
  if(i==j)
  {
    way=true;
    s++;
    x[s]=i;
    writeway();
  }
  else
  {
    s++;
    x[s]=i;
    for(int k=0;k<n;k++)
    {
      if(arr[i][k]==1&&member(k,s+1,x))
      arr[i][k]=0;arr[k][i]=0;
      foundallway(k,j);
      arr[i][k]=1;arr[k][i]=1;s--;
    }
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n-1;i++)
  for(int j=i+1;j<n;j++)
  {
    cout<<"cb "<<i<<"/"<<j<<endl;
    cin>>arr[i][j];
    arr[j][i]=arr[i][j];
  }
  int i,j;
  cout<<"sft  ";cin>>i>>j;
  foundallway(i,j);
  if(!way)cout<<"no way"<<endl;
  return 0;
}
