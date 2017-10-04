//FIB
#include<iostream>
using namespace std;
int main() {
    int a, b=1, pred_fib=1, fib=1;
    cin>>a;
    for (int i=0;i<=a-3;i++) {
        b=pred_fib+fib;
        pred_fib=fib;
        fib=b;
    }
    cout << b << endl;
    return 0;
}
