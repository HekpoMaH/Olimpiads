#include<iostream>
#include<string.h>
using namespace std;
long a[1010][31][31];
long b[1010];
long otg,max1,fl,x,br1,br2,br,n,m,t,m1;
char vhod[100];

long time1(long x, long y, long fl)
{
  long br,br1;
  if(fl==1) return 1;
  for(br=1; br<=n; br++)
   for(br1=1; br1<=n; br1++)
    if(a[x][br][br1]!=a[y][n-br1+1][br]) break;
  if(br==n+1 && br1==n+1) return 1;
  return 0;
}

long time2(long x, long y, long fl)
{
  long br,br1;
  if(fl==1) return 1;
  for(br=1; br<=n; br++)
   for(br1=1; br1<=n; br1++)
    if(a[x][br][br1]!=a[y][n-br+1][n-br1+1]) break;
  if(br==n+1 && br1==n+1) return 1;
  return 0;
}

long time3(long x, long y, long fl)
{
  long br,br1;
  if(fl==1) return 1;
  for(br=1; br<=n; br++)
   for(br1=1; br1<=n; br1++)
    if(a[x][br][br1]!=a[y][n-br1+1][n-br+1]) break;
  if(br==n+1 && br1==n+1) return 1;
  return 0;
}

long drugite_3(long x, long y, long fl)
{
 long m3,m1,m2;
 if(fl==1) return 1;
 m1=time1(x,y,fl);
 m2=time2(x,y,fl);
 m3=time3(x,y,fl);
 if(m1==1 || m2==1 || m3==1) return 1;
 return 0;
}




// ednakvi ==
long ednakvi(long x, long y, long fl)
{
 long br,br1;
	   for(br=1; br<=n; br++)
	    for(br1=1; br1<=n; br1++)
	     if(a[x][br][br1]!=a[y][br][br1]) break;
 if(br==n+1 && br1==n+1) return 1;
 return drugite_3(x,y,fl);
}


// obratno ^
long obratno(long x, long y, long fl)
{
 long br,br1,p=0,temp;
 if(fl==1) return 1;
	   for(br=1; br<=n; br++)
	    for(br1=1; br1<=n; br1++)
	    {
	     if(a[x][br][br1]!=a[y][n-br+1][br1]) p=1;
	     temp=a[x][br][br1];
	     a[x][br][br1]=a[y][n-br+1][br1];
	     a[y][n-br+1][br1]=temp;
	    }

 if(p==0) return 1;
 return drugite_3(x,y,fl);
}






int main()
{
 long br3,dal;
 cin>>m>>n;

 m1=m;;
 for(br=1; br<=m; br++)
 {
	   for(br1=1; br1<=n; br1++)
	    {
		       cin>>vhod;
		       dal=strlen(vhod);
		       for(br3=0; br3<=dal; br3++)
		       {
			a[br][br1][br3+1]=vhod[br3]-'0';
			if(a[br][br1][br3]==1) b[br]++;
		       }
	    }

 }
 do
 {
	   fl=0;
	   for(br=1; br<=m; br++) if(b[br]>0) {x=b[br]; fl=1; break;}
	   if(fl==0) break;
	   for(br1=br+1; br1<=m; br1++)
		       if(b[br1]==x)
		       {
			t=ednakvi(br,br1,0);
			if(t==0) t=obratno(x,br1,0);
			if(t==1) {m1--; b[br1]=-b[br1];}
		       }
	   b[br]=-b[br];
 }
 while(1==1);
 cout<<m1<<endl;
// system("Pause");
 return 0;
}
