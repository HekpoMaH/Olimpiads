#include<iostream>
#include<string>
#include<vector>
using namespace std;

long kod(string s)
{
 long i,x,n,br=0,br2=0;
 n=s.size();
 for(i=0;i<=n-1;i++)
 {if(s[i]=='C'||s[i]=='A'||s[i]=='T') br++;
  if(s[i]=='I'||s[i]=='P'||s[i]=='G') br2++;
 }
 if(br>br2) return 0;
 if(br<br2) return 1;
 if(br==0&&br2==0) return 3;
 if(br==br2&&br!=0) return 2;
}
string s;
vector<long> a;
long i,x,n,m;
int main()
 {
 cin>>n;
 for(i=1;i<=n;i++)
 {cin>>s;
  x=kod(s);
  a.push_back(x);
 }
 for(i=0;i<=n-1;i++)
 {if(a[i]==0) cout<<"CAT"<<endl;
  if(a[i]==1) cout<<"GPI"<<endl;
  if(a[i]==2) cout<<"CAT-GPI"<<endl;
  if(a[i]==3) cout<<"UFO"<<endl;
 }
 return 0;
 }
