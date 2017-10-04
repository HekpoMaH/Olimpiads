#include <iostream>
using namespace std;
void suml(string a, string b, string &r)
 {
  int i, o=0;
  r="";
  if(a.size()>b.size())
   {
    int rz=a.size()-b.size();
    string t="";
    for(i=1; i<=rz; i++) t+="0";
    t+=b;
    b=t;
   }
  if(b.size()>a.size())
   {
    int rz=b.size()-a.size();
    string t="";
    for(i=1; i<=rz; i++) t+="0";
    t+=a;
    a=t;
   }
  for(i=1; i<=a.size(); i++) r+="0";
  for(i=a.size()-1; i>=0; i--)
   {
    r[i]=a[i]-'0'+b[i]-'0'+o;
    o=r[i]/10;
    r[i]%=10;
    r[i]+='0';
    if(i==0 && o>0) { string t=""; t+=o+'0'; t+=r; r=t; }
   }
 } 
void mull(string a, int b, string &r)
 {
  int i, o=0;
  r="";
  if(b==0) { r="0"; return; }
  for(i=1; i<=a.size(); i++) r+="0";
  for(i=a.size()-1; i>=0; i--)
   {
    r[i]=(a[i]-'0')*b+o;
    o=r[i]/10;
    r[i]%=10;
    r[i]+='0';
    if(i==0 && o>0) { string t=""; t+=o+'0'; t+=r; r=t; }
   }
 }
int main()
 {
  string a, c, r, r2, r3;
  int b, d;
  cin>>a>>b>>c>>d;
  mull(a, b, r);
  mull(c, d, r2);
  suml(r, r2, r3);
  cout<<r3<<endl;
  return 0;
 }
