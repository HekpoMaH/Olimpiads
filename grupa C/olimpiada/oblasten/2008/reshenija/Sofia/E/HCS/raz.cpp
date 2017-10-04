#include<iostream>
using namespace std;
int main() {
    int N, del1, del2, tek_del1, tek_del2, tek_raz, raz;
    cin>>N;
    for (int i=1;i<=N;i++) {
        if (N%i==0) {
           tek_del1 = i;
           tek_del2 = N/i;
           if (tek_del1>tek_del2) {
              tek_raz=del1-del2;   
           }
           if (tek_del1<tek_del2) {
              tek_raz=del2-del1;   
           }
           if (tek_del1==tek_del2) {raz=0;del1=tek_del1;del2=del1;}
           if (tek_raz<raz) {
              del1 = i;
              del2 = N/i;
              if (del1>del2) {
                 raz=del1-del2;   
                 }
              if (del1<del2) {
                 raz=del2-del1;   
              }
           }   
        }    
    }
    if (del1<del2) {
       cout << del1 << " " << del2;
    }
    if (del1>del2) {
       cout << del2 << " " << del1;
    }
    if (del1==del2) {
       cout << del1 << " " << del1;
    }
    cout << endl;
    return 0;
}
