#include<iostream>
using namespace std;
int main (){
  int n, duljina1[100], duljina2[100], i, max1 = 0, max2 = 0, j = 0, p[4];
  cin >> n;
  for(i = 0; i < n; i ++){
    cin >> duljina1[i];
  }
  for(i = 0; i < n; i ++){
    cin >> duljina2[i];
    if(duljina1[i] <= duljina2[i]){
      if(duljina2[i] - duljina1[i] > max2){
        max2 = duljina2[i] - duljina1[i];
        p[0] = duljina1[i];
        p[1] = duljina2[i];
      }
    }else{
      if(duljina1[i] - duljina2[i] > max2){
        max2 = duljina1[i] - duljina2[i];
        p[0] = duljina1[i];
        p[1] = duljina2[i];
      }
    }
  }
  for(i = n - 1; i >= 0; i --){
    if(duljina1[i] <= duljina2[j]){
      if(duljina2[j] - duljina1[i] > max1){
        max1 = duljina2[j] - duljina1[i];
        p[2] = duljina1[i];
        p[3] = duljina2[j];
      }
    }else{
      if(duljina1[i] - duljina2[j] > max1){
        max1 = duljina1[i] - duljina2[j];
        p[2] = duljina1[i];
        p[3] = duljina2[j];
      }
    }
    j ++;
  }
  if(max1 <= max2){
    cout << p[0] + p[1];
  }else{
    cout << p[2] + p[3];
  }
  cout << '\n';
return 0;
}
