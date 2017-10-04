#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const double pi=acos(-1.0);
double torad(double deg){
   return deg*pi/180.0;
}
double x[5],y[5];
lli cx[5],cy[5];
double dasin=sin(torad(0.0001)),dacos=cos(torad(0.0001));
void rotate(){
   double nwx,nwy;
   for(int i=1;i<=4;i++){
      nwx=x[i]*dacos-y[i]*dasin;
      nwy=x[i]*dasin+y[i]*dacos;
      x[i]=nwx;
      y[i]=nwy;
   }
}
double projection(){
   double themn,themx;
   double p;
   themn=x[1];
   themx=x[1];
   for(int i=2;i<=4;i++){
      themn=min(themn,x[i]);
      themx=max(themx,x[i]);
   }
   p=themx-themn;

   themn=y[1];
   themx=y[1];
   for(int i=2;i<=4;i++){
      themn=min(themn,y[i]);
      themx=max(themx,y[i]);
   }
   p=max(p,themx-themn);
   return p;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   double mnproj,proj;
   lli mnx=1e9,mny=1e9;
   for(int i=1;i<=4;i++){
      cin>>cx[i]>>cy[i];
      mnx=min(mnx,cx[i]);
      mny=min(mny,cy[i]);
   }
   for(int i=1;i<=4;i++){
      cx[i]=cx[i]-mnx;
      cy[i]=cy[i]-mny;
      x[i]=cx[i];
      y[i]=cy[i];
   }
   mnproj=projection();
   for(int i=1;i<900000;i++){
      rotate();
      proj=projection();
      mnproj=min(mnproj,proj);
   }
   cout<<setiosflags(ios::fixed)<<setprecision(3)<<mnproj<<"\n";
}
