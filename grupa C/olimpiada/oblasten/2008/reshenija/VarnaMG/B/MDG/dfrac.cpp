#include <iostream>
using namespace std;
unsigned long a,b,p;
long long k;

int nod(int x, int y)
    {
     for(;x!=y;)
        {
         if(y>x){int z; z=x;x=y;y=z;}
         x-=y;
         }
     return x;
     }
int main()
{
int i,j;
int z=0;
string m;
scanf("%lu%lu%lld %lu",&a,&b,&k,&p);
unsigned long x=nod(a,b);
a/=x;
b/=x;

//cout<<a<<" "<<b<<endl;
a-=(a/b)*b;
//if(a<b)a*=10;
m='\0';

int null=0;

for(i=0; i<k+p-1;i++)
   {
        if(a==0)
         {
          if(z)z=2;
          if(k<m.size()){for(j=k;j<m.size();j++)printf("%d",m[j]);
            for(j=m.size()-k;j<p;j++)printf("0",m[i]);}
            else for(j=0;j<p;j++)printf("0",m[i]);
          printf("\n");
          return 0;
          }
    if(a<b)a*=10;
    for(;a<b&&a;){a*=10;m+=null;i++;} //moje posle da izkara 1 znak pove4e ?
    //m[m.size()]=a/b;
    if(m[0]==a/b){z=1;break;}
    m+=a/b;
    a=a%b;
    }
//if(z==0)
string n;
int t;
if(z==1)
        {
         k%=m.size();
         if(p>m.size()-k)
                         {
                          for(i=k;i<m.size();i++)n+=m[i]  +'0';
                          t=p/m.size();
                          for(i=0;i<t;i++)
                            for(j=0;j<m.size();j++)n+=m[i]  +'0';
                          p%=m.size();
                          for(i=0;i<p;i++)n+=m[i]  +'0';
                          }         
         else for(i=k;i<p;i++)n+=m[i]  +'0';
         cout<<n;
         }
//else if(z==2){for(j=0;j<p;j++)printf("0",m[i]);    printf("\n");}
else for(i=k;i<k+p;i++)printf("%d",m[i]);  printf("\n");
return 0;
}
