#include<iostream>
using namespace std;
int main()
{
long long v,k,n,br;
char znak;
cin>>v;
cin>>k;
cin>>n;
br=0;
do
{   
	
	cin.get(znak);
	br++;
	if(znak=='+')
	v=v+k;
	else
	v=v-k;
}
while(br<=n);
cout<<v<<endl;
    return 0;
}
