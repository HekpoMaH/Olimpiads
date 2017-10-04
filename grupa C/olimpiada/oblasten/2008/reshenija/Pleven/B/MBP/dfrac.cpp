#include<iostream>
using namespace std;
unsigned long long br,br1,a,b,st,n,daljina,bonus,n1;
unsigned long long c[1000],used[100],ost[1000];
long napravi(long x,long en)
{
 long br,br1,br2=0;
 for(br=1; br<=en; br++) if(c[br]==x) break;
 bonus=br-1;
 for(br1=br; br1<=en; br1++)
 {
  br2++;
  ost[br2]=c[br1];           
 }
 return br2;
}


void smetni(long a,long b)
{
 long br=0,br1,fl=0;
 do
 {
     br++;
     a*=10;
     c[br]=a/b;
     a%=b;
     if(used[c[br]]==0) used[c[br]]=br;
      else {fl=1; daljina=napravi(c[br],br);}
 }
 while(fl!=1);
}






int main()
{
 cin>>a>>b>>st>>n;
 a%=b;
 n1=n;
 smetni(a,b);
 if(bonus>=st)
	       for(br=st; br<=st+n1; br++)
	       {
			  if(n==0) break;
			  cout<<c[br];
			  n--;
	       }
  else
  {
       st-=bonus;
       st%=daljina;
       br=st;
       if(br==0) br=daljina;
       if(n>0)
       do
       {
	 //    cout<<c[br];
	     n--;
	     if(br>=daljina) br=1;
	     cout<<ost[br];
	     if(n==0) break;
             br++;
       }
       while(1==1);

  }
  cout<<endl;
// system("Pause");
 return 0;
}
