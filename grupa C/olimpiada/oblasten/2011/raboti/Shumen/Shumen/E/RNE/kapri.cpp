#include<iostream>
using namespace std;
int main ()
{
long long int b,n[1024],br=0;
cin>>b;
cin>>n[1024];
if (((n[i]*n[i+1])+n[i+2])%10==n[i+3])br++;
cout<<br<<endl;
return 0;
}