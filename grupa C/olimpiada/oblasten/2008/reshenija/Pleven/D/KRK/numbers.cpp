#include<iostream>
using namespace std;
int main()
{ long a,b,c,d,i,j;
    cin>>a>>b>>c>>d;
  if(a!=0 && b!=0 && c!=0 && d==0)  {cout<<a<<" "<<b<<" "<<c<<" "<<a*b*b<<endl;}
  else
  if(a!=0 && b!=0 && c==0 && d!=0)  {cout<<a<<" "<<b<<" "<<a*a*b<<" "<<d<<endl;}
  else
  if(a!=0 && b==0 && c!=0 && d!=0)  {cout<<a<<" "<<c/a/a<<" "<<c<<" "<<d<<endl;}
  else
  if(a==0 && b!=0 && c!=0 && d!=0)  {cout<<d/b/b<<" "<<b<<" "<<c<<" "<<d<<endl;}
  else
  if(a!=0 && b!=0 && c==0 && d==0)  {cout<<a<<" "<<b<<" "<<a*a*b<<" "<<a*b*b<<endl;}
  else
  if(a!=0 && b==0 && c!=0 && d==0)  {cout<<a<<" "<<c/a/a<<" "<<c<<" "<<a*(c/a/a)*(c/a/a)<<endl;}
  else
  if(a==0 && b!=0 && c!=0 && d==0)  {for(i=-1000;i<=1000;i++)
  if(i*i==c/b) {cout<<i<<" "<<b<<" "<<c<<i*b*b<<endl;break;}}
  else
  if(a!=0 && b==0 && c==0 && d!=0)  {for(i=-1000;i<=1000;i++)
  if(i*i==d/a) {cout<<a<<" "<<i<<" "<<a*a*i<<" "<<d<<endl;break;}}
  else
  if(a==0 && b!=0 && c==0 && d!=0) {cout<<d/b/b<<" "<<b<<" "<<d/b/b*d/b/b*b<<" "<<d<<endl;}
  else
  if(a==0 && b==0 && c!=0 && d!=0) {for(i=-1000;i<=1000;i++)
  {for(j=-1000;j<=1000;j++) if(i*i*i*j*j*j==c*d && i*i*j==c && i*j*j==d && i>=j) {cout<<i<<" "<<j<<" "<<c<<" "<<d<<endl;}}}
  else 
  if(a==0 && b==0 && c==0 && d!=0) 
  for(i=-1000;i<=1000;i++)
  {
   for(j=-1000;j<=1000;j++) 
    if(i*j*j==d && i>=j) 
      {cout<<i<<" "<<j<<" "<<i*i*j<<" "<<d<<endl;break;}
   if(i*j*j==d && i>=j) break;
  } 
  else
  if(a==0 && b==0 && c!=0 && d==0) for(i=-1000;i<=1000;i++)
  {for(j=-1000;j<=1000;j++) if(i*i*j==c && i>=j) 
  {cout<<i<<" "<<j<<" "<<c<<" "<<i*j*j<<endl;break;} 
  if(i*i*j==c && i>=j) break;}
  else
  if(a!=0 && b==0 && c==0 && d==0) {cout<<a<<" "<<-1000<<" "<<a*a*(-1000)<<" "<<a*(-1000)*(-1000)<<endl;}
  else
  if(a==0 && b!=0 && c==0 && d==0) {cout<<-1000<<" "<<b<<" "<<(-1000)*(-1000)*b<<" "<<(-1000)*b*b<<endl;}
  else
  if(a!=0 && b!=0 && c!=0 && d!=0) {cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
  else
  if(a==0 && b==0 && c==0 && d==0) {cout<<-1000<<" "<<-1000<<" "<<(-1000)*(-1000)*(-1000)<<" "<<(-1000)*(-1000)*(-1000)<<endl;}
  
  return 0;
  }
