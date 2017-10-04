#include<iostream.h>
#include<math.h>
using namespace std;
unsigned long long a,b,k,p,c[3001],d[3001],v,x,x1,flag,y,br,br1;
char q[3001];
int main()
{ long i,j,t;
  cin>>a>>b;
  cin>>k>>p;
  x=a;
  while (1!=2)
  { if (x==0) { y=1;break;} 
    x*=10;
    if (x<b) { v++;c[v]=0;}
    else
    { x1=(x/b)%10;
      v++;c[v]=x1;
      x-=(x/b)*b;
    }
    if (v==19) break;
  }
  if (y==1)
  { if (k<v) 
    { cout<<c[k];
      for(i=k+1;i<=v;i++) cout<<c[i];
      if (p-(v-k+1)>0)
       for(i=1;i<=p-(v-k+1);i++) cout<<0;
    }
    if (k==v)
    { cout<<c[k];
      for(i=1;i<=p-1;i++) cout<<0;
    }
    if (k>v)
    { for(i=1;i<=p;i++) cout<<0;
    }    
    cout<<endl;
  }
  else
  { for(i=1;i<=v-1;i++)
    { for(j=i+1;j<=v;j++)
       if (c[i]==c[j])
       { br=1;
         d[br]=c[i];
         for(t=i+1;t<=j-1;t++)
          if (c[t]==c[t+j-i]) br1++;
         if (br1==j-i-1)
         { flag=1;
           for(t=i+1;t<=j-1;t++) 
           { br++;
             d[br]=c[t];
           }
         }
         if (flag==1) break;
       }
       if (flag==1) break;
    }
    if (k<=br) { x1=k;x=d[k];}
    else
    { x1=k%br;
      x=d[x1];
    }
    for(i=1;i<=br;i++) d[i+br]=d[i];
    v=0;
    for(i=x1;i<=x1+br-1;i++) { v++;q[v-1]=d[i]+48;}
    x1=p/br;
    for(i=1;i<=x1;i++) cout<<q;
    x1=p%br;
    for(i=0;i<=x1-1;i++) cout<<q[i];
    cout<<endl;
  } 
return 0;
}
  
