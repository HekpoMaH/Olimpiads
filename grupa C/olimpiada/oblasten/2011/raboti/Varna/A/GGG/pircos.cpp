#include<iostream>
#include<cstring>
#include<set>
#include<cstdio>
using namespace std;
int main()
{
   multiset<int>digits;
   multiset<int>::iterator iter;
   long long n;
   long long x;
   long long i;
   scanf("%lld", &n);
   for(i=0;i<n;++i)
   {
                    scanf("%lld", &x);
                    if( digits.count(x)>=1 )
                    {
                        digits.erase(x);
                    }
                    else digits.insert(x);
                   
   }   
   long long p;
   iter=digits.begin();
   p=*iter;
   cout<<*iter<<" ";
   digits.erase(p);
   iter=digits.begin();
   cout<<*iter<<"\n"; 
    return 0;
} 
