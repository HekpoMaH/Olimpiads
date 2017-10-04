#include<iostream>
using namespace std;
int main()
{long long N,a,b,c,d,e,f;
cin>>N;
for(a=0;a<N;a++)
for(b=a+1;b<=N;b++)
if(N==a*b){c=a;d=b;}
if(c>d)cout<<d<<" "<<c<<endl;
else cout<<c<<" "<<d<<endl;
}

