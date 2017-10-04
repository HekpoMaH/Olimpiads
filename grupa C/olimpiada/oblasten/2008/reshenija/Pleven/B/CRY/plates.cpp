#include<iostream>
#include<math.h>
using namespace std;
long n,m,a[101],b[101],i=1,j,k,br,h,br1,h1,k1;
int main()
{
    cin>>m>>n;
    for(i=1;i<=m*2;i++)
    
   { cin>>a[i]; }
   j=i;
i=0;
do
{   j--;
    i++;
 if(a[i]%10==1)
 { b[i]++; a[i]/=10; }
 if(a[i]%10==0 && a[i]!=1)
 { a[i]/=10; }
 if(a[i]==1)
 { b[i]++; a[i]--; }
} while(j!=0);
for(i=1;i<=m*2-1;i++)
{
 if(b[i]==b[i+1])
 { br++; b[i]=-2; b[i+1]=-3; }
}
cout<<br<<endl;

return 0;
}
