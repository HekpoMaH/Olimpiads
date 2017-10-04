#include<bits/stdc++.h>
using namespace std;
set<int> marks;
int n,l,x,y;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>l>>x>>y;
   for(int i=1;i<=n;i++){
      int xx;
      cin>>xx;
      marks.insert(xx);
   }
   vector<int> ans;
   ans.clear();
   if(x<y)swap(x,y);
   if(marks.find(x)==marks.end()){
      int fl=0;
      for(set<int>::iterator it=marks.begin();it!=marks.end();it++){
         //*it-sth=x
         //sth=*it-x
         int sth=*it-x;
         if(*it>x&&marks.find(sth)!=marks.end()){
            fl=1;
            break;
         }
         //sth-*it=x
         //sth=*it+x
         sth=*it+x;
         if(marks.find(sth)!=marks.end()){
            fl=1;
            break;
         }
      }
      if(fl==0){
         for(set<int>::iterator it=marks.begin();it!=marks.end();it++){
            //*it-sth=x
            //sth=*it-x
            //if sth is goind to be added then y should be posible
            //sth-what=y
            //what-sth=y
            int sth;
               sth=*it-x;
            //cout<<"sth1="<<sth<<"\n";
            if(*it>x){
               int what=sth-y;
               //cout<<"what11="<<what<<" "<<(marks.find(what)!=marks.end())<<"\n";
               if(what>=0){
                  if(marks.find(what)!=marks.end()){
                     ans.push_back(sth);
                     marks.insert(sth);
                     fl=1;
                     break;
                  }
               }
               what=y+sth;
               //cout<<"what12="<<what<<" "<<(marks.find(what)!=marks.end())<<"\n";
               if(marks.find(what)!=marks.end()){
                     ans.push_back(sth);
                     marks.insert(sth);
                     fl=1;
                     break;
               } 
            }
            //sth-*it=x
            //sth=*it+x
            sth=*it+x;
               //cout<<"sth2="<<sth<<"\n";
               
               int what=sth-y;
               //cout<<"what21="<<what<<" "<<(marks.find(what)!=marks.end())<<"\n";
               if(what>=0){
                  if(sth<=l&&marks.find(what)!=marks.end()){
                     ans.push_back(sth);
                     marks.insert(sth);
                     fl=1;
                     break;
                  }
               }
               what=y+sth;
               //cout<<"what22="<<what<<" "<<(marks.find(what)!=marks.end())<<"\n";
               if(sth<=l&&marks.find(what)!=marks.end()){
                     ans.push_back(sth);
                     marks.insert(sth);
                     fl=1;
                     break;
               } 
            }
         if(fl==0)marks.insert(x),ans.push_back(x);
      }
   }
   if(marks.find(y)==marks.end()){

      int fl=0;
      for(set<int>::iterator it=marks.begin();it!=marks.end();it++){
         //*it-sth=x
         //sth=*it-x
         int sth=*it-y;
         if(*it>y&&marks.find(sth)!=marks.end()){
            fl=1;
            break;
         }
         //sth-*it=x
         //sth=*it+x
         sth=*it+y;
         if(sth<=l&&marks.find(sth)!=marks.end()){
            fl=1;
            break;
         }
      }
      if(fl==0){
         ans.push_back(y);
         marks.insert(y);
      }
   }
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
