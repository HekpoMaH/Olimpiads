#include<iostream>
#include<string>
using namespace std;
string a,b,izh;
long n,i,fl;
char c;
int main()
{
  cin>>n;
  cin>>a;
  do
  {
    cin.get(c);
    b+=c;
    i++;
    if(b[i-1]!=' ' && fl==0){fl=1;b.erase(0,i-1);}
  }while(!cin.eof());
  cout<<b;
  return 0;
}
