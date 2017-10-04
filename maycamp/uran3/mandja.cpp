#include<iostream>
#include<string>
using namespace std;
string m;
long long br,buk[32];
char a;
int main()
{
  cin>>m;
  for(int i=0;i<m.size();i++)
  {
    if(m[i]>='a'&&m[i]<='z')m[i]=m[i]-'a'+'A';
    buk[m[i]-'A']++;
  }
  long long mx=0;
  for(int i=0;i<32;i++)
  {
    if(buk[i]>mx){mx=buk[i];a=i+'A';}
  }
  cout<<mx<<" "<<a<<endl;
  return 0;
}
