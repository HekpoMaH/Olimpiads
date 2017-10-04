#include<iostream>
using namespace std;
long a,b;
int main()
{ cin>>a>>b;
  long x=a>b?a:b;
  long y=a<b?a:b;
  if(a==b)
   { long apf=1;
     for(int i=2; i<=a; i++)
      apf+=3;
     cout<<apf<<endl; 
   }
  else
   { if(a==1 || b==1)
      cout<<x<<endl;
     else
      { if(a==2 || b==2)
         { long apf=4;
           for(int i=3; i<=x; i++)
            if(i%2==0)
             apf+=2;
           cout<<apf<<endl;  
         }
        else
         { if(x%2!=0)
            { if(y%2!=0)
               { long apf=x/2;
                 apf*=(y/2);
                 apf++;
                 apf*=2;
                 apf++;
                 cout<<apf<<endl;
               }
              else
               { long apf=x/2;
                 if(apf%2==0)
                  { apf*=(y/2);
                    apf*=2;
                  }
                 else
                  { apf*=(y/2);
                    apf--;
                    apf*=2;
                  }
                 cout<<apf<<endl;
               } 
            }
           else
            { if(y%2!=0)
               { long apf=x/2;
                 if((y/2)%2!=0)
                  { apf*=y/2;
                    apf++;
                    apf*=2;
                  }
                 else
                  { apf*=y/2;
                    apf--;
                    apf*=2;
                  } 
                 cout<<apf<<endl; 
               }
              else
               { long apf=x/2;
                 apf*=(y/2);
                 apf--;
                 apf*=2;
                 apf--;
                 cout<<apf<<endl;
               } 
            } 
         } 
      } 
   } 
return 0;
}
