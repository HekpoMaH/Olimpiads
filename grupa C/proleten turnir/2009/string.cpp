#include<iostream>
#include<string>
using namespace std;
long long n,k,fact[22],k1,del,used[22],a[22],br,g;
char tr;
string s,s1="abcdefghijklmnopqrstuvwxyz";
int main()
{
  cin>>n>>k;
  fact[0]=1;
  for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i;
  k--;
  for(int i=n-1;i>=0;i--)
  {
    a[br]=k/fact[i];
    br++;//cout<<a[br-1]<<" "<<k<<" "<<k-a[br-1]*fact[i]<<endl;
    k-=a[br-1]*fact[i];
    //cout<<a[br-1]<<" "<<k<<endl;
  }
  for(int i=0;i<br;i++)
  {
      cout<<a[i]<<" ";
    tr=s1[a[i]];
    s+=s1[a[i]];
    g=s1.size();
    for(int i=0;i<g;i++)
    {
      if(s1[i]==tr){s1.erase(i,1);break;}
    }
  }
  cout<<s<<endl;
  return 0;
}
