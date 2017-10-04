#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string home,away;
   cin>>home>>away;
   int n;
   cin>>n;
   char h,a;
   int t,m;
   char ch,c;
   map<int,int> cnt_home,cnt_away;
   for(int i=0;i<n;i++){
      cin>>t>>c>>m>>ch;
      if(c=='h'&&cnt_home.count(m)&&cnt_home[m]>=2)continue;
      if(c=='a'&&cnt_away.count(m)&&cnt_away[m]>=2)continue;
      if(ch=='r'){
         cout<<(c=='h' ? home : away)<<" "<<m<<" "<<t<<"\n";
         if(c=='h')
            cnt_home[m]=2;
         else
            cnt_away[m]=2;
      }
      else if(ch=='y'){
         if(c=='h'){
            cnt_home[m]++;
            if(cnt_home[m]==2){
               cout<<(c=='h' ? home : away)<<" "<<m<<" "<<t<<"\n";
            }
         }
         else{
            cnt_away[m]++;
            if(cnt_away[m]==2){
               cout<<(c=='h' ? home : away)<<" "<<m<<" "<<t<<"\n";
            }
         }
      }
   }
}
