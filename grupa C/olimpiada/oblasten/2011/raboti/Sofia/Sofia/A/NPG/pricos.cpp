#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
short is(int a);

  vector <int> all;
  int N;
  
int main()
{
  int index=-1;
  cin>>N;
  for(int i=1;i<=N;i++)
  {
    int a,ind;
    cin>>a;
    ind=is(a);
    if ( ind != -1 )
    {
      index=ind;
    }
    else
    {
      ind=0;
      for(unsigned j=0;j<all.size();j++)
      {
	if(all[i]==0)
	{
	  all[i]=a;
	  ind=1;
	  break;
	}
      }
      if(ind == 1);
      else
      {
	all.push_back(a);
      }
    }
  }
  int a=0,b=0;
  for(unsigned i=0;i<all.size();i++)
  {
    if(all[i]!=0)
    {
      if(a!=0)b=all[i];
      else a=all[i];
    }
  }
  cout<<min(a,b);
  cout<<" ";
  cout<<max(a,b);
  cout<<endl;
  return 0;
}
short is(int a)
{
  for(unsigned i=0;i<all.size();i++)
  {
    if(a==all[i])
    {
      all[i]=0;
      return i;
    }
  }
  return -1;
}