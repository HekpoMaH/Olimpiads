#include<iostream>
#include<vector>
using namespace std;
long n,k,i,x,n1;
vector<pair<long,long> >a;
int main()
{
 
 cin>>n>>k;
 a.push_back(make_pair(0,0)); 
 
 for(i=1;i<=n;i++)
 {
  cin>>x;
  a.push_back(make_pair(x,i));
 }
 
 n1=n; 
 
 
 
 while(k>n)
  k-=n;
 k++;
 
 while(n1!=1)
 {
                          
  x=a[k].first;
  
  a[k].first=0;
  
  n1--;
  k=k+x-(n-n1)+1;
  while(k>n)
   k-=n;
 }
   
 for(i=1;i<=n;i++)
 {
  if(a[i].first!=0)
   cout<<a[i].second<<endl;
 }
  
 //system("pause");
 return 0;
}
