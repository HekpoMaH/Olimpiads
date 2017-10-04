
/*
ID: espr1t
LANG: C++
TASK: SilverGold
KEYWORDS: Medium, Sorting, Greedy, Binary Search
*/

#include <cstdio>
#include <algorithm>
FILE* in; FILE* out;

const int MAX = 128;
const int BINARY_ITERS = 100;

struct Bar {
    int weight;
    double ratio;
    bool operator < (const Bar& r) const {return ratio < r.ratio;}
};

int n;
Bar a[MAX];

int main(void) {
    in = stdin; out = stdout;
//    in = fopen("SilverGold.in", "rt"); out = fopen("SilverGold.out", "wt");
    
    fscanf(in, "%d", &n);
    double weight1 = 0.0, weight2 = 0.0;
    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &a[i].weight);
        int gold, silver;
        fscanf(in, "%d %d", &gold, &silver);
        a[i].ratio = (double)gold / (double)(gold + silver);
        weight1 += a[i].weight * a[i].ratio;
        weight2 += a[i].weight * (1.0 - a[i].ratio);
    }
    if (weight1 < weight2) {
       printf("INV\n");
        for (int i = 0; i < n; i++)
            a[i].ratio = 1.0 - a[i].ratio;
    }
    std::sort(a, a + n);
    //for(int i=0;i<n;i++)printf("%lf ",a[i].ratio);
    weight1 = 0.0; weight2 = 0.0;
    for (int i = 0; i < n; i++) {
        weight1 += a[i].weight * a[i].ratio;
        weight2 += a[i].weight * (1.0 - a[i].ratio);
        if (weight2 < weight1) {
           printf("%lf %lf\n",weight1,weight2);
            weight1 -= a[i].weight * a[i].ratio;
            weight2 -= a[i].weight * (1.0 - a[i].ratio);
            
            double left = 0.0, right = 1.0;
            for (int iter = 0; iter < BINARY_ITERS; iter++) {
                double mid = (left + right) / 2.0;
                double w1 = weight1 + mid * a[i].weight * a[i].ratio;
                double w2 = weight2 + mid * a[i].weight * (1.0 - a[i].ratio);
                if (w1 < w2) left = mid;
                else right = mid;
            }
            weight1 += right * a[i].weight * a[i].ratio;
            weight2 += right * a[i].weight * (1.0 - a[i].ratio);
            break;
        }
    }
    fprintf(out, "%.6lf\n", weight1 + weight2);
    return 0;
}
