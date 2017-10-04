#include<iostream>
using namespace std;
int main()
{
    int a[1000],b[1000],br=0;
    int n,m;
cin>>n>>m;
for(int i=0;i<2*n;i++)
cin>>a[i];    
for(int j=0;j<2*n;j++)
if(j%2==0){b[br]=a[j];br++;}

int br1=0;int maxbr=0;int x=0;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{if(b[i]==b[j])br1++;
if(br1>maxbr){maxbr=br1;x=b[i];}}}
cout<<x<<"\n";
    
        
    
    system("pause");
    return 0;}
    
