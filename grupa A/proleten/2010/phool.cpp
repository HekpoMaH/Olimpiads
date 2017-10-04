#include<bits/stdc++.h>
using namespace std;
const double eps=1e-5;
double get_angle(double a,double b,double c){
   return acos((a*a+b*b-c*c)/(2*a*b));
}
double get_side(double a,double b,double alpha){
   return sqrt(a*a+b*b-2*a*b*cos(alpha));
}
bool valid(double a,double b,double c){
   return a<b+c&&b<a+c&&c<a+b;
}
bool valid(double a,double b,double c,double d){
   return a<b+c+d&&b<a+c+d&&c<a+b+d&&d<a+b+c;
}
double attempt(int a,int b,int c,int d){
   if(!valid(a,b,c,d))return -1;
   if(!valid(a,b+c,d))return -1;
   double alpha=get_angle(b+c,a,d);
   double cut=get_side(a,b,alpha);
   return cut;
}
set<int> cuts;
void add(double cut){
   if(cut==-1)return;
   cut*=100;
   cuts.insert((int)cut);
}
int main(){
   int s[4],idx[4]={0,1,2,3};
   for(int i=0;i<4;i++)cin>>s[i];
   do{
      add(attempt(s[idx[0]],s[idx[1]],s[idx[2]],s[idx[3]]));
   }while(next_permutation(idx,idx+4));
   cout<<cuts.size()<<"\n";
   set<int>::iterator it;
   for(it=cuts.begin();it!=cuts.end();it++){
      cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)*it/100.0<<"\n";
   }
}
