#include<iostream>
#include<stdio.h>
using namespace std;
string x;
long i,j,m,n,s;
pair<long,long> br[1002];

int main()
{
    cin>>m>>n;
    long m1=m;
    for(i=1;i<=m;i++)
    { br[i].second=i;
      for(j=1;j<=n;j++)
         { cin>>x;         
            for(s=0;s<n;s++)
            { if(x[s]=='1') { br[i].first++;   }
            }
         }
    }
    sort(br,br+m+1);
    for(i=1;i<n;i++) 
     for(j=i+1;j<=n;j++)  
        if(br[i].first==br[j].first) m1--;         
     
     cout<<m1<<endl;
  //  system("pause");
    return 0;
    }
