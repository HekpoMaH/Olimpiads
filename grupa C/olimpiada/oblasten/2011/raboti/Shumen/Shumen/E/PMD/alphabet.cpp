#include<iostream>
using namespace std;
string s;
int n,m;
int read()
{
     int br0,i;
     cin>>n>>m;
     for(i=0;i<=m;i++)
     {
          getline(cin,s);
          if(s[0]>='A'&&s[0]<='Z')
          {
               if((int)(s[0]-'A')==n)
               {
                    return i;
               }
          }
          else{if(((int)(s[0]-'a')+1)==n){return i;}}
          }
          return 0;}
int main ()
{
if(read())
{
cout<<"win"<<" "<<read()<<endl;
}
else
cout<<"lose"<<endl;

return 0;
}
