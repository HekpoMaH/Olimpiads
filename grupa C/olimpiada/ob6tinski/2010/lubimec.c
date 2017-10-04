#include<iostream>
#include<string>
using namespace std;
int n,k;
string s;
int ed=-1,tr=-1,br;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    k=s.size();
    for(int j=0;j<k;j++)
    {
      if(s[j]=='1')ed=j;
      if(s[j]=='3')tr=j;
      if(ed<tr&&ed!=-1&&tr!=-1){br++;break;}
    }
    ed=-1;
    tr=-1;
  }
  if(br!=0)cout<<br<<endl;
  else cout<<"No"<<endl;
  return 0;
}
