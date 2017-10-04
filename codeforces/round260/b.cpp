#include<bits/stdc++.h>
using namespace std;
int a[4]={2,4,3,1};
int b[4]={3,4,2,1};
int c[2]={4,1};
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin>>s;
   int num=0;
   for(int i=max((int)s.size()-2,0);i<s.size();i++)num=num*10+s[i]-'0';
   if(num!=0)cout<<(1+a[(num+3)%4]+b[(num+3)%4]+c[(num+3)%2])%5<<"\n";
   if(num==0)cout<<4<<"\n";
}
