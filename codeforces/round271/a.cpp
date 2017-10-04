#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
#define mp make_pair
string s1="qwertyuiop";
string s2="asdfghjkl;";
string s3="zxcvbnm,./";
map<char,char> l,r;
char pos;
string s;
int main(){
   for(int i=0;i<s1.size();i++){
      if(i>0)l[s1[i]]=s1[i-1];
      if(i<s1.size()-1)r[s1[i]]=s1[i+1];
   }
   for(int i=0;i<s2.size();i++){
      if(i>0)l[s2[i]]=s2[i-1];
      if(i<s2.size()-1)r[s2[i]]=s2[i+1];
   }
   for(int i=0;i<s3.size();i++){
      if(i>0)l[s3[i]]=s3[i-1];
      if(i<s3.size()-1)r[s3[i]]=s3[i+1];
   }
   cin>>pos;
   cin>>s;
   for(int i=0;i<s.size();i++){
      if(pos=='L')cout<<r[s[i]];
      else cout<<l[s[i]];
   }
   cout<<"\n";
}
