#include<iostream>
#include<vector>
using namespace std;
long m,i,n,k,x,br;
vector<long> a,b;
int main()
 {
 cin>>n>>k;
 for(i=1;i<=n;i++)
 {cin>>x;
  a.push_back(x);
  b.push_back(i);
 }
 m=n;
 while(n>1)
 {
  while(k>n)
  k=k-n; 
  x=a[k-1];
  a.erase(a.begin()+k-1);
  b.erase(b.begin()+k-1);
  n--;
  k+=x-1;
 }
 cout<<b[0]<<endl;
 return 0;
 }
