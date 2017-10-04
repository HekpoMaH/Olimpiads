#include <iostream>
using namespace std;

struct point{
  int x,y;
};
int n,n2,jcount;
point cord[16];
long temp=0;
char used[16];
unsigned long best=(unsigned long)(-1);
unsigned long a[16][16];

unsigned absl(int x){
  if(x>0)
    return x;
  else
    return x*-1;
}

void minP(int i,int j){
  if(((cord[i].x+cord[i].y)%2==1)||((cord[j].x+cord[j].y)%2==1)){
    a[i][j]=(unsigned long)(-1);
    a[j][i]=a[i][j];
    return;
  }
  point temp;
  temp.x=absl(cord[i].x-cord[j].x);
  temp.y=absl(cord[i].y-cord[j].y);
  if(temp.x>temp.y)
    a[i][j]=temp.x;
  else
    a[i][j]=temp.y;
  a[j][i]=a[i][j];
}
void findMinP(int i,int j){
  jcount++;
  temp+=a[i][j];
  if(jcount==n){
    if(best>temp&&temp!=0)
      best=temp;
    temp-=a[i][j];
    jcount--;
    return;
  }
  used[i]=1;
  used[j]=1;
  for(int z=0;z<n2;z++)
    if(!used[z])
      findMinP(j,z);
  jcount--;
  temp-=a[i][j];
  used[j]=0;
}
int main(){
  int i,j;
  cin>>n;
  n2=2*n+1;
  cord[0].x=cord[0].y=0;
  used[0]=0;
  jcount=0;
  for(i=1;i<n2;i++){
    cin>>cord[i].x>>cord[i].y;
    used[i]=0;
  }
  for(i=0;i<n2;i++)
    for(j=i;j<n2;j++){
      if(i==j){
        a[i][j]=(unsigned long)(-1);
        a[j][i]=a[i][j];
      }
      else
        minP(i,j);
    }
  for(i=1;i<n2;i++){
    findMinP(0,i);
    used[0]=0;
  }
  /*for(i=0;i<n2;i++){
    for(j=0;j<n2;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }*/
  cout<<best<<endl;
  return 0;
}