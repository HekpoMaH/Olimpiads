//
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int main()
{
  int n,br1=0,br2=0,br3=0,br4=0,br22=0,br33=0,p1=0,p3=2,p4=3;
  char a;
  cin>>n;
  cin>>a;
  string s;
  for(int i=0;i<n*4;i++)
  {

    cin>>s;
    if(br22>0){br2++;}
    br22=0;
    if(br33>1){br3++;}
    br33=0;
    for(int j=0;j<s.size();j++)
    {
      if(s[j]>='A' && s[j]<='Z'){s[j]=s[j]+32;}
      if(i==p1){if(s[0]==a){br1++;}p1=p1+4;break;}
      if((i-1)%4==0){if(s[j]==a){br22++;}}
      if(i==p3)
      {
        if(j+1!=s.size())
        {
          if(s[j]==a){br33++;}
        }
        else
        {
          if(s[j]==a){br33++;}
          p3=p3+4;
        }
      }
      if(i==p4){if(s[s.size()-1]>='A' && s[s.size()-1]<='Z'){s[s.size()-1]=s[s.size()-1]+32;}if(s[s.size()-1]==a){br4++;};p4=p4+4;}
    }
  }
  cout<<br1<<" "<<br2<<" "<<br3<<" "<<br4<<endl;
  return 0;
}