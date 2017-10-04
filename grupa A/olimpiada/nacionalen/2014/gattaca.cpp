#include<bits/stdc++.h>
using namespace std;
int n,m,kk;
const int nmax=1e5+9;
string s1,s2;
unsigned base[4]={0,131,137,139};
unsigned basep[4][nmax];
void read(){
   cin>>n>>m>>kk;
   cin>>s1>>s2;
}
void init(){
   for(int i=1;i<=3;i++)basep[i][0]=1;
   for(int k=1;k<=3;k++){
      for(int i=1;i<nmax;i++){
         basep[k][i]=basep[k][i-1]*base[k];
      }
   }
}
bool chek(int sz){
   unsigned hashes[4][nmax];
   unsigned hashes2[4][nmax];
   int uk=0;
   int uk2=0;
   unsigned roling;
   for(int k=1;k<=1;k++){
      uk=0;
      roling=0;
      for(int i=0;i<sz;i++){
         roling=roling*base[k]+s1[i]-'A';
      }
      for(int i=sz;i<n;i++){
         hashes[k][++uk]=roling;
         roling=roling-basep[k][sz-1]*(s1[i-sz]-'A');
         roling=roling*base[k]+s1[i]-'A';
         
      }
      hashes[k][++uk]=roling;
   }
   //for(int i=1;i<=uk;i++){
   //   cout<<hashes[1][i]<<" ";
   //}
   //cout<<"\n";
   for(int k=1;k<=1;k++){
      uk2=0;
      roling=0;
      for(int i=0;i<sz;i++){
         roling=roling*base[k]+s2[i]-'A';
      }
      for(int i=sz;i<m;i++){
         hashes2[k][++uk2]=roling;
         roling=roling-basep[k][sz-1]*(s2[i-sz]-'A');
         roling=roling*base[k]+s2[i]-'A';
         
      }
      hashes2[k][++uk2]=roling;
      sort(hashes2[k]+1,hashes2[k]+uk2+1);
   }
   //for(int i=1;i<=uk2;i++){
   //   cout<<hashes2[1][i]<<" ";
   //}
   //cout<<"\n";
   for(int i=1;i<=uk;i++){
      //cout<<hashes[1][i]<<"-> ";
      if(upper_bound(hashes2[1]+1,hashes2[1]+uk2+1,hashes[1][i])-lower_bound(hashes2[1]+1,hashes2[1]+uk2+1,hashes[1][i])>=kk){
         return true;
      }
   }
   return false;
}
string exactans(int sz){
   unsigned hashes2[4][nmax];
   int uk2;
   string ans="";
   unsigned roling;
   for(int k=1;k<=1;k++){
      uk2=0;
      roling=0;
      for(int i=0;i<sz;i++){
         roling=roling*base[k]+s2[i]-'A';
      }
      for(int i=sz;i<m;i++){
         hashes2[k][++uk2]=roling;
         roling=roling-basep[k][sz-1]*(s2[i-sz]-'A');
         roling=roling*base[k]+s2[i]-'A';
         
      }
      hashes2[k][++uk2]=roling;
      sort(hashes2[k]+1,hashes2[k]+uk2+1);
   }

   int k=1;
   roling=0;
   string x;
   for(int i=0;i<sz;i++){
      roling=roling*base[k]+s1[i]-'A';
   }
   for(int i=sz;i<n;i++){
      if(upper_bound(hashes2[1]+1,hashes2[1]+uk2+1,roling)-lower_bound(hashes2[1]+1,hashes2[1]+uk2+1,roling)>=kk){
         x="";
         for(int j=i-sz;j<i;j++){
            x+=s1[j];
         }
         if(ans==""){
            ans=x;
         }
         else if(x<ans)ans=x;
      }
      roling=roling-basep[k][sz-1]*(s1[i-sz]-'A');
      roling=roling*base[k]+s1[i]-'A';
      
   }

   if(upper_bound(hashes2[1]+1,hashes2[1]+uk2+1,roling)-lower_bound(hashes2[1]+1,hashes2[1]+uk2+1,roling)>=kk){
      x="";
      for(int j=n-sz;j<n;j++){
         x+=s1[j];
      }
      if(ans==""){
         ans=x;
      }
      else if(x<ans)ans=x;
   }
   return ans;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   init();
   int left=1,right=min(m,n)+1,mid;
   while(left+1<right){
      mid=(left+right)/2;
      if(chek(mid)){
         left=mid;
      }
      else{
         right=mid;
      }
   }
   cout<<exactans(left)<<"\n";
   //cout<<left<<"\n";
}
