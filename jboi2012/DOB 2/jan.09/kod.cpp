#include<iostream>
using namespace std;
int main()
{
   long long int n;
   cin>>n;
   long long int n1=abs(n);
   int br=0;
   int e,d,s,h,dh,sh;
   e=n1%10;
   d=(n1/10)%10;
   s=(n1/100)%10;
   h=(n1/1000)%10;
   dh=(n1/10000)%10;
   sh=n1/100000;
   int b;
   if(e%2==0){br++;}
   if(d%2==0){br++;}
   if(s%2==0){br++;}
   if(h%2==0){br++;}
   if(dh%2==0){br++;}
   if(sh%2==0){br++;}
   b=dh*100+s*10+e;
   int v;
   v=e*100+s*10+dh;
   cout<<br<<abs(b-v)<<endl;
   system("pause");
   return 0;
}
