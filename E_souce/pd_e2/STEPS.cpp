#include<iostream>
using namespace std;
int main()
{int n,h,l,i;
char s;
cin>>n>>h>>l;
cin>>s;
cout<<s;for(i=1;i<=l;i++)cout<<s<<"\n";
cout<<s;for(i=1;i<=l-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=l-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=(2*l)-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=(2*l)-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=(3*l)-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=(3*l)-2;i++)cout<<' ';cout<<s<<"\n";
cout<<s;for(i=1;i<=(4*l)-2;i++)cout<<' ';cout<<s<<"\n";
for(i=1;i<=4*l;i++)cout<<s<<"\n";
return 0;
}
