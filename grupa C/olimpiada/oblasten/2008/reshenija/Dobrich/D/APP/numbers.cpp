#include<iostream.h>
#include<math.h>
int main()
{int a,b,a2b,ab2,m=1;
cin>>a>>b>>a2b>>ab2;

// 1
if(a!=0&&b!=0&&a2b!=0)ab2=a*b*b;
else if(b!=0&&a2b!=0&&ab2!=0)a=0-sqrt(a2b/b);
else if(a!=0&&b!=0&&ab2!=0)a2b=a*a*b;
else if(a!=0&&a2b!=0&&ab2!=0)b=sqrt(ab2/a);

// 2 
else if(a!=0&&b!=0){a2b=a*a*b; ab2=a*b*b;}
else if(a!=0&&a2b!=0){b=a2b/(a*a); ab2=a*b*b;}
else if(a!=0&&ab2!=0){b=sqrt(ab2/a); a2b=a*a*b;}
else if(b!=0&&ab2!=0){a=sqrt(a2b/b); ab2=a*b*b;}
else if(b!=0&&a2b!=0){a=sqrt(a2b/b); ab2=a*b*b;}

// 3

else if(ab2!=0){m=sqrt(ab2); if( m==sqrt(ab2)){a=1;b=0-m;a2b=a*a*b;}
                             
}

cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2;

return 0 ;
}
