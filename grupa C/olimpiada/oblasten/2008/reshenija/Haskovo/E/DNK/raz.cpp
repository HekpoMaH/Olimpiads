//program raz
#include<iostream>
using namespace std;
int main()
{
     int raz, n, minc, maxc, m1,m2, d1, d2;
     cin>>n;
     minc=10000;

for (int m=1;m<=n;m++)
{
     if (n%m==0){
                 m1=m;
                 m2=n/m;
                 raz=abs(m1-m2);
     if(raz<=minc)
                 {
                 minc=raz;
                 d1=m1;
                 d2=m2;
                 }
     }
}
     if(d1<=d2) cout<<d1<<" "<<d2<<endl;
     if(d2<d1) cout<<d2<<" "<<d1<<endl;        
     return 0;
}
