#include<iostream>
using namespace std;
int main(){
  int brredove,brtursenivkolonka[4],kolkopatisesreshta[10000],i,j;
  char dumi[10000][4][50],tursenabukva;
  cin>>brredove>>tursenabukva;
  for(i=0;i<brredove;i++){
    for(j=0;j<4;j++){
      cin>>dumi[i][j];
    }
  }
  for(i=0;i<4;i++){
    brtursenivkolonka[i]=0;
  }
  for(i=0;i<brredove;i++){
    if(dumi[i][0][0]==tursenabukva||dumi[i][0][0]==tursenabukva-'a'+'A'){
      brtursenivkolonka[0]++;
    }
    for(j=0;j<strlen(dumi[i][1]);j++){
      if(dumi[i][1][j]==tursenabukva||dumi[i][1][j]==tursenabukva-'a'+'A'){
        brtursenivkolonka[1]++;
      }
    }
    for(j=0;j<strlen(dumi[i][2]);j++){
      if(dumi[i][2][j]==tursenabukva||dumi[i][2][j]==tursenabukva-'a'+'A'){
        kolkopatisesreshta[i]++;
      }
    }
    if(kolkopatisesreshta[i]>=2){
      brtursenivkolonka[2]++;
    }
    if(dumi[i][3][strlen(dumi[i][3])-1]==tursenabukva||dumi[i][3][strlen(dumi[i][3])-1]==tursenabukva-'a'+'A'){
      brtursenivkolonka[3]++;
    }
  }
  for(i=0;i<4;i++){
    cout<<brtursenivkolonka[i]<<" ";
  }
  cout<<'\n';
  return 0;
}