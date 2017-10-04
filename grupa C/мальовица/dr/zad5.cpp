#include<iostream>
#include<string>
using namespace std;
int n,a,k,c;
string ch;
int main()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>a;
     k=a;
     ch="";
     while(k>0)
     {
       ch+=k%2+'0';
       k/=2;
     }
     ch+=k+'0';//cout<<ch<<endl;
     while(ch.size()<8)ch+='0';
     //cout<<ch<<endl;
     k=ch[0]-'0';
     for(int i=1;i<8;i++)k=k*2+ch[i]-'0';
     cout<<k<<endl;
   }
   return 0;
}
