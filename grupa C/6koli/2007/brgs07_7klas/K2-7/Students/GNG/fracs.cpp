#include <iostream>

using namespace std;

int main()
{
 int n;
 cin>>n;
 int a[n][2];
 for(int i=0;i<n;i++)
 {cin>>a[i][0]>>a[i][1];
 }
 for(int i=0;i<n;i++)
 {
         for(int j=min(a[i][0],a[1][1]);j>=2;j--)
         {
                 if(a[i][0]%j==0&&a[i][1]%j==0){a[i][0]/=j;a[i][1]/=j;j++;}
         }
         
 } 
 int p=1;
 for(int i=0;i<n;i++)
 {
         p=p*a[i][1];
 }
 
 int b[n][2];
 for(int i=0;i<n;i++)
 {
     b[i][0]=a[i][0]*(p/a[i][1]);
     b[i][1]=a[i][1]*(p/a[i][1]);
 }
 int ok,t[2],t1[2];
 do
 {
     ok=1;
     for(int i=0;i<n-1;i++)
     {
             if(b[i][0]<b[i+1][0]){t[0]=b[i][0];t[1]=b[i][1];b[i][0]=b[i+1][0];b[i][1]=b[i+1][1];b[i+1][0]=t[0];b[i+1][1]=t[1];    t1[0]=a[i][0];t1[1]=a[i][1];a[i][0]=a[i+1][0];a[i][1]=a[i+1][1];a[i+1][0]=t1[0];a[i+1][1]=t1[1];ok=0;}
             
     }
 }
 while(!ok);
 cout<<n<<"\n";
 for(int i=n-1;i>=0;i--)
 cout<<a[i][0]<<" "<<a[i][1]<<"\n";
     
         



 return 0;
}
