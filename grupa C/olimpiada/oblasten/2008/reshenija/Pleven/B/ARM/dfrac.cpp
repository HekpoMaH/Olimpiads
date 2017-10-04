#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
string t(""),c(""),d("");
char x[100];
long long pow(int f)
{int i;
long long r=10;
for(i=1;i<f;i++)
r*=10;
return r;
}
bool only_0()
{int i,size;
size=c.size();
for(i=0;i<size;i++)
if(c[i]!='0') return false;
return true;
}
void fill_0(int n)
{int i;
c="";
for(i=1;i<=n;i++)
c+='0';
}
int main()
{long long q,h,a,b,k,r;
int i=0,j=0,index=1,p,size;
bool flag=true,fl=false;
cin>>a>>b>>k>>p;
q=a;
while(1)
{h=q*10;
r=a*pow(j+1);
if(r%b==0) {fill_0(index);ltoa(r/b,x,10);c+=x;fl=true;break;}
if(r>b && flag) {index=j;flag=false;}
i=h/b;
t+=char(i+48);
if((j+1)%2==0)
{c=t.substr(0,(j+1)/2);d=t.substr((j+1)/2);
if(c==d && !only_0()) break;
}
q=h%b;
j++;
}
size=c.size();
if(!fl) {
i=k%size-1;j=0;
if(i<0) i=0;
while(j<p)
{if(i>=size) i=0;
cout<<c[i];
i++;j++;
}}
else {
if(k>size)
for(j=0;j<p;j++)
cout<<0;
else {
j=k-1;
while(j<size && p>0)
{cout<<c[j];j++;p--;}
if(p>0)
while(p>0) {cout<<0;p--;}
}}
cout<<endl;	
return 0;
}
