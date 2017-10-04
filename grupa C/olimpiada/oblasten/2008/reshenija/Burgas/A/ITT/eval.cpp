#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
char a[128];
int skoba=0;
vector<int> pls[128];

unsigned long long fact(int k)
{
         unsigned long long s=1;
         for(;k>1;k--)
                      s*=k;
                      
         return s;
}
unsigned long long ans[128];
int main()
{
 cin>>a;

 for(int i=0;i<strlen(a);i++)
 {
     //    cout<<i<<endl;
         if(a[i]=='(') { skoba++;pls[skoba].push_back(0);}
         else if(a[i]==')') 
         {
              for(int k=0;k<pls[skoba].size();k++)
                      ans[skoba]+=fact(pls[skoba][k]);
              skoba--;
              
         }
         else if(a[i]=='+')
              pls[skoba][pls[skoba].size()-1]++;
              
         else if(a[i]=='*')
              pls[skoba].push_back(0);
         
 }
unsigned long long sol=1;
for(int i=0;i<30;i++)
 if(ans[i]!=0)
              sol*=ans[i];
              
 cout<<sol<<endl;
    
}
