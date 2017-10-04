#include<iostream>
using namespace std;

 unsigned long long int a,b,k,p;
 int main()
 {
  cin>>a>>b>>k>>p;
  k-=1;
  for(unsigned long long int i=p+k; i>0; i--)
  {
   if(a!=0)
   {
    a*=10;
    if(k==0)
     {
            cout<<a/b;
            
     }
    else k--;   
    a%=b;
   }
   else cout<<"0"; 
  }
  cout<<endl;
  return 0;
}
