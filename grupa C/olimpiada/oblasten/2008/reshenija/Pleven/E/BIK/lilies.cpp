#include<iostream.h>
void main()
{
int s=0, min=20, n, a, i;
cin>>n;
cout<<endl;
for(i=0; i<n; i++)
{cin>>a;
 if(a<min) min=a;
 s=s+a;
 }
 cout<<s-min+1;
}