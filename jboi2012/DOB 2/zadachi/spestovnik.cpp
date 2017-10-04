#include <iostream> 
using namespace std;
int main()
{
 int a=1, b=8,  c=320;
 long br1,o1,n,p,q;
 float c1,c8,c320;
 cin>>n;
 c1=0.12;c8=0.82;c320=30.5;
 p=int(c8/c1)+1;q=int(c320/c8)+1;
 br1=n/c;o1=n%c;
 if(o1+(40-q)*b+(8-p)*a>=c) 
cout<<br1+1<<" "<<0<<" "<<0<<endl;
   else 
    {
      cout<<br1;br1=o1/b;o1=o1%b;
      if (o1+(8-p)*a>=b) 
 cout<<" "<<br1+1<<" "<<0<<endl;
      else cout<<" "<<br1<<" "<<o1<<endl;
     }
}
