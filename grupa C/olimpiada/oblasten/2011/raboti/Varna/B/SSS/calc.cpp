#include <iostream>
#include <cmath>
using namespace std;

int final = 1000000;
int s, n;

bool checkprime(int x)
{
      if (x == 1) return true;
      for(int i = 2; i <=sqrt(x); i++) if(x%i == 0) {return false;}
      return true;
}

int division(int x)
{
      for(int i = n; i > 1; i--) {if(x%i == 0) return i;}
      return 1;
}
int main()
{
      cin >> s >> n;
      if(n == 1) {cout << s; return 0;}
      if(n >= s) {cout << "1"; return 0;}
      if(s == 1) {cout << "1"; return 0;}
      //for(int i = 1; i<= n; i++) if((s/i < n && s%i==0) || s-i <=n) {cout << "2"; return 0;}
      int temp = s;
      int finals;
      for(int i = 1; i <= n; i++){
            temp = s;
            finals = 0;
            if(temp%n == 0){
            while(temp%n == 0) {temp/=n; finals++;}}
            if(temp == 1) {temp = 0; }
            while(temp > 0)
            {
                  if(sqrt(temp) < n ){finals+=2; temp = 0; break;}
                  else if(temp < n) {finals++; temp = 0; break;}
                  else if(temp < 2*n) {finals+=2; temp = 0; break;}
                  else{
                  if(!checkprime(temp) && temp != division(temp) && division(temp) != 1) {temp /= division(temp); finals++;}
                  else {temp-=i; finals++;}
                  }
            }
            if(finals <=final) final = finals;
      }


      cout << final;
      return 0;
}
