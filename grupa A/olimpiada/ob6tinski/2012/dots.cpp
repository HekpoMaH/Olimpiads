#include<bits/stdc++.h>
using namespace std;
struct vec{
   int x,y;
   vec(){}
   vec(int _x,int _y){
      x=_x;
      y=_y;
   }
   vec operator-(vec b){
      return vec(b.x-x,b.y-y);
   }
   int cross(vec b){
      return x*b.y-b.x*y;
   }
};
vec p[5];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   for(int i=1;i<=4;i++)
      cin>>p[i].x>>p[i].y;
   int s[5];
   vec AB=p[2]-p[1];
   vec AC=p[3]-p[1];
   vec AD=p[4]-p[1];
   vec BD=p[4]-p[2];
   vec BC=p[3]-p[2];
   s[1]=abs(AB.cross(AC));
   s[2]=abs(BC.cross(BD));
   s[3]=abs(AC.cross(AD));
   s[4]=abs(AB.cross(AD));
   sort(s+1,s+5);
   int br=0;
   for(int i=1;i<=4;i++){
      if(s[i]==0)br++;
   }
   if(br==4){
      cout<<0<<"\n";
      return 0;
   }
   if(br==2){
      cout<<1<<"\n";
      return 0;
   }
   if(br==1){
      cout<<2<<"\n";
      return 0;
   }
   if(br==0){
      if(s[1]+s[2]+s[3]==s[4])cout<<3<<"\n";
      else cout<<4<<"\n";
   }
}

