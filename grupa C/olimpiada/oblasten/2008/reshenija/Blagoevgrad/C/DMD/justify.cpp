#include <iostream>

using namespace std;
int n,br,b[62],c[62],d[62],e[62],r[62][2],q[62][62],br1,br2,k,asd;
char a[10000][62];
int main()
{cin>>n;
 n=n+1;
 for(int i=0;i<n;i++)
 r[i][0]=1000;
 for(int i=0;i<n;i++)
 cin.getline(a[i],60);
 for(int i=0;i<n;i++)
 {
         int m=strlen(a[i]);
         b[br]=m;
         br++;
 }
 for(int i=0;i<br-1;i++)
 c[i]=60-b[i];
 for(int i=0;i<n;i++)
 {
         int f=strlen(a[i]);
         for(int j=0;j<f;j++)
         if(a[i][j]==' ') c[i]=c[i]+1;
 }                                                          //c i d e ot i=1 do i<br-1
 for(int i=0;i<n;i++)
 {
         int m=strlen(a[i]);
         for(int j=1;j<m;j++)
         if(a[i][j]==' '&&a[i][j-1]!=' ') d[i]=d[i]+1;
 }
 for(int i=1;i<br-1;i++)
 {
                            r[i][0]=c[i]%d[i];
                            r[i][1]=c[i]/d[i];
 }
 for(int i=1;i<br-1;i++)
 {
         for(int j=0;j<d[i];j++)
         {
                 q[i][j]=r[i][1];
         }
 }
 for(int i=1;i<br-1;i++)
 {
         if(r[i][0]!=0) br2=r[i][0];
         br1=0;
         if(br2!=0)
         {do
         {
                        q[i][br1]++;
                        br2--;
                        if(br1<d[i]) br1++;
                        else br1=0;
         }
         while(br2>0);}
 }              
 for(int i=0;i<n-1;i++)
 {
         int m=strlen(a[i]);
         k=0;
         for(int j=0;j<m;j++)
         {
                 if(a[i][j]==' '&&a[i][j-1]!=' '&&j!=0) 
                 {
                               for(int h=0;h<q[i][k];h++)
                               cout<<" ";
                               k++;
                 }
                 else if(a[i][j]!=' ') cout<<a[i][j];
         }
         cout<<"\n";
 }
 int o=strlen(a[n-1]);
 for(int j=0;j<o;j++)
 {if(a[n-1][j]==' '&&a[n-1][j-1]!=' '&&j!=0) cout<<a[n-1][j];
  if(a[n-1][j]!=' ') cout<<a[n-1][j];}
 cout<<"\n";
 
   
    return 0;
}
