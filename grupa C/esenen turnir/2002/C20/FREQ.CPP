#include <iostream.h>
#include <stdio.h>
void main(){
char S[256],q;
int i,j,N,k,a[27],p;
cin>>N;
p=0;
for (i=1;i<N+1;i++){
	gets(S);
	for (j=0;j<27;j++) a[j]=0;
	j=0;
	while (S[j]!='\x0') {if (S[j]!=' ') a[S[j]-'a'+1]++;j++;}
	k=0;
	for (j=1;j<27;j++) if (a[j]>a[k]) k=j;
	if (a[k]>p) {p=a[k]; q=k+'a'-1;}
	}
cout<<q<<' '<<p;
}