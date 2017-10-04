#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>

using namespace std;

int N;

char c[10001];

int e[10001];

//stack <int> s;
int s[10001], size;

int main () {
    scanf ("%s\n", &c);

    N = strlen (c);

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        e[i] = e[i - 1];
        if (c[i - 1] == '_') continue;

        if (c[i - 1] == '\\') //s.push (i);
            s[size++] = i;
        else {
            //if (s.empty()) {
            if (!size) {
                continue;
            }
            //ans += i - s.top();
            ans += i - s[size - 1];
            //e[i] = e[s.top() - 1] + 1;
            e[i] = e[s[size - 1] - 1] + 1;
            //s.pop();
            size--;
        }
    }
    printf ("%d %d\n", e[N], ans);
}
