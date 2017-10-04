#include<iostream>
using namespace std;
long long a[100000],s,n,i,k,os,br;
long long feeeeeeeeeeeeeeeeeeeeeee(long long s)
{long long q ;
for(q=n;q>=1;q--)
{if(a[q]<=s){return a[q];}
                 }
 }
int main()
{
   cin>>s>>n;
   for(i=1;i<=n;i++)
   cin>>a[i];
   
   sort(a+1,a+1+n);
   while(s!=0)
   { k=feeeeeeeeeeeeeeeeeeeeeee(s);
     os=s%k;
     br+=(s-os)/k;
     s=os;           }
     cout<<br<<endl;
  
    return 0;
}
