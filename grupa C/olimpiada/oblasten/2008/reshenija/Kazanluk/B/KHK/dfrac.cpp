#include <iostream>
#include <cmath>
#include <cstring>
int a1[32000]={0};
int b1[32000]={0};
int res[32000]={0};
int k,p;
int la,lb;

void strtomas (char s[], int a[])
{
	int l=strlen(s);
	for(int i=0;i<l;i++)
	a[i]=s[i]-'0';
}

void delenie (int a[], int b, int res[])
{
int carry=a[0];
res[0]=a[0]/b;
for(int i=1;i<=la;i++)
	{
	
	res[i]=carry/b;
	carry=carry-res[i]*b;
	carry=carry*10+a[i];
	
//	  res[i]=carry/b;
	
	}
}

int main ()
{
char a[255];
int b;
int k,p;
cin>>a>>b;
cin>>k>>p;
la=strlen(a);
strtomas(a,a1);
delenie(a1,b,res);
for(int i=k;i<k+p;i++)
cout<<res[i];
return 0;

}
