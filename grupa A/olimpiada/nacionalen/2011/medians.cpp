#include<bits/stdc++.h>
using namespace std;
const int eps=1e-9;
multiset <double> s;
int n;
multiset <double> :: iterator it;
int cmp(double a,double b){
   if(fabs(a-b)<eps)return 0;
   if(a-b<eps)return -1;
   return 1;
}
void print(){
   if(((int)s.size())%2==1){
      cout<<setiosflags(ios::fixed)<<setprecision(3)<<*it<<"\n";
      return;
   }
   multiset<double>::iterator it2;
   it2=it;
   it2++;
   cout<<setiosflags(ios::fixed)<<setprecision(3)<<(*it+*it2)/2.0<<"\n";
}
void insert(double a){
   if(s.empty()){
      s.insert(a);
      it=s.begin();
      return;
   }
   s.insert(a);
   if(cmp(a,(*it))<0){
      if((int)s.size()%2==0){
         it--;
      }
   }
   else{
      if((int)s.size()%2==1){
         it++;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   char op;
   double a;
   it=s.begin();
   for(int i=1;i<=n;i++){
      cin>>op;
      if(op=='G'){
         print();
      }
      else{
         cin>>a;
         insert(a);
      }
   }
}
