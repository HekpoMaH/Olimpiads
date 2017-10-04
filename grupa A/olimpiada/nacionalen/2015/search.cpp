#include<bits/stdc++.h>
using namespace std;
const int nmax=1e7+9;
string s;
int bl[nmax],n;
int cmp(int p1,int p2){
   int j,t;
   if(p1>=n||p2>=n)return 0;
   if(p1>p2)t=n-p1-1;
   else t=n-p2-1;
   j=0;
   while(j<=t&&s[p1+j]==s[p2+j])j++;
   return j;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s;
   n=s.size();
   int ans=0,pos=0,l=0,r=0;
   bl[0]=0;
   for(int i=1;i<n;i++){
      bl[i]=0;
      if(i>r){
         bl[i]=cmp(0,i);
         if(bl[i]>0){
            l=i;
            r=i+bl[i]-1;
         }
      }
      else{
         int k=i-l;
         if(bl[k]<r-i+1)bl[i]=bl[k];
         else{
            bl[i]=r-i+1;
            l=i;
            int q=cmp(r-i+1,r+1);
            if(q>0){
               bl[i]+=q;
               r=i+bl[i]-1;
            }
         }
      }
      int tmp=min(bl[i],i);
      if(tmp>ans){
         ans=tmp;
         pos=i;
      }
   }
   cout<<ans<<" "<<pos+1<<"\n";
}
