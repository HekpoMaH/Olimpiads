#include<iostream>
#include<string>
using namespace std;
long long m[1004],q,x,br,b,lc;
char op;
long long ppg(long long s)
{
  long long xr=0;
  for(int i=0;i<s;i++){xr^=m[i];}
  return xr;
}
int main()
{
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cin>>op;
    if(op=='A')
    {
      cin>>x;
      m[br]=x;
      br++;
    }
    if(op=='B')
    {
      b=ppg(br);
      if(b==0)cout<<-1<<endl;
      cout<<b<<endl;
    }
  }
  return 0;
}
