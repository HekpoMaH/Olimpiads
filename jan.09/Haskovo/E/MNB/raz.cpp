//raz
#include<iostream>
using namespace std;
int main()
{
    int n,i,min,m1,m2,r,a,b;
    min=10000;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       if(n%i==0) {m1=n/i;
                   m2=i;}
       r=abs(m1-m2);
       if(r<min) {min=r;
                  a=m1;
                  b=m2;}
    }
    if(a<b) {cout<<a<<" "<<b<<endl;}
    else {cout<<b<<" "<<a<<endl;}
    system("pause");
    return 0;
}
   
