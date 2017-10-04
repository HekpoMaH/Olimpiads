#include<iostream>
#include<string>
using namespace std;
long long k,c,a,i,d;
string s,ch;
char p;
int main()
{
  cin>>k;
  c=1;
  while(i<=k)
  {
    ch="";
    a=c;
    while(a!=0)
    {
      ch+=a%10+'0';
      a/=10;
    }
    d=ch.size();
    for(long long int j=0;j<d/2;j++)
    {
      p=ch[j];
      ch[j]=ch[d-j-1];
      ch[d-j-1]=p;
    }
    i+=d;c++;
    //cout<<ch<<endl;
    s+=ch;
  }
  cout<<s[k-1]<<endl;
  return 0;
}
