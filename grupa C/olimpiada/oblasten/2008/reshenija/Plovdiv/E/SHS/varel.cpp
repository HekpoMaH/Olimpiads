#include<iostream>
using namespace std;
int main()
{int n,i,v,k;
char a;
cin>>v>>k>>n;
for(i=1;i<=n;i++)
   {
  cin>>a;
  if(a=='+')
  v=v+k;
  if(a=='-')
  v=v-k;
        
    }
     cout<<v<<endl;
    
return 0;
    }
