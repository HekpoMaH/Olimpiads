/*
TASK:future
LANG:C++
*/
#include<iostream>
using namespace std;

char a[200], b[200];
int a1[200], b1[200],a2[200], b2[200], c1[200], c[200], d[200],a11[200], b11[200];
int sum, k, k1, k2, k3, n, n1, n2, p, m,i,maxi, maxi1, j;
int main()
{cin>>a>>b>>k;
n=strlen(a);
m=strlen(b);
// n1 - po-golqmata daljina
if(n>m) n1=n; else n1=m;
//zapisvane na cifrite v masivi ot celi chisla
for(i=n-1; i>=0; i--) a1[n-1-i]=a[i]-'0';
for(i=m-1; i>=0; i--) b1[m-1-i]=b[i]-'0';
//proverka za po-golqmo chislo
i=0;  maxi1=0; maxi=0;
do
{if((a1[n1-1-i]>b1[n1-1-i]))
maxi=1;
else
{if(a1[n1-1-i]!=b1[n1-1-i]) maxi1=1;
else i=i+1;}} while (maxi==0 && maxi1==0);
//zapisvame po-golqmoto ot dvete chisla v masiva a1
if(maxi1==1)
{for(i=0; i<n1; i++) swap(a1[i],b1[i]);}
//izvajdane na chislata
for(i=0; i<n1; i++)
{if(b1[i]>a1[i]) { a1[i]=a1[i]+10; a1[i+1]=a1[i+1]-1;}
c[i]=a1[i]-b1[i];}
//umnojenie na dalgo chislo s dvucifreno chislo
k1=k%10; k2=k/10; p=0; n2=n1;
//umnojenie na chisloto s poslednata cifra na dvucifrenoto chislo
for(i=0; i<n1; i++)
{k3=c[i]*k1;
if(k3>9){a2[i]=k3%10+p;
if(i==n1-1){ a2[i+1]=k3/10; n2=n1+1;}
else p=k3/10;}
else {a2[i]=k3+p; p=0;}}
//umnojenie s parvata cifra
p=0;
for(i=0; i<n1; i++)
{k3=c[i]*k2;
if(k3>9){b2[i+1]=k3%10+p;
if(i==n1-1) {b2[i+2]=k3/10; n2=n1+1;}
else p=k3/10;}
else {b2[i+1]=k3+p; p=0;}}
//sabirane na dvete proizvedeniq
p=0;
for(i=0; i<=n2; i++)
{k3=a2[i]+b2[i];
if(k3>9){d[i]=k3%10+p;
if(i==n2){d[i+1]=k3/10; n2=n2+1;}
else p=k3/10;}
else {d[i]=k3+p; p=0;}}
//prebroqwame kolko nuli ima v nachaloto na rezultatnoto chislo
j=0;
i=n2;
do
{if(d[i]==0)
{j=j+1; }i=i-1;} while (d[i]==0);
//izvejdame rezultatnoto chislo (bez nulite v nachaloto) i izchislqvame suma na cifrite
sum=0;
for(i=n2-j; i>=0; i--)
{  cout<<d[i]; sum=sum+d[i];} cout<<endl;
//opredelqme koi cifri sa deliteli, kolko pati se sreshtat
k=0;  k2=0;
for(i=0; i<=n2; i++)
{if(d[i]>0){if(sum%d[i]==0)
{k1=d[i]; if(i>0){for(j=0;j<k;j++)
{if(a11[j]==k1){b11[j]=b11[j]+1; k2=1;}}}
if(k2==0){a11[k]=k1; b11[k]=1;if(i<n2){k=k+1;}} k2=0;}}}
//opredelqme cifrata, koqto se sreshta max broi pati
for(i=0; i<k-2; i++){if(b11[i]<b11[i+1])
{swap(b11[i],b11[i+1]); swap(a11[i],a11[i+1]);}}
cout<<a11[0]<<endl;
system("pause");
return 0;
}

//int main () {}
