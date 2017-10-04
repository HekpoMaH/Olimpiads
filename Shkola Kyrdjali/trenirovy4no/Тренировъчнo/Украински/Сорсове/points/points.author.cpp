#include <cstdio>
#include <fstream>

using namespace std;

const int maxN = 100000;

int x[maxN], y[maxN];

long long solve(int p[], int n) {
     long long sump = 0, sump2 = 0, ans = 0;
     int i;
     for(i = 0; i < n; ++i) {
          ans += (long long)i * p[i] * p[i] - 2 * p[i] * sump + sump2;
          sump += p[i];
          sump2 += p[i] * p[i];
     }
     return ans;
}

int main() {
     int n,i;
     FILE *ifs = fopen("points.dat","r");
     ofstream ofs("points.sol");
     
     fscanf(ifs, "%d", &n);
     for(i = 0; i < n; ++i)fscanf(ifs, "%d%d", &x[i], &y[i]);

     ofs << solve(x, n) + solve(y, n) << endl;
     
     fclose(ifs);
     return 0;
}
