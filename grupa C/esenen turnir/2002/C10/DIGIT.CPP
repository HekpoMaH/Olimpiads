#include<iostream.h>
void main()
{long i=0,k,a=1,b;
float n;
cin>>k;
   while(i<k)
   {

   do
   {
   b=a%10;
   a=a/10;i++;
   if(i==k)break;
   }
   while(a!=0);

   n++;a=n;
   }
   cout<<"b="<<b<<endl;
   }


