#include <iostream>
#include <cstring>
char duma[100];
using namespace std;
int main () {
    int n, br = 0, br1 = 0, br2 = 0, br3 = 0, br4 = 0, br5 = 0;
    char a;
    cin >> n >> a;
    for (int i = 0; i < n ; i ++) {
        cin >> duma;
        if (duma[0] == a || duma[0] == (a - 'a') + 'A') {
            br ++;
        }
        cin >> duma;
        for (int j = 0; j < strlen(duma); j ++) {
            if (duma[j] == a || duma[j] == (a - 'a') + 'A') {
                br4 ++;
            }
        }
        if (br4 != 0) {
            br1 ++;
            br4 = 0;
        }
        cin >> duma;
        for (int d = 0; d < strlen(duma); d ++) {
            if (duma[d] == a || duma[d] == (a - 'a') + 'A') {
                br5 ++;
            }
        }
        if (br5 > 1) {
            br2 ++;
            br5 = 0;
        }
        cin >> duma;
        if (duma[strlen(duma) - 1] == a || duma[strlen(duma) - 1] == (a - 'a') + 'A') {
            br3 ++;
        }
    }
    cout << br << " " << br1 << " " << br2 << " " << br3 << endl;
    return 0;
}
