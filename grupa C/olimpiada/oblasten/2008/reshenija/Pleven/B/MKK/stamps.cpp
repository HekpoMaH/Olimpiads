#include<iostream>
#include<vector>
using namespace std;
vector<long> lol;
long s,n,used[5005];
int main()
{ cin>>s>>n;
  for(int i=1; i<=n; i++)
   { long x;
     cin>>x;
     lol.push_back(x);
   }
  sort(lol.begin(),lol.end());
  long l=lol.size()-1;
  for(int i=0; i<=l; i++)
   used[lol[i]]=1;
  for(int i=2; i<=s; i++)
   { long o0=99999999;
     for(int j=0; j<=l; j++)
      { if(i-lol[j]>0)
         { long x;
           x=used[i-lol[j]]+1;
           if(x<o0)
            o0=x;
         }
      }
     if(used[i]==0)
      used[i]=o0;
     else
      if(o0<used[i])
       used[i]=o0;  
   }  
 cout<<used[s]<<endl;
 return 0;
}
