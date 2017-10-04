#include<iostream>
using namespace std;
long long n,a,brd,mp,del,brtd;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    //for(int j=0;j<=mp;j++)used[j]=0;
    del=2;
    mp=0;
    brtd=0;
    brd=1;
    while(a!=1)
    {
      if(a%del==0)
      {
        a/=del;
        brtd++;
        //if(del>mp)mp=del;
      }//cout<<"brtd="<<brtd+1<<" ";
      else
      {
        del++;
        brd*=(brtd+1);
        brtd=0;
      }
    }brd*=(brtd+1);
    //brd=1;
    //for(int j=0;j<=mp;j++)brd*=(used[j]+1);
    if(i==n-1)cout<<brd<<endl;
    else cout<<brd<<" ";
  }
  return 0;
}
