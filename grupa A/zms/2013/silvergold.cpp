#include<bits/stdc++.h>
using namespace std;

const int nmax=109;

struct svg{
   double w,ratio;
   svg(){}
   svg(double _w,double _g,double _s){
      w=_w;
      ratio=_g/(_g+_s);
   }
};
bool cmp(svg fi,svg se){
   return fi.ratio<se.ratio;
}
svg a[nmax];
int n;
void invratio(){
   for(int i=1;i<=n;i++){
      a[i].ratio=1.0-a[i].ratio;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   double w1=0.0,w2=0.0;
   for(int i=1;i<=n;i++){
      double w,silv,gold;
      cin>>w>>gold>>silv;
      a[i].w=w;
      a[i].ratio=gold/(gold+silv);
      w1+=a[i].w*a[i].ratio;
      w2+=a[i].w*(1.0-a[i].ratio);
   }
   if(w1<w2){
      //cout<<"INV\n";
      invratio();
   }
   sort(a+1,a+n+1,cmp);
   w1=0.0;w2=0.0;
   for(int i=1;i<=n;i++){
      w1+=a[i].w*a[i].ratio;
      w2+=a[i].w*(1.0-a[i].ratio);
      if(w1>w2){
         //cout<<w1<<" "<<w2<<"\n";
         w1-=a[i].w*a[i].ratio;
         w2-=a[i].w*(1.0-a[i].ratio);
         //cout<<i<<" "<<w1<<" "<<w2<<"\n";
         double l=0.0,r=1.0,mid;
         for(int j=1;j<=100;j++){
            mid=(l+r)/2.0;
            double ww1=w1+mid*a[i].w*a[i].ratio;
            double ww2=w2+mid*a[i].w*(1.0-a[i].ratio);
            if(ww1<ww2)l=mid;
            else r=mid;
         }
         w1+=r*a[i].w*a[i].ratio;
         w2+=r*a[i].w*(1.0-a[i].ratio);
         break;
      }
   }
   cout<<setiosflags(ios::fixed)<<setprecision(6)<<(w1+w2)<<"\n";
}
