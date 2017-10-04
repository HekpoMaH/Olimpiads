/*
TASK:diet
LANG:C++
*/
#include <iostream>
using namespace std;
int x, y, z;
void scan(){
    cin >> x >> y >> z;
}
void solve(){
    int sum = 10 * x + 20 * y + 30 * z;
    sum = (sum / 60) * 60;
    cout << sum / 60 << " ";
    int mn = min(x, min(y, z));
    x -= mn;
    y -= mn;
    z -= mn;
    int br = mn, ans = 0;
    while ( br != sum / 60 ){ 
        if ( x == 0 ){
            if ( y > z ){++ans;
                y -= 1;
                x += 2;
            }
            else if ( y <= z ){++ans;
                z -= 1;
                y += 1;
                x += 1;
            }
        }
        if ( y == 0 ){
            if ( x - 2 > z - 1 ){
                x -= 2;
                y += 1;
            }
            else if ( x - 2 <= z - 1 ){++ans;
                z -= 1;
                ++x;
                ++y;
            }
        }
        if ( z == 0 ){
            if ( x - 3 > y - 2 ){
                x -= 3;
                ++z;
            }
            else if ( x - 3 <= y - 2 ){++ans;
                y -= 2;
                ++x;
                ++z;
            }
        } --x;--y;--z;++br;
    }
    cout << ans << endl;
}
int main(){
    scan();
    solve();
}
