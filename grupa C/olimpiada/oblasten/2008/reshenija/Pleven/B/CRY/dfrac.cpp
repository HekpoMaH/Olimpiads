#include<iostream>
#include<math.h>
using namespace std;
long p,a1[1001],b1[1001],i,m,j,h,br,y,x;
unsigned long long k;
double s,l,a,b;
int main()
{
    cin>>a>>b>>k>>p;


 
    s=a/b;
    l=s;
    if(s*b!=a)
    {
    
    
    do
    {
     l*=10;
     i++;
     a1[i]=floor(l);
     a1[i]%=10;
     
     if(a1[i]==a1[1] && i!=1)
     { break; }
        }
        while(1==1); 
     a1[i]=0;
     i--;
     for(j=k;j<=i;j++)
     {
  
     cout<<a1[j];
      br++;
     if(br==p)
      { break; }
     }
     if(br<p)
     { 
do
{
     for(y=1;y<=i;y++)
     { 
                      cout<<a1[y];
                      br++;
                      if(br==p) 
                   break; 
                    }
                    }while(br!=p); 
                    } }
    if(s*b==a)
     {
              s-=floor(s);
              do
              {  br++;
                    s*=10;
                    if(floor(s)==s)
                    { break; }
                    }
       while(floor(s)!=ceil(s));
       x=s;    
       for(j=br;j>=1;j--)
       { a1[j]=x%10;
           x/=10;
           if(x==0) {break;} }
     for(i=k;i<=p+k-1;i++)
     { cout<<a1[i];
         
       }
                    
                    }  
        
    
    return 0;
}
