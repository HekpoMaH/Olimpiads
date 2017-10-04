#include<iostream>
using namespace std;

int visochina[2][100], shit[2][100];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n ; i ++) {
        cin >> visochina[0][i];
    }
    for (int i = 0; i < n ; i ++) {
        cin >> visochina[1][i];
    }
    for (int i = 0; i < n ; i ++) {
        shit[0][i] = visochina[0][i] + visochina[1][i];
        shit[1][i] = visochina[0][i] + visochina[1][n - i - 1];
    }
    int min = 500, min1 = 500;
    for (int i = 0 ; i < n ; i ++) {
        if (shit[0][i] < min) {
            min = shit[0][i];
        }
        if (shit[1][i] < min1) {
            min1 = shit[1][i];
        }
    }
    if (min > min1) {
        cout << min << endl;
    } else {
        cout << min1 << endl;
    }
    return 0;
}
