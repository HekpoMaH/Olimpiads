#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[1000001];
long long n;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int i=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==a[i+1]){a[i].erase();a[i+1].erase();i++;}
    else cout<<a[i]<<endl;
  }
  //for(int i=0;i<n;i++)
  //{
    //if(a[i].size()>0){cout<<a[i]<<endl;break;}
  //}
  return 0;
}
