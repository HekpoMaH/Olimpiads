#include<iostream>
using namespace std;
int main()
{int n,m,i;
char f[1600],c[100];
cin>>n;
cin>>m;
for(i=0;i<m;i++){cin>>f[i];}
for(i=0;i<m;i++){
                if(f[i]=='.'){c[i]=i;}
}
cout<<c[6];
return 0;
}
