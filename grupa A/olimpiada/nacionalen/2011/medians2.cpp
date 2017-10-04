#include <iostream>
#include <stdio.h>
#include <set>
#include <math.h>

#define eps 1e-9

using namespace std;

multiset <double> s;
int N;

multiset <double> :: iterator iter;

char cmp (double a, double b) {
    if (fabs (a - b) < eps) return 0;
    if (a - b < eps) return -1;
    return 1;
}
void insert (double A) {
    if (s.empty()) {
        s.insert (A);
        iter = s.begin();
        return;
    }
    s.insert (A);
    if (cmp (A, (*iter)) < 0) {
        if ((int)s.size() % 2 == 0)
            iter--;
    } else {
        if ((int)s.size() % 2 == 1)
            iter++;
    }
}

void print () {
    if (((int)s.size()) &  1)
        printf ("%.3lf\n", *iter);
    else {
        multiset <double> :: iterator iter2;
        iter2 = iter;
        iter2++;

        printf ("%.3lf\n", (double)((*iter) + (*iter2))/2.0);
    }
}
int main () {
    //freopen ("medians.in", "r", stdin);

    scanf ("%d\n", &N);
   // cin >> N;
    char op;
    double A;
    iter = s.begin();
    for (int i = 0; i < N; i++) {
       // cin >> op;
        scanf ("%c", &op);
        if (op == 'A') {
           //cin >> A;
           scanf (" %lf\n", &A);
           insert (A);
        } else {
            scanf ("%c", &op);
            print();
        }
    }
}
