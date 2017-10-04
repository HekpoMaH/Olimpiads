#include<iostream>
#include<string>
using namespace std;
int main()
{
 int n5,i5,n,i,i2,br,br2,b,b1;
 string s;
 char c;
 cin>>n5;
 cin.get(c);
 for(i5=1;i5<n5;i5++)
 {
  br=br2=0;
  i=0;
  getline(cin,s);
  n=s.size();
  //cout<<s<<" "<<s[n-1]<<endl;
  if(s[0]!=' '){br++;while(s[i]!=' '){br2++;i++;}}
  while(i<n)
  {
   while(s[i]==' '){i++;if(i==n)break;}
   br++;
   while(s[i]!=' '){i++;br2++;if(i==n)break;}
  }
  //cout<<br<<" "<<br2<<endl;
  b=(60-br2)/(br-1);
  b1=(60-br2)%(br-1);
  i=0;
  if(s[0]!=' ')
   while(s[i]!=' '){cout<<s[i];i++;}
  else
  {
   while(s[i]==' '){i++;}
   while(s[i]!=' '){cout<<s[i];i++;}
  }
  while(i<n)
  {
   if(b1)
   {
    b1--;
    for(i2=0;i2<=b;i2++)cout<<" ";
   }
   else for(i2=0;i2<b;i2++)cout<<" ";
   while(s[i]==' '){i++;if(i==n)break;}
   while(s[i]!=' '){cout<<s[i];i++;if(i==n)break;}
  }
  cout<<endl;
 }
 getline(cin,s);
 i=0;
 n=s.size();
 if(s[0]!=' ')
  while(s[i]!=' '){cout<<s[i];i++;if(i==n)break;}
 else
 {
  while(s[i]==' '){i++;if(i==n)break;}
  while(s[i]!=' '){cout<<s[i];i++;if(i==n)break;}
 }
 while(i<n)
 {
  cout<<" ";
  while(s[i]==' '){i++;if(i==n)break;}
  while(s[i]!=' '){cout<<s[i];i++;if(i==n)break;}
 }
 cout<<endl;
 return 0;
}
