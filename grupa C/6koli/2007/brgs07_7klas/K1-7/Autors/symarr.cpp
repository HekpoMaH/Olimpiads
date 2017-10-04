#include<iostream>
using namespace std;
int main()
{
int n,a[20][20],i,j,p,q,sum=0, key=0, l=0;
cin>>n;
for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>a[i][j];
for(i=1;i<=n-1;i++){
 p=n;
 q=n-i+1;
 for(j=1;j<=n-i;j++){
  if (a[i][j]!=a[p][q]) key=1;   
  p--;               
 }                    
}
if(key==0) {
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)
     if ((a[i][j]%3==0)&&(a[i][j]!=0)) {if (l==0){cout <<a[i][j];l++;}
                       else cout <<" "<<a[i][j];}
  cout<<endl; 
 }
else {for(i=1;i<=n;i+=2)for(j=1;j<=n;j++) sum+=a[i][j];                   
cout<<sum<<endl;
 }
}
