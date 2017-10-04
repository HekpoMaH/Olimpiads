#include<iostream>
using namespace std;
int main ()
{
int N,H,L,x,y;
char S='+';
cin>>N>>H>>L;
cin.get(S);
x=(N*H)-H;
y=(H*L)-H;
cout<<S<<"\n";
system("pause");
return 0;
}
