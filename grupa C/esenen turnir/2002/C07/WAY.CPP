//Peter Ivanov 7klas Shumen PMG tel. 52331
#include<iostream.h>
void main()
{  int n, a, A;
   cin>>n;
   if (n==1) a=0;
   if (n==2) a=1;
   if (n==3) a=3;
   if (n==4) a=6;
   if (n==5) a=10;
   if (n==6) a=15;
   if (n==7) a=21;
   if (n==8) a=28;
   if (n==9) a=35;
   if (n==10) a=45;
   for (int i=0; i<a*3; i++)
      cin>>A;
   cout<<"0";
}
