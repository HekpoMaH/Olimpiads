#include<iostream>
using namespace std;
long s[5010],a[3010];
long s1,br,br1,n,en,br2;
int main()
{
 cin>>s1>>n;
 for(br=1; br<=n; br++) {cin>>a[br]; s[a[br]]=1;}
 for(br=1; br<=n; br++)
 {
    en=s1-a[br];
    for(br1=1; br1<=en; br1++)
     if(s[br1]!=0)
     if(s[br1+a[br]]>s[br1] || s[br1+s[br]]==0) s[br1+a[br]]=s[br1]+1;
 }
 cout<<s[s1]<<endl;
// system("Pause");
 return 0;   
}
