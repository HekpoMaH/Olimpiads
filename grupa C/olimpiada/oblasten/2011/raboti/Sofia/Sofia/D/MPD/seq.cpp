#include<iostream>
using namespace std;
int main () {
    double price, cpyprice, br = 1, maxbr = 0;
    cin >> price;
    while (price != 0) {
        cpyprice = price;
        cin >> price;
        if (cpyprice <= price) {
            br ++;
        } else {
            if (br > maxbr) {
                maxbr = br;
            }
            br = 1;
        }
    }
    cout << maxbr << endl;
    return 0;
}
