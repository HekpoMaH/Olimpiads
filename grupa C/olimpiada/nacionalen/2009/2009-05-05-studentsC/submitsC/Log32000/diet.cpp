/*
TASK:diet
LANG:C++
*/
#include<iostream>
using namespace std;

int main()
{
int a,b,c,d,r=0;
cin>>a>>b>>c;
d=(a+2*b+3*c)/6;
cout<<d<<' ';
if(c<d)
{
 b=b-(d-c);
 a=a-(d-c);
 if(b>d)
  r=(d-a+1)/2;    
}
else
{
 c=c-d;
 if(b<d)
  if(a>=d)
  {            
   b=b+(a-d)/2;
   a=d+(a-d)%2;
   r=((d-b)*2)/3 + (d-b)%3;
   if(a%2==1 && (d-b)%3==1)
   r--;      
  }
  else
  {   
   //cout<<a<<b<<c<<d;   
   r=((d-b)*2)/3;
   //cout<<r<<endl;
   b=d-(d-b)%3;
   r=r+((d-a)/3)*2;
   //cout<<r<<endl;
   //cout<<r<<' ';
   a=d-(d-a)%3;
   //cout<<d-a<<endl<<endl;
   if(d-b==2)
     r=r+d-a; 
   else
    if(d-b==1)
     if(d-a==2)
      r=r+2;
     else
      r++;
    else
     r=r+d-a;      
  } 
 else
 {
  b=b-d;
  if(d-a>=2*b)
  {
   r=b;
   a=a+2*b;
   r=r+((d-a)/3)*2+(d-a)%3;
  }
  else
   r=(d-a+1)/2;    
 }  
}
cout<<r<<endl;
//system("pause");
return 0;
}
