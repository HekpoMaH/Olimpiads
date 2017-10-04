#include<bits/stdc++.h>
using namespace std;
const int nmax=2009;
int a[nmax];
int n;
vector<int> v[nmax];
void read(){
   cin>>n;
   long long pr=1;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      v[a[i]].push_back(i);
   }
   for(int i=1;i<=2000;i++){
      if(v[i].size()!=0)pr*=v[i].size();
      if(pr>=3)return;
   }
   if(pr<=2){
      cout<<"NO\n";
      exit(0);
   }
}
int main(){
   read();
   cout<<"YES\n";
   int swapped=0;
   for(int i=1;i<=2000;i++){
      for(int j=0;j<v[i].size();j++){
         cout<<v[i][j]<<" ";
      }
      if(v[i].size()>=2&&swapped==0){
         swap(v[i][0],v[i][1]);
         swapped=i;
      }
   }
   cout<<"\n";
   int sw2=0;
   for(int i=1;i<=2000;i++){
      for(int j=0;j<v[i].size();j++){
         cout<<v[i][j]<<" ";
      }
      if(v[i].size()>=2&&sw2==0&&swapped!=i){
         swap(v[i][0],v[i][1]);
         sw2=i;
      }
   }
   cout<<"\n";
   if(sw2==0){
      for(int i=1;i<=2000;i++){
         if(v[i].size()>=3&&sw2==0){
            swap(v[i][2],v[i][1]);
            sw2=i;
         }
         for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
         }
      }
      cout<<"\n";
      return 0;
   }
   for(int i=1;i<=2000;i++){
      for(int j=0;j<v[i].size();j++){
         cout<<v[i][j]<<" ";
      }
   }
   cout<<"\n";

}
