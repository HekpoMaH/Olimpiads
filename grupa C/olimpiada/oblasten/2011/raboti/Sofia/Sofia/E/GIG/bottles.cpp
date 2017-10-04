//BOTTLES.CPP
#include<iostream>
using namespace std;
int main ()
{
int ml,nl,but;
cin>>ml>>nl; 0<ml,nl<50;
but=ml,nl;
ml<!nl;
if (ml+nl%2>=0) cout<<but<<endl;
else ml+nl-1;
cout<<but<<endl;
return 0;
}
