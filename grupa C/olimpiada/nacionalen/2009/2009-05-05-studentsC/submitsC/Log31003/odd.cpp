/*
TASK:odd
LANG:C++
*/
#include<iostream>
using namespace std;
long long a[1000001];
bool b[10000002];
int main()
{
long long n,i,j,k=5000000,p=2000000;
cin>>n;
for(i=1;i<=n;i++)
{
 cin>>a[i];
 b[a[i]/k]=1-b[a[i]/k];                
}

for(i=0;i<=p;i++)
 if(b[i]==1)
 {
  j=i;
  break;
 }
b[j]=0;

for(i=1;i<=n;i++)
if(a[i]/k==j)
 b[ a[i]%k ]=1-b[ a[i]%k ];
long long sp;
for(i=0;i<k;i++)
 if(b[i]==1)
 {
  sp=j*k+i;
  break;
 }
cout<<sp<<endl;                            
//system("pause");
return 0;    
}
