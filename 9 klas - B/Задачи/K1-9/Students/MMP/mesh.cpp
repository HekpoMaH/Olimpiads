#include <iostream>
using namespace std;
long a,b,maxi,br,c;
int main()
{
 cin>>a>>b;
 maxi=max(a,b);
if(a==b)cout<<a+b<<endl;
else
{
   maxi/=2;
   br+=maxi*3;
   c=maxi/3;
   if(c==1)br++;
   c=c/2;
   br=br+c*3;      
 cout<<br<<endl;
}
 
 return 0;       
}
