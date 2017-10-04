#include<iostream.h>
#include<string.h>
void main()
{char M[255];long m1[100][100],n,m,max,k,p,br=0,b=0,o;
cin>>n;
for(int i=0;i<n;i++)
{cin>>M[i];m=strlen(M);
for(int j=0;j<m;j++)
m1[i][j]=M[j]-'0';};
for(int l=0;l<n;l++)
for(int i=0;i<m;i++)
{k=m1[l][i];
if(b<br){b=br;o=k;};
for(int j=0;j<m;i++)
if(m1[l][j]==k){br++;p=k;};};
if(o==97)cout<<"a ";
if(o==98)cout<<"b ";
if(o==99)cout<<"c ";
if(o==100)cout<<"d ";
if(o==101)cout<<"e ";
if(o==102)cout<<"f ";
if(o==103)cout<<"g ";
if(o==104)cout<<"h ";
if(o==105)cout<<"i ";
if(o==106)cout<<"j ";
if(o==107)cout<<"k ";
if(o==108)cout<<"l ";
if(o==109)cout<<"m ";
if(o==110)cout<<"n ";
if(o==111)cout<<"o ";
if(o==112)cout<<"p ";
if(o==113)cout<<"q ";
if(o==114)cout<<"r ";
if(o==115)cout<<"s ";
if(o==116)cout<<"t ";
if(o==117)cout<<"u ";
if(o==118)cout<<"v ";
if(o==119)cout<<"w ";
if(o==120)cout<<"x ";
if(o==121)cout<<"y ";
if(o==122)cout<<"z ";
cout<<b;}