#include<iostream>
using namespace std;
int main() {
      int N, a=0, b, br=0, malko=21;
      cin>>N;
      while(a<N) {
           cin>>b;
           br=br+b;
           if (b<malko) malko=b;
           a++;   
      }
      cout << br-malko+1 << endl;
      return 0;    
} 
