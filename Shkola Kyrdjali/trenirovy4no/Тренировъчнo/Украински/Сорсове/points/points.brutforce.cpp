#include <cstdio>
#include <fstream>

using namespace std;

const int maxN = 100000;

int x[maxN], y[maxN];

#define SQR(x) ((x) * (x))

int main() {
     int n,i,j;
     long long ans;
     FILE *ifs = fopen("points.dat", "r");
     ofstream ofs("points.sol");
     
     fscanf(ifs,"%d",&n);
     for(i = 0; i < n; ++i)fscanf(ifs, "%d%d", &x[i], &y[i]);
     
     ans = 0;
     for(i = 0; i < n; ++i)
          for(j = 0; j < i; ++j) 
               ans += SQR(x[i] - x[j]) + SQR(y[i] - y[j]);

     ofs<<ans<<endl;

     fclose(ifs);
     return 0;
}
