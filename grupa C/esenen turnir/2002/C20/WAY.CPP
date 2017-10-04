#include <iostream.h>
void main(){
int a[11][11],N,obh[11],i,j,k,p,b[11],c[11],i1,j1,d[11];
cin>>N;
for (i=1;i<N+1;i++)
 for (j=1;j<N+1;j++)
  a[i][j]=0;
for (i=1;i<=((N*(N-1))/2);i++) {cin>>k>>p>>j; if (j==1) {a[k][p]=1;a[p][k]=1;}}
cin>>i1>>j1;
for (i=1;i<11;i++) {b[i]=0;c[i]=0;d[i]=0;obh[i]=0;}
b[1]=i1;
obh[i1]=1;
k=1;
p=1;
while ((p<N+1) && (k<N+1)){
	for (i=1;i<N+1;i++) if ((a[b[k]][i]==1) && (a[i][b[k]]==1) && (obh[i]==0)) {obh[i]=1;p++;b[p]=i;c[p]=k;
	if (b[p]==j1) break;}
	if (b[p]==j1) break;
	k++;
	}
if (b[p]==j1){
	d[10]=b[p];
	i=9;
	while (c[p]!=1){d[i]=b[c[p]];p=c[p];i--;}
	d[i]=i1;
	p=11-i;
	cout<<p<<"\n";
	while (i<11) {p++;cout<<d[i]<<' ';i++;}
	}
else cout<<'0';
}