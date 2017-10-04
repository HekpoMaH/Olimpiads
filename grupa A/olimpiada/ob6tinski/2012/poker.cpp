//Poker Face
#include<bits/stdc++.h>
using namespace std;
int u[19];
int u2[19];
int main(){
   int a[9];
   for(int i=1;i<=5;i++){
      cin>>a[i];
      u[a[i]]++;
   }
   sort(a+1,a+6);
   int fl=1;
   for(int i=1;i<5;i++){
      if(a[i]+1!=a[i+1])fl=0;
   }
   if(fl==1){
      cout<<"Straight";
      exit(0);
   }
   for(int i=1;i<=13;i++){
      u2[u[i]]++;
   }
   if(u2[5]==1)cout<<"Impossible";
   else if(u2[4]==1)cout<<"Four of a Kind";
   else if(u2[3]==1&&u2[2]==1)cout<<"Full House";
   else if(u2[3]==1)cout<<"Three of a Kind";
   else if(u2[2]==2)cout<<"Two Pairs";
   else if(u2[2]==1)cout<<"One Pair";
   else cout<<"Nothing";
}
