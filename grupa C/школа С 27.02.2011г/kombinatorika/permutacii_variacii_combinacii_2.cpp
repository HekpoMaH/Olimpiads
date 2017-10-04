#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
string s = "abcdefghijklmnopqrstuvwxyz";

void shuffle(int n, int k, int b) {
  if (b==k) {cout << s.substr(0,k) << endl; return;}
  for (int i=b; i<n; ++i) {
    swap(s[b],s[i]);
    shuffle(n,k,b+1);
    swap(s[b],s[i]);
  }
}

void perms(int n) {shuffle(n,n,0);}

void vars(int n, int k) {shuffle(n,k,0);}

void combs(int n, int k) {
  int i,j;
  static vector<int> ix(k+1);
  for (ix[0]=-1,i=1; i<=k; ++i) ix[i] = i;
  for (i=1; i;) {
    for (j=1; j<=k; ++j) cout << s[ix[j]-1];
    cout << endl;
    for (i=k; ix[i]==n-k+i; --i) ;
    ++ix[i];
    for (j=i+1; j<=k; ++j) ix[j] = 1+ix[j-1];
  }
}

int main() {
  int n,k;
  cout << "permutacii na ... bukvi: ";         cin >> n;       perms(n);
  cout << "variacii ot ... bukvi po ...: ";    cin >> n >> k;  vars(n,k);
  cout << "combinacii ot ... bukvi po ...: ";  cin >> n >> k;  combs(n,k);
  return 0;
}
