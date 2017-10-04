#include<iostream>
using namespace std;
int n,k,a[1001][1001],m=-500001,ang[1001][1001],posi,posj;
void down(int i,int j,int k,int ori,int orj){
	if(i>n)return;
	//if(ori==1&&orj==1)cout<<i<<" "<<j<<endl;
	if(k==0)return;
	ang[ori][orj]+=a[i][j];
	down(i+1,j,k-1,ori,orj);
}
void right(int i,int j,int k,int ori,int orj){
	if(j>n)return;
	//if(ori==1&&orj==1)cout<<i<<" "<<j<<endl;
	if(k==0)return;
	ang[ori][orj]+=a[i][j];
	right(i,j+1,k-1,ori,orj);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  cin>>a[i][j];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
			  ang[i][j]+=a[i][j];
			  down(i+1,j,k,i,j);
			  right(i,j+1,k,i,j);
			}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	      if(ang[i][j]>m){
				m=ang[i][j];
				posi=i;
				posj=j;
			}  
	cout<<posi<<" "<<posj<<endl;		
return 0;				
}
