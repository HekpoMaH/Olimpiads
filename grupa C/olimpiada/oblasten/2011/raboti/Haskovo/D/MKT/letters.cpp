#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long int br[4];
int main()
{
  long int n,sr=0;
  char a;
  string s;
  cin>>n>>a;
  for(long int j=0;j<n;j++)
  {
    for(int i=0;i<4;i++)
    {
      cin>>s;
      if(i==0)
      {
        if(s[0]==a || char(s[0]-('A'-'a'))==a || char(s[0]+('A'-'a')==a)){br[0]++;}
      }
      if(i==1)
      {
        for(int g=0;g<s.size();g++)
        {
          if(s[g]==a || char(s[g]-('A'-'a'))==a || char(s[g]+('A'-'a')==a)){br[1]++;break;}
        }
      }
      if(i==2)
      {
        sr=0;
        for(int g=0;g<s.size();g++)
        {
          if(s[g]==a || char(s[g]-('A'-'a'))==a || char(s[g]+('A'-'a')==a)){sr++;}
        }
        if(sr>=2)br[2]++;
      }
      if(i==3)
      {
        if(s[s.size()-1]==a || char(s[s.size()-1]-('A'-'a'))==a || char(s[s.size()-1]+('A'-'a')==a))br[3]++;
      }
    }
  }
  cout<<br[0]<<" "<<br[1]<<" "<<br[2]<<" "<<br[3]<<endl;
  return 0;
}
