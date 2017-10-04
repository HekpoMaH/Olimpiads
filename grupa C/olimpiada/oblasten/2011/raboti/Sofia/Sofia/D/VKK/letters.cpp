#include<iostream>
using namespace std;

char a[4][20],b;
long long n,izhod[4],dalzina,brbukwi,i,j;


int main(){
  cin>>n>>b;
  for(i=0;i<n;i++){
    cin>>a[0];
    if(a[0][0]==b || a[0][0]==(b-'a'+'A')){
      izhod[0]++;
    }
    cin>>a[1];
    brbukwi=0;
    dalzina=strlen(a[1]);
    for(j=0;j<dalzina;j++){
      if(a[1][j]==b || a[1][j]==(b-'a'+'A')){
        brbukwi++;
    }
    }
    if(brbukwi>0){
      izhod[1]++;
    }
    cin>>a[2];
    brbukwi=0;
    dalzina=strlen(a[2]);
    for(j=0;j<dalzina;j++){
      if(a[2][j]==b || a[2][j]==(b-'a'+'A')){
        brbukwi++;
    }
    }
    if(brbukwi>1){
    izhod[2]++;
    }
    cin>>a[3];
    dalzina=strlen(a[3]);
    if(a[3][dalzina-1]==b || a[3][dalzina-1]==(b-'a'+'A')){
      izhod[3]++;
    }
  }
  cout<<izhod[0]<<" "<<izhod[1]<<" "<<izhod[2]<<" "<<izhod[3]<<endl;
  return 0;
}


