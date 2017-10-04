#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s[1000][30];
int n,m;
void read()
{
     cin>>m>>n;
     int i,j;
     for(i=0;i<m;i++)
     {
          for(j=0;j<n;j++)
          {
               cin>>s[j][i];
          }
     }
}
int main()
{
     read();
     int i,j,max=0,l=2,br=1,k;
     sort(s[0],s[0]+n);
     for(i=0;i<m;i++)
     {
          for(j=i+1;j<m;j++)
          {
               sort(s[j],s[j]+n);
               for(k=0;k<n;k++)
               {
                    if(s[i][k]==s[j][k]) l=1;
                    else {l=0;break;}
               }
               if(l==1) br++;
          }
          if(br>max) max=br;
     }
     cout<<max<<endl;
return 0;
}
