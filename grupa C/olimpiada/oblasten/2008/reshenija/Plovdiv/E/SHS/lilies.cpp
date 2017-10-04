#include<iostream>
using namespace std;
int main()
{int s=0,n,a,i,min=20;
cin>>n;
for(i=1;i<=n;i++)
   {
  cin>>a;
  s=s+a;
  if(min>a)min=a;
        
    }
     cout<<(s-min)+1<<endl;
     system("pause");
return 0;
    }
