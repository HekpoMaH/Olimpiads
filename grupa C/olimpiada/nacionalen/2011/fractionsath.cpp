#include<iostream>
using namespace std;
int main()
{
int z,m,n;
cin >> z >> m >> n;
int i=1, j=1;
for(int p=2;p<=z;p++)
{ int k=m*p/n+1;
if(k*j<p*i) {i=k; j=p;}
}
cout << i << " " << j << endl;
}