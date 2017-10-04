#include<iostream>
using namespace std;
int main(){
int N,i,j,min1=401,min2=401;
cin>>N;
int a[N],b[N];
for(i=0;i<N;i++)cin>>a[i];
for(j=0;j<N;j++)cin>>b[j];
j=N-1;
for(i=0;i<N;i++,j--)if((a[i]+b[j])<min1)min1=a[i]+b[j];
for(i=0;i<N;i++)if((a[i]+b[i])<min1)min2=a[i]+b[i];
if(min1>min2)cout<<min1<<endl;
else if(min2>min1)cout<<min2<<endl;
return 0;
}
