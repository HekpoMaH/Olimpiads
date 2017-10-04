#include<iostream>

using namespace std;

long n,br,step,br1,x,ans,ans1,fl;
string s;
int main()
{
 cin>>s;
 ans=s[0]-'0';
 for(br=1; br<s.size()-1; br+=2)
 {
  if(s[br]=='*')
  {
   ans*=(s[br+1]-'0');
  }
  if(s[br]=='+')
  {
   ans+=(s[br+1]-'0');
  }
  if(s[br]=='-')
  {
   if(fl==0) {fl=1; ans1=ans;  ans=(s[br+1]-'0'); continue;}
   ans1-=ans;
   ans=(s[br+1]-'0');
  }
 }
 cout<<ans1-ans<<endl;
 return 0;
}







/*



#include<iostream>

using namespace std;


long x,br,ans,step,rpoz;
long a[100];
bool mini;
string s;
long min(long x, long y)
{
 if(x<y) return x;
 return y;
}
long max(long x, long y)
{
 if(x>y) return x;
 return y;
}


long find(long poz, bool mini1)
{
 long br=poz+1;
 long ans=s[poz]-'0';
 step+=2;
 if(s[br]=='*')
 {
  x=find(br+1,true);
  ans*=x;
 }
 if(s[br]=='+')
 {
  x=find(br+1,true);
  ans+=x;
 }
 if(s[br]=='-')
 {
  x=find(br+1,false);
  ans-=x;
 }
 cout<<poz<<" "<<x<<" "<<endl;
 if(mini==true)
 {
  if((s[poz]-'0')>ans) { return (s[poz]-'0');}
  else {rpoz=br-2; return ans;}
 }
 else
 {
  if((s[poz]-'0')<ans) { return (s[poz]-'0');}
  else {rpoz=br-2; return ans;}
 }
}



int main()
{

cin>>s;
ans=s[0]-'0';
for(br=1; br<s.size(); br++)
{
  bool fl=0;
  if(br%2==1)
  {
   if(s[br]=='*')
   {
    mini=true;
    x=find(br+1,true);
    mini=true;
    br=rpoz;
    ans*=x;
    fl=1;
    cout<<ans<<" "<<x<<"     "<<rpoz<<"   1 "<<endl;
   }
   if(s[br]=='+' && fl!=1)
   {
    mini=true;
    x=find(br+1,true);
    br=rpoz;
    ans+=x;
    fl=1;
    cout<<ans<<" "<<x<<"     "<<rpoz<<"    2"<<endl;
   }
   if(s[br]=='-' && fl!=1)
   {
    mini=false;
    x=find(br+1,false);
    br=rpoz;
    ans-=x;
    cout<<ans<<" "<<x<<"     "<<rpoz<<"    3"<<endl;
   }
   //br--;
  }
}
cout<<ans<<endl;


 return 0;
}
*/