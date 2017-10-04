#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int dx[5]={0,0,1,-1};
const int dy[5]={1,-1,0,0};
int main(){
   int n;
   string s[nmax];
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         int br=0;
         for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(!(ni>=0&&ni<n&&nj>=0&&nj<n))continue;
            if(s[ni][nj]=='o')br++;
         }
         if(br%2!=0){
            cout<<"NO\n";
            return 0;
         }
      }
   }
   cout<<"YES\n";
}
