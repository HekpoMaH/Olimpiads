#include <iostream>
using namespace std;
int main()
{ long long m,n,k,t,v,s;
cin>>n>>m>>k;
t=60*n+m;
v=16*t;
s=k*1024;
if (v<=s) cout<<"YES\n";
else cout<<"NO\n"<<v-s<<endl;
//system("pause");
return 0;
}

