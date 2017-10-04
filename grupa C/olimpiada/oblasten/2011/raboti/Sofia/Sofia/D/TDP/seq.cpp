#include<iostream>
using namespace std;
int main (){
  long long br, i = 0, j, max = 0;
  double a1, a2;
  cin >> a1 >> a2;
  br = 1;
  if(a2 != 0){
    while(a2 != 0){
      if(a2 >= a1){
        br ++;
      }else{
        if(br > max){
          max = br;
        }
        i ++;
        br = 1;
      }
      a1 = a2;
     cin >> a2;
    }
    cout << max;
  }else{
    cout << 1;
  }
  cout << '\n';
return 0;
}
