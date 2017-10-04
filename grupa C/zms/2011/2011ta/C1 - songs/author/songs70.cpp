#include <iostream>
using namespace std;
int mas[5005][5005];
int main()
{int n,br=0;
 int a[5005];
 int b[5005];
 cin>>n;
 for(int i=1;i<=n;i++)
 cin>>a[i];
 for(int i=1;i<=n;i++)
 cin>>b[i];
 
 for(int i=1;i<n;i++)
  for(int j=i+1;j<=n;j++)
   mas[a[i]][a[j]]=1;
   
 for(int i=1;i<n;i++)
  for(int j=i+1;j<=n;j++)
   if(mas[b[i]][b[j]]!=1) 
   mas[b[i]][b[j]]=2;
  
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
    if(mas[i][j]==2) br++;
    cout<<br<<endl;
}
