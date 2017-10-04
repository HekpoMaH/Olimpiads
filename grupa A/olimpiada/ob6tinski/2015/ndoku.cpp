#include<bits/stdc++.h>
using namespace std;
char starter[9][9];
char ans[9][9][9][9];
int n;
int main(){
   cin>>n;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>starter[i][j];
      }
   }
   for(int srow=0;srow<n;srow++){
      for(int scol=0;scol<n;scol++){
         for(int i=srow;i<n+srow;i++){
            for(int j=scol;j<n+scol;j++){
               ans[srow][scol][i%n][j%n]=starter[i%n][j%n];
            }
         }
      }
   }
   for(int scol=0;scol<n;scol++){
      for(int srow=0;srow<n;srow++){
         for(int i=srow;i<n+srow;i++){
            for(int j=scol;j<n+scol;j++){
               cout<<ans[srow][scol][i%n][j%n];
            }
         }
         cout<<"\n";
      }
   }
}
