#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_func(string s){
   int sz=s.size();
   vector<int> p(sz+1);
   p[0]=0;
   p[1]=0;
   int l,r;
   l=0;
   r=2;
   while(r<=sz){
      if(s[l]==s[r-1]){
         l++;
         p[r]=l;
         r++;
      }
      else{
         if(l==0)p[r++]=0;
         else l=p[l];
      }
   }
   return p;
}
int main(){
   string s;
   cin>>s;
   vector<int> p;
   p=prefix_func(s);
   sz=p.size();
}
