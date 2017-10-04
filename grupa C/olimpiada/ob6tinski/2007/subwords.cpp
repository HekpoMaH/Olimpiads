#include<iostream>
#include<string>
using namespace std;
string s,p[1000],k;
int br,n,l;
int main()
{
  cin>>s;
  n=s.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      k="";
      for(int f=j;f<=j+i;f++){if(j+i+1>n)break;k+=s[f];}
      l=0;
      for(int f=0;f<br;f++){if(k==p[f]){l=1;break;}}
      if(l==0){p[br]=k;br++;}
      //cout<<k<<endl;
    }
  }
  cout<<br-1<<endl;
  return 0;
}
