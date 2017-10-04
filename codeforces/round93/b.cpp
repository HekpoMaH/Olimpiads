#include<bits/stdc++.h>
using namespace std;
string s;
const int nmax=1e6+9;
unsigned int hash[nmax][4];
const int base[4]={101,197,911};
unsigned int pw[nmax][4];
bool chek1(int x){
   //cout<<"trying w/ "<<x<<"\n";
   for(int i=0;i<3;i++){
      //cout<<hash[x-1][i]<<" "<<hash[s.size()-1][i]-hash[s.size()-x-1][i]*pw[x][i]<<"\n";
      if(hash[x-1][i]!=hash[s.size()-1][i]-hash[s.size()-x-1][i]*pw[x][i])
         return false;
   }
   return true;
   //[1;n-x)
}
bool chek2(int x){
   //cout<<"trying w/ "<<x<<"\n";
   for(int i=1;i<s.size()-x;i++){
      int krai=i+x-1;
      for(int j=0;j<3;j++){
         if(hash[krai][j]-hash[i-1][j]*pw[x][j]==hash[x-1][j])return true;
      }
   }
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s;
   for(int i=0;i<3;i++){
      hash[0][i]=s[0]-'a';
      //cout<<hash[0][i]<<" "<<s[0]<<"\n";
      pw[0][i]=1;
   }
   //assert(hash[0][0]==hash[0][1]&&hash[0][1]==hash[0][2]);
   //exit(0);
   for(int i=1;i<s.size();i++){
      for(int j=0;j<3;j++)hash[i][j]=hash[i-1][j]*base[j]+s[i]-'a',pw[i][j]=pw[i-1][j]*base[j];
   }
   //for(int i=0;i<s.size();i++)cout<<hash[i][0]<<" ";
   //cout<<"\n";
   vector<int> answers;
   //answers.push_back(0);
   for(int i=1;i<s.size();i++){
      if(chek1(i)){
         //cout<<i<<"\n";
         answers.push_back(i);
      }
   }
   //cout<<chek2(3)<<"\n";
   int l=-1,r=answers.size(),mid;
   while(l+1<r){
      mid=(l+r)/2;
      //cout<<l<<" "<<r<<" "<<mid<<" "<<answers[mid]<<" "<<chek2(answers[mid])<<"\n";;
      if(chek2(answers[mid])==true){
         l=mid;
      }
      else{
         r=mid;
      }
   }
   if(l!=-1){
      string ans="";
      for(int i=0;i<answers[l];i++){
         ans+=s[i];
      }
      cout<<ans<<"\n";
   }
   else cout<<"Just a legend\n";
}
