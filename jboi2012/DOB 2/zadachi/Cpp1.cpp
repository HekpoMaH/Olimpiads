#include<iostream.h>
#include<fstream.h>
#include<math.h>
int main(){
 int n,i,j;
 double b[2][100],min,k1,k2,k3;

 cin>>n;
 ifstream fin("data.txt",ios::in);
 for(i=0;i<2;i++){
  for(j=0;j<n;j++){
   fin>>b[i][j];
  }
 }
 
for(i=0;i<n;i++)
{
 b[2][i]=sqrt(pow(b[1][i],2)+pow(b[2][i],2));

}
for(i=0;i<n;i++)
{
 min=b[2][i];
  for(j=i+1;j<n;j++)
  { 
   if(min>b[2][j])
   {
    k1=b[0][j];
    k2=b[1][j];
    k3=b[2][j];
    b[2][j]=b[2][i];
    b[1][j]=b[1][i];
    b[0][j]=b[0][i];
    b[0][i]=k1;
    b[1][i]=k2;
    b[2][i]=k3;
   }
  }
  
  cout<<b[0][i];
  cout<<b[1][i];
  cout<<b[2][i];
}
return 0;
}