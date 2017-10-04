#include <iostream>
#include<math.h>
using namespace std;
long a,b,c,d,a1,b1,c1,d1,ok,x;
int main()
{
 cin>>a1>>b1>>c1>>d1;


  if(a1!=0 && b1!=0 && c1!=0 && d1!=0)
   {a=a1;b=b1;c=c1;d=d1;}
  
  if(a1==0 && b1==0 && c1==0 && d1==0)
   {a=-1000;b=-1000;c=-1000;d=-1000;}  
  
  if((!(a1!=0 && b1!=0 && c1!=0 && d1!=0)) && (!(a1==0 && b1==0 && c1==0 && d1==0)))
  {
   if(a1==0 && b1==0)
   {
    if(c1==0)
    {
	 for(a=-1000;a<=1000;a++)
	 {
	  for(b=-1000;b<=1000;b++)
	   if(a*b*b==d1)
	    {ok=1;break;}
	  if(ok==1)
	   break;}
     
	 d=d1;
	 c=a*a*b;
	 }
     
     else
     {
	  for(a=-1000;a<=1000;a++)
	  {
	   for(b=-1000;b<=1000;b++)
	    if(a*a*b==c1)
	     {ok=1;break;}
	   if(ok==1)
	    break;}
           
	  c=c1; d=a*b*b;
	  }
   }  
    else
	{
	 if(a1==0)
	 {
	  if(c1==0 && d1==0)
	   {a=-1000;
	    b=b1;
		c=a*a*b;
		d=a*b*b;}
	  }     
	 else
     {
	  if(c1==0 && d1==0)
	   {b=-1000;
	    a=a1;
		c=a*a*b;
		d=a*b*b;}
	}	    
  }
  
    if((!(a1!=0 && b1!=0 && c1!=0 && d1!=0)) && (!(a1==0 && b1==0 && c1==0 && d1==0)))
    {
	 if(a1==0 && b1==0 && c1!=0 && d1!=0)
	 {
	  for(a=-1000;a<=1000;a++)
	  {
	   for(b=-1000;b<=1000;b++)
	    if(a*b*b==d1 && a*a*b==c1)
	     {ok=1;break;}
	   if(ok==1)
	    break;ok=0;}
     
	  c=c1;
	  d=d1;
	 }
     
	 if(a1==0 && b1!=0 && c1==0 && d1!=0)
	 {
	  b=b1;
	  d=d1;
      a=d/b/b;
      c=a*b*b;
	 }
     
	 if(a1==0 && b1!=0 && c1!=0 && d1==0)  
     {
	  b=b1; c=c1;
	  x=c/b;
	  a=sqrt(x);
	  d=a*b*b;
	 }  
     
	 if(a1!=0 && b1==0 && c1==0 && d1!=0)
     {
	  a=a1;
	  d=d1;
	  x=d/a;
	  b=sqrt(x);
	  c=a*a*b;
	 }
	  
    if(a1!=0 && b1==0 && c1!=0 && d1==0) 
	{
	 a=a1;
	 b=c1/a/a;
	 c=c1;
	 d=a*b*b; 
    }  
   if(a1!=0 && b1!=0 && c1==0 && d1==0)  
   {
	a=a1;
	b=b1;
	c=a*a*b;
	d=a*b*b;
   }
  
  if(a1==0 && b1!=0 && c1!=0 && d1!=0)	  
  {
   b=b1; c=c1; d=d1;
   a=d/b/b;
  }
 	  
  if(a1!=0 && b1==0 && c1!=0 && d1!=0)	  
  {
   a=a1; c=c1; d=d1;
   b=c/a/a;
  } 
  
  if(a1!=0 && b1!=0 && c1==0 && d1!=0)	  
  {
   a=a1; b=b1; d=d1;
   c=a*a*b;
  }  
	  
  if(a1!=0 && b1!=0 && c1!=0 && d1==0)	  
  {
   a=a1; b=b1; c=c1;
   d=a*b*b;
  }  
	  
 }  
  
  }
  
  
 cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
 //system("pause");
 return 0;
} 
