#include<iostream>
int main ()
{
int s,n,x,br=0;
double d,g;
cin>>s>>n;
int masiv[n];
for(int i=0;i<n;i++)
cin>>masiv[i];
for(int i=0;i<n;i++)
	for(int j=1;j<n;j++)
	{if (masiv[j-1]>masiv[j]) {x=masiv[j-1];
						   masiv[j-1]=masiv[j];
						   masiv[j]=x;}}

for(int i=n-1; i>0;i--)
{br=br+s/masiv[i];
s=s%masiv[i];
if (s==0) break;}
cout<<br;
return 0 ; }

