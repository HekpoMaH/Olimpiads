#include <iostream>
#include<string.h>
using namespace std;
long n,i,j,br1,br2,l;
string s;
int main()
{
 
 cin>>n;
 
 for(i=1;i<=n;i++)
 {  
  s.clear();
  br1=0;
  br2=0;
  cin>>s;
  l=s.size();
  for(j=0;j<=l-1;j++)
  {
   if(s[j]=='C' || s[j]=='A' ||  s[j]=='T')
    br1++;
   
   if(s[j]=='G' || s[j]=='P' ||  s[j]=='I')
    br2++;
  }
  
  if(br1>br2)
   cout<<"CAT"<<endl;
  
  if(br1<br2)
   cout<<"GPI"<<endl;
 
  if(br1==br2)
   if(br1==0)
    cout<<"UFO"<<endl;
   else
    cout<<"CAT-GPI"<<endl;
  
 } 
 
// system("pause");
 return 0;
}
