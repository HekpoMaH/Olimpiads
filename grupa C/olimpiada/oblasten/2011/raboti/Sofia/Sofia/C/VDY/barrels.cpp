#include <iostream>

using namespace std;

int main() {
    int s, n, barcnt=0, s1=0;
    cin>>s>>n;
    //mn_typo_reshenie;
    long a[n];
    for(int i = 0; i<n; i++) cin>>a[i];
    while(s1<=s) {
      for(int i = 0; i<n; i++)
      {
        s1 = s1 + a[i];
        barcnt++;
        if(s1 == s) break;
        }
      }
      cout<<barcnt<<endl;
  }