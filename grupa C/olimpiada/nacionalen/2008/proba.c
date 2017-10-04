#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s,ms,spr;
int md,ds,k;
//stack<int> st;
int sword(string s)
{
  int d=s.size(),d1;
  d1=d;
  //string s2=s;
  if(d%2==1)return 0;
  for(int i=0;i<d;i++)
  {
    if(s[i]>='A'&&s[i]<='Z'){s[i]+=('a'-'A');}
    //cout<<"s["<<i<<"]"<<s[i]<<" "<<"s["<<i+1<<"]"<<s[i+1]<<endl;cout<<"s="<<s<<endl;
    if(s[i]==s[i+1]){s.erase(i,2);i=-1;d=s.size();}
  }
  if(s.size()==0)return d1;
  if(s.size()>0)return 0;
}
int main()
{
  //ios::sync_with_stdio(false);
  getline(cin,s);k=0;
  while(k<s.size())
  {
    if(s[k]!=' ')spr+=s[k];//cout<<"spr="<<spr<<endl;
    if(s[k]==' '||k==s.size()-1)
    {for(int i=0;i<spr.size();i++)if(spr[i]>='A'&&spr[i]<='Z'){spr[i]+=('a'-'A');}
    ds=sword(spr);//cout<<"spr="<<spr<<endl;
    if(ds>md)
    {
      md=ds;
      ms=spr;
    }
    spr="";
    }
    k++;
  }
  cout<<ms<<endl;
  return 0;
}
