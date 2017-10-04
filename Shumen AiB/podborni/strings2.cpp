#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_func(string s){
   int sz=s.size();
   vector<int> p;
   p.resize(sz+1);
   p[0]=0;
   p[1]=0;
   int l,r,lng,f=0;
   l=0;
   r=2;
   while(r<=sz){
      if(s[l]==s[r-1]){
         l++;
         if(l*2==r){
            f=1;
            lng=l;
            cout<<r<<" "<<r/lng<<"\n";
            p[r]=l;
            r++;
            continue;
         }
         if(lng!=0&&r%lng==0){
            f=1;
            cout<<r<<" "<<r/lng<<"\n";
         }
         p[r]=l;
         r++;
      }
      else{
         lng=0;
         if(l==0)p[r++]=0;
         else l=p[l];
      }
   }
   if(f==0)cout<<"No Solution\n";
   return p;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string s;
   int n;
   cin>>n;
   cin>>s;
   n=s.size();
   vector<int> p=prefix_func(s);
}
