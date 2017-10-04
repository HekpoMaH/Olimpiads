#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
     int a,b,p,x=1,z=1,y=1,l1=0,l2=0,D=10,i;
     long long k;
     string s;
     cin>>a>>b>>k>>p;
     while(l1&&l2)
     {
          if(l1) y=y*10;
          if(l2) z=z*10;
          if(y>=b) l1=1;
          if(z>=a) l2=1;
     }
     D=D*(y/z);     
     for(i=1;i<k;i++)
     {
          a=(a*D)%b;
     }
     for(i=1;i<=p;i++)
     {
          x=a*D/b;
          a=(a*D)%b;
          s+=(x+'0');
     }
     cout<<s<<endl;
return 0;
}
