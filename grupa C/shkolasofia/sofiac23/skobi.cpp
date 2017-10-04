#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
string s;
double br1,br2,br3,n;
int main()
{
  ios::sync_with_stdio(false);
  cin>>s;
  n=s.size();
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(')br1++;
    if(s[i]==')')br1--;
    if(s[i]=='[')br2++;
    if(s[i]==']')br2--;
    if(s[i]=='{')br3++;
    if(s[i]=='}')br3--;
  }
  br3=abs(br3);
  br2=abs(br2);
  br1=abs(br1);
  cout<<br3+br2+br1<<endl;
  return 0;
}
