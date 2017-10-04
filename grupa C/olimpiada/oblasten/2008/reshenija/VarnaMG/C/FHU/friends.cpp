#include<iostream>
#include<queue>
using namespace std;
long a[2001][2001],used[2001],m,c,b,n,mn,lvl[2001],l=1,br=1,h;
queue <int> q;
void BFS(int k){
	//cout<<k<<endl;
	used[k]=1;
	if(k==l){
		l=k;
		br++;
	}
	for(int i=1;i<=n;i++)
	  if((!used[i])&&a[k][i])
	                       {
								lvl[br]++;
								q.push(i);
								used[i]=1;
						   }
	if(!q.empty())q.pop();					   
	if(!q.empty())BFS(q.front());	
}				   	

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>c>>b;
		a[b][c]=1;
		a[c][b]=1;
	}
q.push(1);
for(h=1;h<=n;h++)
if(a[1][h]==1){
	l=h;
	break;
}
if(h==n+1){cout<<"0\n";return 0;}
BFS(1);
for(int i=1;i<=n;i++)
 if(lvl[i]>mn)mn=lvl[i];
 cout<<mn<<endl;
 
 //system("pause");
 
 
return 0;	
}
