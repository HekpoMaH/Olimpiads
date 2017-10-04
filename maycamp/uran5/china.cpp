#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
string a,s[2500];
long long b,c,C,m,p,n,br,lp,sum;
int main()
{
  cin>>n;
  cin>>b>>c>>C>>m>>p;
  cin>>a;
  //cout<<a<<endl;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]!='a'){s[br]+=a[i];}
    else br++;
  }
  //cout<<br<<endl;cout<<s[br-1]<<endl<<s[br-2]<<endl;
  //for(int i=0;i<br;i++)cout<<s[i]<<endl;
  int tr;
  for(int i=0;i<br;i++)
  {
    reverse(s[i].begin(),s[i].end());
    //cout<<s[i]<<" ";
    lp=-1;tr=s[i].size();
    for(int j=0;j<tr;j++)
    {
      if(s[i][j]=='p')lp=j+1;
    }//cout<<lp<<endl;
    for(int j=0;j<lp;j++)
    {
      //cout<<j<<endl;
      if(s[i][j]=='b')sum+=b;
      if(s[i][j]=='c')sum+=c;
      if(s[i][j]=='C')sum+=C;
      if(s[i][j]=='m')sum+=m;
      if(s[i][j]=='p')sum+=p;
    }
    //cout<<sum<<endl;
  }
  cout<<sum<<endl;
  return 0;
}
