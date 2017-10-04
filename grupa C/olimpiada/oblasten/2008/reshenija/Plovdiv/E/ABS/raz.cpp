#include<iostream>
using namespace std;
int main()
{unsigned long long i,a,b,n,min=1000000;
cin>>n;
for(i=1;i<=n;i++)
{
    if(n%i==0)
    {
        if(min>((n/i)-i))
        {
            min=((n/i)-i);
            a=i;
            b=n/i;
            }
    }
}
cout<<a<<" "<<b;
return 0;
}
