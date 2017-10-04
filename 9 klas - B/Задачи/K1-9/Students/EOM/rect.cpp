#include<iostream.h>
#include<math.h>
long n,a[6003],b[6003],c[6003],d[6003],x,sum;
long flag1,flag2,flag3,flag4;
int main()
{ long i,j;
  cin>>n;
  for(i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
  sum+=2*(c[1]-a[1]);
  sum+=2*(d[1]-b[1]);
  for(i=2;i<=n;i++)
  { flag1=0;
    flag2=0;
    flag3=0;
    flag4=0;
    for(j=1;j<=i-1;j++)
    { 
      if (a[i]==c[j])
      { if (b[i]>=b[j] && b[i]<=d[j])
        { if (d[i]>d[j]) { x=abs(d[i]-d[j]);sum+=x;}
        }
        else
        if (d[i]>=b[j] && d[i]<=d[j])
        { if (b[i]<b[j]) { x=abs(b[j]-b[i]);sum+=x;}
        }
        flag1=1;
      }
      if (c[i]==a[j])
      { if (b[i]>=b[j] && b[i]<=d[j])
        { if (d[i]>d[j]) { x=abs(d[i]-d[j]);sum+=x;}
        }
        else
        if (d[i]>=b[j] && d[i]<=d[j])
        { if (b[i]<b[j]) { x=abs(b[i]-b[j]);sum+=x;}
        }
        flag2=1;
      }
      if (b[i]==d[j])
      { if (a[i]>=a[j] && a[i]<=c[j])
        { if (c[i]>c[j]) { x=abs(c[i]-c[j]);sum+=x;}
        }
        else
        if (c[i]>=a[j] && c[i]<=c[j])
        { if (a[i]<a[j]) { x=abs(a[i]-a[j]);sum+=x;}
        }
        flag3=1;
      }
      if (d[i]==b[j])
      { if (a[i]>=a[j] && a[i]<=c[j])
        { if (c[i]>c[j]) { x=abs(c[i]-c[j]);sum+=x;}
        }
        else
        if (c[i]>=a[j] && c[i]<=c[j])
        { if (a[i]<a[j]) { x=abs(a[i]-a[j]);sum+=x;}
        }
        flag4=1;
      }
    }
   if (flag1==0) sum+=(d[i]-b[i]);
   if (flag2==0) sum+=(d[i]-b[i]);
   if (flag3==0) sum+=(c[i]-a[i]);
   if (flag4==0) sum+=(c[i]-a[i]);
  }
  cout<<sum<<endl;
return 0;
}
 
