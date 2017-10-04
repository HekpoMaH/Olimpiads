#include<iostream>
using namespace std;
bool gotovo;
int main (){
  long long n, i, j, br1 = 0, br2 = 0, br3 = 0, br4 = 0, k, l;
  cin >> n;
  char bukva, duma[4][51];
  cin >> bukva;
  for(i = 0; i < n; i ++){
    for(j = 0; j < 4; j ++){
      k = 0;
      l = 0;
      gotovo = false;
      cin >> duma[j];
      if(j == 0){
        if(duma[j][0] == bukva || duma[j][0] == bukva - 32){
          br1 ++;
        }
      }else{
        if(j == 1){
          while(!gotovo && k < strlen(duma[j])){
            if(duma[j][k] == bukva || duma[j][k] == bukva - 32){
              br2 ++;
              gotovo = true;
            }
            k ++;
          }
        }else{
          if(j == 2){
            while(!gotovo && k < strlen(duma[j])){
              if(duma[j][k] == bukva || duma[j][k] == bukva - 32){
                l ++;
              }
              if(l == 2){
                br3 ++;
                gotovo = true;
              }
              k ++;
            }
          }else{
            l = strlen(duma[j]);
            if(duma[j][l - 1] == bukva || duma[j][l - 1] == bukva - 32){
              br4 ++;
            }
          }
        }
      }
    }
  }
  cout << br1 << ' ' << br2 << ' ' << br3 << ' ' << br4;
  cout << '\n';
return 0;
}
/*
3 a
Ani Miraj Masa Bala
Taralej toto Dani Kana
ananas pile ananas Tapa
*/
// Chetat se simvol po simvol.
