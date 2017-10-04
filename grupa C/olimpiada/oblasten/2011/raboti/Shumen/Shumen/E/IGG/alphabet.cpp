#include<iostream>
using namespace std;
int main()
{
  long long int n,m,pl,i,p,l=0,j;
  char s[100],a;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
  cin>>s[0];
  if(s[0]>='A'&&s[0]<='Z')
  a='A'+(n-1);
  else
  a='a'+(n-1);
  if(s[0]==a){pl=i;l=1;}
  cin.getline(s,80,'.');
  }
  if(l!=0)
  cout<<"win"<<" "<<pl<<endl;
  else
  cout<<"lose"<<endl;




return 0;
}