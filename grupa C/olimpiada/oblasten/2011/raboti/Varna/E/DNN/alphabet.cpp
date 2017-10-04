#include <iostream>
using namespace std;
int main ()
{
char a,b,b1,a1;
int i,n,m,d=0,c,s;
cin>>n>>m;
if(n==1)b='a',b1='A';
if(n==2)b='b',b1='B';
if(n==3)b='c',b1='C';
if(n==4)b='d',b1='D';
if(n==5)b='e',b1='E';
if(n==6)b='f',b1='F';
if(n==7)b='g',b1='G';
if(n==8)b='h',b1='H';
if(n==9)b='i',b1='I';
if(n==10)b='j',b1='J';
if(n==11)b='k',b1='K';
if(n==12)b='l',b1='L';
if(n==13)b='m',b1='M';
if(n==14)b='n',b1='N';
if(n==15)b='o',b1='O';
if(n==16)b='p',b1='P';
if(n==17)b='q',b1='Q';
if(n==18)b='r',b1='R';
if(n==19)b='s',b1='S';
if(n==20)b='t',b1='T';
if(n==21)b='u',b1='U';
if(n==22)b='w',b1='W';
if(n==23)b='v',b1='V';
if(n==24)b='x',b1='X';
if(n==25)b='y',b1='Y';
if(n==26)b='z',b1='Z';
for(i=1;i<=m;i++)
{
 cin>>a;
 if(a==b||a==b1)d++;
 for(;a1='.';)
   cin>>a1;
 cout<<endl;
 if(d!=0)s=i;
}
if(d==0)cout<<"lose"<<endl;
else cout<<"win "<<s<<endl;
system ("pause");
return 0;
}
