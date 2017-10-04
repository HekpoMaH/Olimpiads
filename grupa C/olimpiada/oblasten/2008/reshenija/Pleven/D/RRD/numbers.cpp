#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long a,b,a2b,ab2; 
    cin>>a>>b>>a2b>>ab2;
    
    if(a!=0 && b!=0){
    a2b=a*a*b;
    ab2=a*b*b;
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<endl;} 
    
    if(a!=0 && b==0)
    {
            
    if(a2b!=0) {b=a2b/(a*a);}
    if(ab2!=0) {b=sqrt( (ab2/a) );
    if(b==1) b=-1;
    if(b==2) b=-2;
    if(b==3) b=-3;
    if(b==4) b=-4;
    if(b==5) b=-5;
    if(b==6) b=-6;
    if(b==7) b=-7;
    if(b==8) b=-8;
    if(b==9) b=-9;}
    a2b=a*a*b;
    ab2=a*b*b;
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<endl; 
    }
    if(a==0 && b!=0)
    {
            if(a2b!=0) {a=sqrt( (a2b/b) );
                       }
                        
            if(ab2!=0) a=ab2/(b*b);
    a2b=a*a*b;
    ab2=a*b*b;
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<endl;    
    
}
    if(a==0 && b==0)
    {
             for(a=-1000;a<=1000;a++)
            {
             for(b=a;b>=-1000;b--)
              if(a2b!=0 && ab2==0) if(a*a*b==a2b) break; else;
              else
              if(a*b*b==ab2) break;
             if(a*b*b==ab2) break;
            }
             if(a2b==0 && ab2==0 ) {a=-1000; b=-1000;}
            
            
    a2b=a*a*b;
    ab2=a*b*b;
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<endl; 
} 
  
    //system("PAUSE");
    return 0;
}
