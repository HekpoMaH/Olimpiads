#include<iostream>
#include<string>
using namespace std;
string first,sec,ans,reb;
int sta,stb,stc,x,y,z;
int pos1,pos2;
int horner(string s,int a,int b,int c)
{
  int res=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='A')res=res*10+a;
    if(s[i]=='B')res=res*10+b;
    if(s[i]=='C')res=res*10+c;
  }
  return res;
}
int main()
{
  cin>>reb;
  pos1=reb.find_first_of("+");
  pos2=reb.find_first_of("=");
  first=reb.substr(0,pos1);
  sec=reb.substr(pos1+1,pos2-pos1-1);
  ans=reb.substr(pos2+1,reb.size()-pos2-1);
  //cout<<first<<" "<<sec<<" "<<ans<<endl;
  if((first[0]=='A'&&first.size()>1)||(sec[0]=='A'&&sec.size()>1)||(ans[0]=='A'&&ans.size()>1))sta=1;
  if((first[0]=='B'&&first.size()>1)||(sec[0]=='B'&&sec.size()>1)||(ans[0]=='B'&&ans.size()>1))stb=1;
  if((first[0]=='C'&&first.size()>1)||(sec[0]=='C'&&sec.size()>1)||(ans[0]=='C'&&ans.size()>1))stc=1;
  for(int a=sta;a<=9;a++)
  {
    for(int b=stb;b<=9;b++)
    {
      for(int c=stc;c<=9;c++)
      {
        if(a!=b&&a!=c&&b!=c)
        {
          x=horner(first,a,b,c);
          y=horner(sec,a,b,c);
          z=horner(ans,a,b,c);
          //cout<<a<<" "<<b<<" "<<c<<endl;
          //cout<<x<<" "<<y<<" "<<z<<endl;
          //system("pause");
          if(x+y==z)
          {
            cout<<x<<"+"<<y<<"="<<z<<endl;
            return 0;
          }
        }
      }
    }
  }
  //cout<<"No solution"<<endl;
  return 0;
}
