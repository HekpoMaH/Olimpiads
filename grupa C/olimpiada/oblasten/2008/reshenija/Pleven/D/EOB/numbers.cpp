#include<iostream>
#include<math.h>
using namespace std;
long a,b,i,c,d,x,k;
int main()
 {
 cin>>a>>b>>c>>d;
 if(a==0&&b==0&&c==0&&d==0) {a=-1000;b=a;c=a*a*a;d=c;}
 if((c==0||d==0)&&b!=0&&a!=0) {c=a*a*b;d=a*b*b;}
 if(a!=0&&c!=0&&(b==0||d==0)) {b=c/(a*a);d=b*b*a;}
 if(d!=0&&b!=0&&(a==0||c==0)) {a=d/(b*b);c=a*b*a;}
 if(a>0&&b==0&&c==0&&d==0) {b=-1000;c=a*a*b;d=b*b*a;}
 if(b>0&&a==0&&c==0&&d==0) {a=-1000;c=a*a*b;d=b*b*a;}
 if(b>0&&c>0&&d==0&&a==0) {a=(long)sqrt(c/b);if(a>0) a=-a;d=b*b*a;}
 if(a>0&&d>0&&c==0&&b==0) {b=(long)sqrt(d/a);if(b>0) b=-b;c=b*a*a;}
 if(c!=0&&a==0&&b==0&&d==0)
 for(i=-1000;i<=1000;i++)
 {if(i!=0)
  {x=(long)c/(i*i);
  if(c==i*i*x) {a=i;b=x;d=b*b*a;break;}}
 }
 if(d!=0&&a==0&&b==0&&c==0)
 for(i=-1000;i<=1000;i++)
 if(i!=0)
  {k=(long)d/i;
  x=(long)sqrt(k);
  if(x>0) x=-x;
  if(d==i*x*x) {a=i;b=x;c=a*a*b;break;}
  }
 
 if(a==0&&b==0&&c!=0&&d!=0)
  for(i=-1000;i<=1000;i++)
 {if(i!=0)
  {x=(long)c/(i*i);
  if(c==i*i*x&&d==i*x*x) {a=i;b=x;break;}
  }
 }
 cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
 return 0;
 }
