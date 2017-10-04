#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int inf=1e9;
vector<int> nar;
vector<int> nam;
int a[nmax];
int main(){
   int n;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   a[0]=0;
   a[n+1]=inf;
   int la,lb,lap,lbp,lat,lbt,lapt,lbpt;
   la=0;lb=1;
   lap=n+1;lbp=1;
   for(int i=2;i<=n;i++){
      if(a[lb]>a[i]){
         lat=la;
         lbt=i;
      }
      else if(a[lap]>a[i]){
         lat=lbp;
         lbt=i;
      }
      else if(a[lbp]<a[i]){
         lat=i;
         lbt=lap;
      }
      else{
         cout<<"Impossible\n";
         exit(0);
      }
      if(a[lbp]<a[i]){
         lapt=lap;
         lbpt=i;
      }
      else if(a[la]<a[i]){
         lapt=lb;
         lbpt=i;
      }
      else if(a[lbp]>a[i]){
         lapt=i;
         lbpt=la;
      }
      else{
         cout<<"Impossible\n";
         exit(0);
      }
      if(lat!=la){
         nar.push_back(lat);
      }
      if(lapt!=lap){
         nam.push_back(lapt);
      }
      la=lat;
      lb=lbt;
      lap=lapt;
      lbp=lbpt;
      //cerr<<"i="<<i
      //   <<"\n la="<<la<<" "<<"lb="<<lb
      //   <<"\n la'="<<lap<<" lb'="<<lbp<<"\n";
   }
   //cout<<nam.size()<<"\n";
   //for(int i=0;i<nam.size();i++){
   //   cout<<nam[i]<<" ";
   //}
   //cout<<"\n";
   if(nar.size()==0){
      nar.push_back(1);
   }
   int used[nmax];
   memset(used,0,sizeof(used));
   for(int i=0;i<nar.size();i++){
      used[nar[i]]=1;
   }
   vector<int> r2;
   r2.clear();
   for(int i=1;i<=n;i++){
      if(used[i]==0)r2.push_back(i);
   }
   bool fl=false;
   for(int i=0;i<r2.size()-1;i++){
      if(a[r2[i]]<=a[r2[i+1]])fl=true;
   }
   if(fl==true){
      memset(used,0,sizeof(used));
      for(int i=0;i<nam.size();i++){
         used[nam[i]]=1;
      }
      nar.clear();
      for(int i=1;i<=n;i++){
         if(used[i]==0)nar.push_back(i);
      }
   }
   if(nar.size()<n){
      cout<<nar.size()<<"\n";
      for(int i=0;i<nar.size();i++){
         cout<<nar[i]<<" ";
      }
      cout<<"\n";
   }
   else{
      nar.pop_back();
      cout<<nar.size()<<"\n";
      for(int i=0;i<nar.size();i++){
         cout<<nar[i]<<" ";
      }
      cout<<"\n";
   }
}
//6 1 3 2 5 2
