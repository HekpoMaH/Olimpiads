#include<iostream>
#include<string>
using namespace std;
int min1,min2,c1,c2,min3,c3;
string s1,s2;
int main()
{
  cin>>s1;
  cin>>s2;
  c1=(s1[0]-'0')*10+s1[1]-'0';min1=(s1[3]-'0')*10+s1[4]-'0';
  c2=(s2[0]-'0')*10+s2[1]-'0';min2=(s2[3]-'0')*10+s2[4]-'0';
  //cout<<c1<<":"<<min1<<endl<<c2<<":"<<min2<<endl;
  min1+=c1*60;
  min2+=c2*60;
  if(min1>min2)min3=24*60-(min1-min2);
  else min3=min2-min1;
  //cout<<min3<<endl;
  c3=min3/60;
  min3%=60;
  if(c3<10)cout<<"0"<<c3<<":";
  else cout<<c3<<":";
  if(min3<10)cout<<"0"<<min3<<endl;
  else cout<<min3<<endl;
  return 0;
}
