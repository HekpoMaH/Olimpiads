#include<math.h>
#include<iostream.h>
void main()
{int n,min,a,b,ma,m  b;
cin>>n;
min=n-1;
for(a=1; a<=n; a++)
{b=n/a;
if(b*a==n)
 if(fabs(b-a)<min)
  {min=fabs(b-a);
  ma=a;
  mb=b;
  }
}
cout<<ma<<' '<<mb;

}