#include <iostream>

using namespace std;

int main() {

int S, N, ost, del;
cin >> S >> N;
int ceni[N];
for (int i=0;i<N;i++) {
    cin >> ceni[i];
}

sort(ceni,ceni+N);

cout << S << endl;

return 0;
}
