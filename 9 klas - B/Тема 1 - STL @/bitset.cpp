#include <iostream>
using namespace std;
#include <bitset>
int main() {
  const bitset<12> mask(2731);
  cout << "mask =      " << mask << endl;

  bitset<12> x;

  cout << "Enter a 12-bit bitset in binary: " << flush;
  if (cin >> x) {
    cout << "x =        " << x << endl;
    cout << "As ulong:  " << x.to_ulong() << endl;
    cout << "And with mask: " << (x & mask) << endl;
    cout << "Or with mask:  " << (x | mask) << endl;
  }
}
