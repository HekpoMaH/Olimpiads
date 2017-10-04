#include<iostream.h>
#include<stdlib.h>
int K; int a[10000],d,k;
void main()
{ cin>>K;
d=K;
for(int i=0;i<9;i++)
a[i]=i;
int b;int c;int z;
for( i=10;i<10000;i++)
a[i]=i/10; i++;
a[i]=i%10;
for( i=0;i<10000;i++)
if(i==K) cout<<a[i]<<endl;
}



