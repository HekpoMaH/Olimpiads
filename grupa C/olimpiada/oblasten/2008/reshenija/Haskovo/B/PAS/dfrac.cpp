#include <iostream>
#include <cmath>
using namespace std;
int c[90000];
void del(int a, int b)
{  
  c[0]=a/b;
  if ((a%b)!= 0) a=a*10;
  else a=0;
  for (int i=1;i<90000;i++)
  {   if (a==0) c[i]=0;
      if ((a<b) && (a!=0))
       {
                a=a*10;c[i]=a/b;
                a=(a-(b*(a/b)));
       }
       else c[i]=a/b;a=(a-(b*(a/b)));
     
      
  }
          
}
int main ()
{
    int a,b,k,p;
    cin>>a>>b;
    cin>>k>>p;
    del(a,b);
    for (int i=k;i<p+k;i++)
    {
        cout <<c[i];
    }
    return 0;
}
