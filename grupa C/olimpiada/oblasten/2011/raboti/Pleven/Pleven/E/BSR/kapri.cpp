#include <iostream>

using namespace std;

int main()
{int l,r,c,k,n,p,i,br=0;
cin>>n;
while(br<=n)
{br++;
cin>>k;
p=k*k;
if(k%100<0)r=k%100;c=k/100;
if(k%1000<0)r=k%1000;c=k/1000;
if(r+c==k)   i++;}
cout<<i<<endl;
    return 0;
}
