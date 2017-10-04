#include<iostream>
using namespace std;
long n,a[5015][8],b[512][512],c[512][512];
int main()
{ cin>>n;
  long br=0;
  for(int i=1; i<=n; i++)
   { cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
     for(int j=a[i][1]+1; j<=a[i][3]; j++)
      { if(b[a[i][2]][j]==0)
         { br++;
           b[a[i][2]][j]=1;
         }
        if(b[a[i][4]][j]==0)
         { br++;
           b[a[i][4]][j]=1;
         }
      }
     for(int j=a[i][2]+1; j<=a[i][4]; j++)
      { if(c[j][a[i][1]]==0)
         { br++;
           c[j][a[i][1]]=1;
         }
        if(c[j][a[i][3]]==0)
         { br++;
           c[j][a[i][3]]=1;
         } 
      }
   }
cout<<br<<endl;
return 0;
}   
