/*
TASK:diet
LANG:C++
*/
#include<iostream>
using namespace std;
/*
long br1,br2,br3,minbr,n,m,x,y,z;
void carrots1 (long a, long b, long c, long br)
{
   if (br1==m) {if (br<minbr) {minbr=br;} ;}
   br1++;
   for(long i=1;i<=3;i++)
   {
      if (i==1) {if (a>0) {a--;}; carrots1(a,b,c,br);}
      if (i==2) {if (b>0) {b--;br++;br1++;}; carrots1(a,b,c,br);}
      if (i==3) {if (c>0) {c--;b++;br++;}; carrots1(a,b,c,br);}
   }
}
void carrots2 (long a, long b, long c, long br)
{
   if (br2==m) {carrots1(a,b,c,br);}
   br2++;
   for(long i=1;i<=3;i++)
   {
      if (i==1) {if (b>0) {b--;}; carrots2(a,b,c,br);}
      if (i==2) {if (c>0) {c--;a++;br++;}; carrots2(a,b,c,br);}
      if (i==3) {if (a>1) {a=a-2;}; carrots2(a,b,c,br);}
   }
}
void carrots3 (long a, long b, long c, long br)
{
   if (br3==m) {carrots2(a,b,c,br);}
   br3++;
   for(long i=1;i<=3;i++)
   {
      if (i==1) {if (c>0) {c--;}; carrots3(a,b,c,br);}
      if (i==2) {if (a>0 && b>0) {a--;b--;} ;carrots3(a,b,c,br);}
      if (i==3) {if (a>2) {a=a-3;} ;carrots3(a,b,c,br);}
   }
}
*/
int main()
{
   long x,y,z,n,m,k,i,br=0;
   cin>>x>>y>>z;
   n=10*x+20*y+30*z;
   m=n/60;
   //carrots3(x,y,z,0);
   if (z>=m) {z=z-m;}
   else 
   {
      k=m-z;
      z=0;
      for(i=1;i<=k;i++)
      {
         x--;
         y--;       
      }
   }
   if (x>=m) {x=x-m;}
   else
   {
      k=m-x;
      x=0;
      if (k%2==1 && z>0) {k--;z--;y++;br++;}
      while (k>0 && y>0)
      {
         y--;
         k=k-2;
         br++;
      }
   }
   if (y>=m) {y=y-m;}
   {
      k=m-y;
      while (x>1 && k>0)
      {
         k--;
         x=x-2;
      }
      while (z>0 && k>0)
      {
         k--;
         z--;
         br++;
      }
   }
   cout<<m<<" "<<br<<endl;
   //system("pause");
   return 0;
}
