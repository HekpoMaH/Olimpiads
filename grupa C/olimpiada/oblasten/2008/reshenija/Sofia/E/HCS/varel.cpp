#include<iostream>
using namespace std;
int main() {
      int V, K, N;
      char znak;    
      cin>>V>>K>>N;
      for (int i=0;i<N;i++) {
          cin>>znak;
          if (znak=='+') V=V+K;
          if (znak=='-') V=V-K;
      }
      cout << V << endl;
      return 0;    
} 
