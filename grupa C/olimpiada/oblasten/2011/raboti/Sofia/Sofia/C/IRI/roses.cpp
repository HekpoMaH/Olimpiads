#include <iostream>
using namespace std;


int main(){
  int m,n,k;
  cin>>m>>n>>k;
  int a[m][n];

  for(int i=0;i<m;i++){
    for(int ii=0;ii<n;ii++){
    cin>>a[i][ii];
    }
  }

  int max=0;
  int temp=0;
  int all=0;

  for(int i=0;i<=m-k;i++){
    for(int j=0;j<=n-k;j++){
      temp=0;
      for(int ii=0;ii<k;ii++){
        for(int jj=0;jj<k;jj++){
        temp=temp+a[i+ii][j+jj];
        }
      }
      if(temp>max)
          max=temp;

    }
  }
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        all=all+a[i][j];
    cout<<all-max<<endl;
    return 0;
}










