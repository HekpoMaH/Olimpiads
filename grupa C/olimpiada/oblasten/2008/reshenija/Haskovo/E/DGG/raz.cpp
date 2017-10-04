//raz 
#include<iostream>
using namespace std;
int main()
{
     long int n,a,b,c,f;
     cin>>n;
     long int min=999999;
     long int r,r2;
     for (int d=1;d<=n;d++ )
     {
     if(n%d==0)
     {  
               
               a=d;
               b=n/d;
               r=abs(a-b);
               if(r<min){
                         min=r;
                         c=a;
                         f=b;
                         }
                                                 
      }
      }
      if (c<f)   cout<<c<<" "<<f<<endl;
      else cout<<f<<" "<<c<<endl;   
     return 0;
     }
     
  

