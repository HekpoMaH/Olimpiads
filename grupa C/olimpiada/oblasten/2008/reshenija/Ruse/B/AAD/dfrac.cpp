#include<iostream>
using namespace std;
main()
{
long long a,b,c,i,br=0;
long long k,p;


cin>>a>>b>>k>>p;


for(i=1;i<p+k;)
{


if (a/b<1 && a!=0) {a=a*10;}    
else {c=a/b;a=a-(c*b);i++;if (i>k) {cout<<c;}}


        
}
 

                  


}





