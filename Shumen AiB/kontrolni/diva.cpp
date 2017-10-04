
#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const int MAXL = 13, SQRT = 1e6;

ll n, m;

pii d[MAXL][SQRT];

int rem10[MAXL];

int main() {    
   
    cin >> n >> m;
    

    ll s = (int) sqrt(n);

    vector <int> vn;
    ll tmp = n;
    while (tmp) {
        vn.puba(tmp % 10);
        tmp /= 10;
    }

    if (szof(vn) == 1) {
        if (n % m == 0) {
            cout << n << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (m > s) {        
        ll ans = -1;
        int best = 100;
        for (int i = 0; ; ++i) {
            ll tmp = m * i;
            vector <int> v;
            while (tmp) {                
                v.puba(tmp % 10);
                tmp /= 10;
            }
            if (szof(v) > szof(vn)) {
                break;
            }
            if (szof(v) < szof(vn)) {
                continue;
            }
            int bal = 0;
            for (int j = 0; j < szof(v); ++j) {
                if (v[j] != vn[j]) {
                    ++bal;
                }
            }
            if (best > bal) {
                best = bal;
                ans = i * m;
            }
        }
        cout << ans << endl;
    } else {        
        rem10[0] = 1;
        for (int i = 1; i < MAXL; ++i) {
            rem10[i] = rem10[i - 1] * 10 % m;
        }
        
        
        for (int i = 0; i < MAXL; ++i) {
            for (int j = 0; j < SQRT; ++j) {
                d[i][j] = mapa(100, -1);
            }
        }
        d[0][0] = mapa(0, -1);
        for (int i = 1; i <= szof(vn); ++i) {            
            int start = 0;
            if (i == szof(vn)) {
                start = 1;
            }
            int rem = rem10[i - 1];
            for (int j = start; j < 10; ++j) {
                for (int k = 0; k < m; ++k) {
                    d[i][(k + j * rem) % m] = min(d[i][(k + j * rem) % m], mapa(d[i - 1][k].ff + (vn[i - 1] != j), j));
                }
            }
            /*
            cerr << "i: " << i << endl;
            for (int j = 0; j < m; ++j) {
                cerr << d[i][j].ff << " ";
            }
            cerr << endl;
            */
        }
        if (d[szof(vn)][0].ff == 100) {
            cout << -1 << endl;
            return 0;
        }
        vector <int> ans;        
        int rem = 0;
        for (int i = szof(vn); i > 0; --i) {
            int now = rem10[i - 1];
            ans.puba(d[i][rem].ss);
            rem = (rem - now * d[i][rem].ss) % m;
            if (rem < 0) {
                rem += m;
            }
        }
                
        for (int i = 0; i < szof(ans); ++i) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}                                    
