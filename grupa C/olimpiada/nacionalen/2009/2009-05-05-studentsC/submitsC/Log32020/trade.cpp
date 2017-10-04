/*
TASK: trade
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;
int cnt_towns;
pair<int, double> ocenki[100000][2];
double ans[100000];
bool ansrd[100000];
bool first[100000];
void add(int v1, int v2, double weighta) {
    ocenki[v1][(first[v1] ? 0 : 1)].first = v2;
    ocenki[v1][(first[v1] ? 0 : 1)].second = weighta;
    first[v1] = 1;
}
bool direct(int v1, int v2) {
    if (ocenki[v1][0].first == v2 || ocenki[v1][1].first == v2) {
        return 1;
    }
    return 0;
}
double from_to(int v1, int v2) {
    if (ocenki[v1][0].first == v2) {
        return ocenki[v1][0].second;
    }
    return ocenki[v1][1].second;
}
int main() {
    scanf("%d", &cnt_towns);
    int v1, v2;
    double weight;
    for (int i = 0;i < cnt_towns; ++i) {
        scanf("%d %d", &v1, &v2);
        cin >> weight;
        v1--; v2--;
        add(v1, v2, weight);
        add(v2, v1, weight);
    }
    //for (int i = 0;i < cnt_towns; ++i) {
    //    printf(" %d -> %d %.2f, %d %.2f\n", i, ocenki[i][0].first, ocenki[i][0].second, ocenki[i][1].first, ocenki[i][1].second);
    //}
    double razl;
    double weig1, weig2;
    for (int i = 0;i < cnt_towns; ++i) {
        if (direct(ocenki[i][0].first, ocenki[i][1].first) && !ansrd[i]) {
            v1 = ocenki[i][0].first;
            v2 = ocenki[i][1].first;
            weig1 = ocenki[i][0].second;
            weig2 = ocenki[i][1].second;
            //printf("%d %d %d\n", i, v1, v2);
            razl = 2 * (weig2 - weig1);
            //printf("%.2f\n", razl);
            ans[v1] = ((from_to(v1, v2) * 2) - razl) / 2;
            ans[i] = (weig1 * 2) - ans[v1];
            ans[v2] = (from_to(v1, v2) * 2) - ans[v1];
            ansrd[i] = 1;
            ansrd[v1] = 1;
            ansrd[v2] = 1;
            //puts("");
        }
    }
    bool posible = 1;
    for (int i = 0;i < cnt_towns; ++i) {
        posible *= ansrd[i];
        //printf(" %.2f", ans[i]);
    }
    //puts("");
    if (posible) {
        printf("%.2f", ans[0]);
        for (int i = 1;i < cnt_towns; ++i) {
            printf(" %.2f", ans[i]);
        }
        puts("");
    } else {
        puts("impossible");
    }
    return 0;
}
