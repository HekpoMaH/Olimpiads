#include<iostream.h>
#include<math.h>
long long a,b,k,i=0,br=0,w;

long double v ;
int p;

int main ()
{
  cin>>a;
  cin>>b;
  cin>>k>>p;
  v=1.0*a/b;
   br=0;
   for( i=0;i<k-1;i++)
   v=v*10;
 v=v-floor(v); 
do{ int w=v*10; 
       cout<<w;
       v=v*10-w ;
       br++;   
            }while(br != p);
   cout<<endl;
    return 0;
    }
