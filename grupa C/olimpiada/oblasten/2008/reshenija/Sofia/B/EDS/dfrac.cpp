#include<iostream>
using namespace std;
int main()
{
int a,b,p=50,x; int k; int m[300000];
cin>>a>>b>>k>>p;
int l=a;
m[0]=b;
for (int i=0; i<b-1; i++)
{
m[i]=(10*l)/b;
if (m[i]!=0)
l=(10*l)%(m[i]*b);
else l*=10;
cout<<m[i];
}
for (int i=0; i<p; i++)
m[b+i]=m[i];
for (int i=(int)k%b; i<p; i++)
cout<<m[i];
cout<<endl;
system("pause");
return 0;

}
