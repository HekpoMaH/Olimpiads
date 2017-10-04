#include <iostream>
using namespace std;
int a[4];
int MaxNo(int start)
{int i,m=start;
 for(i=start+1;i<4;i++) if (a[i]>a[m]) m=i;
 return m;
}
void selSort(void)
{int i,j,c;
 for (i=0;i<3;i++){j=MaxNo(i);
                   c=a[i];
                   a[i]=a[j];
                   a[j]=c;
                  }
}
int better(void)
{int i,j,m=100,p,q,d=10;
 selSort();
 for (i=0;i<3;i++) if (a[i]-a[i+1]<d) d=a[i]-a[i+1];
 for (i=0;i<3;i++)
  if (a[i]-a[i+1]==d)
  {p=10*a[i];
   q=10*a[i+1];
   switch(i)
   {case 0:{p+=a[3];q+=a[2];break;}
    case 1:{p+=a[3];q+=a[0];break;}
    case 2:{p+=a[1];q+=a[0];}
   }
   if (p-q<m) m=p-q;
  }
 return m;
}
int main(void)
{int i;
 for (i=0;i<4;i++) cin>>a[i];
 cout<<better()<<endl;
 return 0;
}
