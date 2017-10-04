#include <iostream>
using namespace std;
int main()
{long r1,r2,r3,r4,a,b,c,d;
 cin>>r1>>r2>>r3>>r4;
 bool f=true;a=-1000;
 do
   {if (a!=0)
     {b=-1000;
      do
       {if (b!=0)
         {c=a*a*b;d=a*b*b;
          if (((a==r1)||(r1==0))&&
             ((b==r2)||(r2==0))&&
             ((c==r3)||(r3==0))&&
             ((d==r4)||(r4==0)))
                  {cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   f=false;
                  }
         }
      b++;}
      while ((b<=a)&&f);
     }
      a++; 
   }
while ((a<=1000)&&f);       
  return 0;
}  

