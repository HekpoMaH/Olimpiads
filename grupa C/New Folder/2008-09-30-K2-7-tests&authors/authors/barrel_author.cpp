  #include <iostream>
  #include <math.h>
using namespace std;
void extended_euclid(int a, int b, int &x1, int &y1, int &d)
{int x2,y2;
x1=1;x2=0;y1=0;y2=1;
    while (a!=b)
       {if (a>b) {a=a-b;x1=x1-x2;y1=y1-y2;}
        else {b=b-a;x2=x2-x1;y2=y2-y1;}}
    d=b; 
}  
int main()
{int a,b,d,x,y,c,x0,y0,i,min,xx,yy,a1,b1;
 cin>>a>>b>>c;a1=a;b1=b;
    extended_euclid(abs(a),abs(b), x, y, d);
 if (c%d==0) 
  {a=a/d;b=b/d;c=c/d;
  extended_euclid(abs(a),abs(b), x, y, d);
  x0=x*c;y0=y*c;
  min=abs(x0)*a+abs(y0)*b;xx=x0;yy=y0;
for (i=-c;i<=c;i++)
  {x=x0-b*i;
   y=y0+a*i;
   if (abs(x)*a+abs(y)*b<=min) {min=abs(x)*a+abs(y)*b;xx=x;yy=y;}
   }
   cout<<abs(xx)+abs(yy)<<endl;
   cout<<abs(xx)*a1+abs(yy)*b1<<endl;
 if (xx>0) for (i=1;i<=xx;i++) cout<<"+1"<<endl;
 if (yy>0) for (i=1;i<=yy;i++) cout<<"+2"<<endl;
 if (xx<0) for (i=1;i<=abs(xx);i++) cout<<"-1"<<endl;
 if (yy<0)for (i=1;i<=abs(yy);i++) cout<<"-2"<<endl;
}
else cout<<"NO SOLUTION\n";   
//system("pause");
return 0;
}  
