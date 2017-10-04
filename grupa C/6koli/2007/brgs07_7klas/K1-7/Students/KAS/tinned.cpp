#include <iostream>
#include <string>
using namespace std;
class Dlg
 {
  string s;
  public:
  Dlg(string a) { s=a; }
  Dlg operator+(Dlg b);
  Dlg operator*(int b);
  string Get() { return s; }
  void Set() { cin>>s; }
  int Size() { return s.size(); }
 };
Dlg Dlg::operator+(Dlg b)
 {
  string e="";
  string r="";
  string fr="";
  string tbs=b.Get();
  int k, c=3, i, o=0;
  if(s.size()<tbs.size())
   { k=tbs.size()-s.size(); while(k!=0) { e+="0"; k--; } e+=s; c=1; }
  if(tbs.size()<s.size())
   { k=s.size()-tbs.size(); while(k!=0) { e+="0"; k--; } e+=tbs; c=2; }
  if(tbs.size()==s.size()) { e=s; c=3; }
  for(int i=0; i<e.size(); i++) r+="0";
  for(int i=e.size()-1; i>=0; i--)
   {
    if(c==1) r[i]=e[i]-'0'+tbs[i]-'0'+o;
    if(c==2) r[i]=e[i]-'0'+s[i]-'0'+o;
    if(c==3) r[i]=e[i]-'0'+tbs[i]-'0'+o;
    o=r[i]/10; r[i]-=(r[i]/10)*10;
    r[i]+='0';
    if(i==0 && o>0) { fr+=o; fr+=r; c=3; }
   }
  //cout<<r;
  if(c==3) s=fr;
  s=r;
  Dlg l(s);
  return l;
 }
Dlg Dlg::operator*(int b)
 {
  string r="";
  string fr="";
  int c=0;
  int o=0, i, k;
  for(i=0; i<s.size(); i++) r+="0";
  for(i=s.size()-1; i>=0; i--)
   {
    r[i]=(s[i]-'0')*b+o;
    o=r[i]/10; r[i]-=(r[i]/10)*10;
    r[i]+='0';
    if(i==0 && o>0) { fr+=o; fr+=r; c=1; }
   }
  if(!c) cout<<r;
  else cout<<fr;
 }
 int main()
  {
   int k;
   Dlg n("0"); Dlg m("0");
   n.Set();
   m.Set();
   cin>>k;
   n=n+m;
   n=n*k;
   //cout<<n.Get();
   return 0;
 }
