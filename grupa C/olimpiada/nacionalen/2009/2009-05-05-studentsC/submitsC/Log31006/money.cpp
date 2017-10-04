/*
TASK: money
LANG: C++
*/
#include<iostream>
#include<vector>
using namespace std;
long br1=2,j,n,i,x,br=1;
vector<long> a;
int main()
 {
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {scanf("%d",&x);
  a.push_back(x);
 }
 sort(a.begin(),a.end());
 for(i=2;i<n;i++)
 if(a[j]+a[j+1]>a[i]) br1=i-j+1;
 else {br=max(br1,br);j=i-1;}
 br=max(br1,br);
 if(br<3) printf("%d\n",1);
 else printf("%d\n",br);
 //system("PAUSE");
 return 0;
 }
