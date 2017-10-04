#include<iostream>
#include<string>
using namespace std;
string s[1024];
int main()
{
  int n;
  cin>>n;
  int k=0,i;
  for(int w=1;w<=n;w++)
  {
    cin>>s[k];
    i=0;
    while(s[i]!=s[k])i++;
    if(i==k)k++;
  }
  cout<<k<<endl;
  return 0;
}

