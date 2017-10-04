#include <iostream>
#include <math.h>
using namespace std;
int a[5],n=4;
//syzdawane na masiwot delitelite na a[n] 
void delit(int a, int p[], int &k)
{ int j;k=0;
  for (j=1;j<=abs(a/2);j++)
      if (a%j==0) {p[k]=j;k++;p[k]=-j;k++;}
  p[k]=a;k++;p[k]=-a;k++;
}

void kratn(int b, int a[], int c[], int &m)
{int i;
 c[0]=a[0];
 for (i=1;i<n;i++)
  c[i]=a[i]+b*c[i-1];
m=a[n]+b*c[n-1]; 
}

int main()
{int i,j,k=0,m,q=0;long long pp;
int p[10001],z[10001],s[10001];
      a[0]=1;
for (i=1;i<=n;i++) cin>>a[i];
delit(a[n],p,k);
   //prowerka dali sa koreni   pp==0
m=-1;
   for (i=0;i<k;i++)
     {pp=a[0];
     for (j=1;j<=n;j++) pp=pp*p[i]+a[j];
     if (abs(pp)==0)  { m++; z[m]=p[i];}
   }   
 //prowerka dali sa kratnost
for (i=0;i<=m;i++) 
  { k=0;
    while (k==0) 
     {kratn(z[i],a,p,k);
      if (k==0) {n=n-1; for (j=0;j<=n;j++) a[j]=p[j];
                 s[q]=z[i];q++;}
     }
} 

for (i=0;i<q;i++)
  {cout<<"(x";
   if (s[i]>0) cout<<"-"<<s[i]<<")";
   else {s[i]=-s[i];cout<<"+"<<s[i]<<")";}
} 

if (n!=0) {cout<<"(";
           for (i=0;i<n;i++) 
               {if (a[i]!=0) if (a[i]>0) cout<<"+"<<a[i]<<"x^"<<n-i;
                             else {a[i]=-a[i];cout<<"-"<<a[i]<<"x^"<<n-i;}
               } 
           if (a[n]>0) cout<<"+"<<a[i];
           else {a[n]=-a[i];cout<<"-"<<a[i];}
           cout<<")";
          }
 cout<<endl;

cin>>n;
       return 0;
       }
