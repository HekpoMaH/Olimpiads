#include <iostream>
#include <string>
#define MAXN 900
#define MAXM 1000

using namespace std;

int p[MAXN] = {0}, n, uni[MAXM], prev, now;
string st[MAXN][MAXN];


void pfill(string a)
{
     int k = 0, i, asize = a.size();
     
     p[0] = p[1] = 0;
     
     for (i = 2; i < asize; ++i) {
         while (k != 0 && a[i - 1] != a[k])
               k = p[k];
         if (a[i - 1] == a[k]) k++;
         p[i] = k;
     }
     return;
}     

bool search(string where, string what)
{
     int i, j, size1 = where.size(), size2 = what.size(), k;
     
     for (i = 0; i < size1; ++i) {
         k = 0;
         j = i;
         while (k < size2 && j < size1 && where[j] == what[k]){
               k++, j++;
               while (k < size2 && where[j] != what[k] && k != 0) {
                     k = p[k];
               }
         }
         if (k == size2) {
               now = i;
               return true;
         }
     }
     return false;
}

int main()
{
    int m, i, j, k, t, r;
    char a[MAXN][MAXN];
    string st_temp;
    
    cin >> m >> n;
    
    r = n/2 + n%2;
    for (k = 0; k < m; ++k) {
        for (i = 0; i < n; ++i)
                cin >> a[i];
        for (t = 0; t < r; ++t) {
            st[k][t].clear();
            i = t;
            for (j = t; j < n - t; ++j)
                st[k][t] += a[i][j];
            j = n - t - 1;
            for (i = t + 1; i < n - t; ++i)
                st[k][t] += a[i][j];
            i = n - t - 1;
            for (j -= 1; j >= t; --j)
                st[k][t] += a[i][j];
            j = t;
            for (i -= 1; i >= t + 1; --i)
                st[k][t] += a[i][j];
            st[k][t] += st[k][t];
        }
    }
    
    for (i = 0; i < m; ++i)
        uni[i] = 1;
    int br = 0;
    for (i = 0; i < m; ++i)
        for (j = i + 1; j < m; ++j) {
            if (!uni[j]) continue;
            br = 0;
            prev = -1;
            
            for (k = 0; k < r; ++k) {
                st_temp = st[j][k].substr(0, st[i][k].size()/2);
                pfill(st_temp);
                
                
                if (search(st[i][k], st_temp)) {
                                      if (r == 1) br++;
                                      else if (prev == -1) prev = now;
                                      else if (prev == now) br++;
                }
            if (br == r) uni[j] = 0;
            }
        }
            
    br = 0;
    for (i = 0; i < m; ++i)
        if (uni[i]) ++br;
    
    cout << br << "\n";
    
    return 0;
}
    
