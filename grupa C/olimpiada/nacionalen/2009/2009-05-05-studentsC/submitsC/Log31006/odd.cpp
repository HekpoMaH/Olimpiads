/*
TASK:odd
LANG: C++
*/
#include<iostream>
#include<string>
using namespace std;
long long br1,y,n,j,m,i,x,br;
string d,s[1000001];
char c;
int main()
 {
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {cin>>d;
  m=d.size();
  if(m<10)
  {x=0;y=1;
   for(j=m-1;j>=0;j--)
   {x=x+(d[j]-'0')*y;y*=10;}
  br1=br1^x;
  }
  else {s[br]=d;
  for(j=0;j<br;j++)
  if(s[br]==s[j]) {s[br]='0'+s[br];s[j]='0'+s[j];}
  br++;
  }
 }
 br=-1;
 if(br1!=0) printf("%d\n",br1);
 else do
 {br++;
  if(s[br][0]!='0') {cout<<s[br]<<endl;break;}
 } while(s[br][0]=='0');
 //system("PAUSE");
 return 0;
 }
