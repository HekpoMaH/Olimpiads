#include<iostream>
#include<string>
using namespace std;
int br,n,mx;
string s;
int main()
{
  getline(cin,s,'0');
  n=s.size();
  for(int i=0;i<n-1;i+=2)
  {
    if(s[i]==s[i+2])br++;

    else
    {
      if(br>mx)mx=br;
      br=0;
    }
    if(i+2==n-1)
    {
      if(br>mx)mx=br;
      br=0;
    }
    //cout<<"br="<<br<<" "<<"mx="<<mx<<" "<<"s[i]="<<s[i]<<" "<<"s[i+2]="<<s[i+2]<<endl;
  }
  cout<<mx+1<<endl;
  return 0;
}
