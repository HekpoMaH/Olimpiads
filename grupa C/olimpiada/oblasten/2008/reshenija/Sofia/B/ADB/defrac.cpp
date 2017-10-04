#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a,b,p,k,ost,chas,br=0,q,r;
    cin>>a>>b;
    cin>>k>>p;
    r=10*10*10*10*10*10*10*10*10*10*10*10*10*10*10*10*10*10;
    if (a>0 || a<=b || a<30000000 || b>0 || b>a || b<30000000 || k>0 || k<r || p>0 || p<50)
{
    ost=a%b;
    q=k+p-1;
     do               
     {
     chas=(ost*10)/b;
     br++;
     if (br>=k)
      {
      cout<<chas;
      }
     ost=(ost*10)%b;
     }while (br!=q);
     cout<<endl;
}else cout<<"BAT INPUT"<<endl;                
return 0;
}
