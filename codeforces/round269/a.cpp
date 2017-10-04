#include<bits/stdc++.h>
using namespace std;
int sticks[9];
int used[20];
int main(){
   for(int i=1;i<=6;i++)cin>>sticks[i],used[sticks[i]]++;
   int has4,has2;
   has4=has2=0;
   for(int i=1;i<=19;i++){
      if(used[i]>=4)has4=1;
      if(used[i]==2||used[i]==6)has2=1;
   }
   if(has4==0){
      cout<<"Alien\n";
   }
   if(has4==1){
      if(has2==0){
         cout<<"Bear\n";
      }
      else cout<<"Elephant\n";
   }
}
