#include <iostream>
#include <string>

#define ll long long

using namespace std;

string str;

ll dp[32][32][2];
ll numb[32];
int sza, szb;
char oper[32];

void scan(){
    cin >> str;
}

ll f ( int l, int r, int p ){
    if ( dp[l][r][p] != -1 ) return dp[l][r][p];
    if ( l == r ) return dp[l][r][p] = numb[l];

    for ( int i = l; i < r; ++ i ){
        for ( int l1 = 0; l1 < 2; ++l1 )
            for ( int l2 = 0; l2 < 2; ++l2 ){
                ll left = f ( l, i, l1 ), right = f ( i + 1, r, l2 ), all;
                    if ( oper[i] == '+' ) all = left + right;
                        else if ( oper[i] == '-' ) all = left - right;
                            else all = left * right;
                    if ( dp[l][r][p] == -1 ) dp[l][r][p] = all;
                    else if ( !p ){
                        if ( dp[l][r][p] > all ) dp[l][r][p] = all;
                    }
                    else {
                        if ( dp[l][r][p] < all ) dp[l][r][p] = all;
                    }
            }
    }

    return dp[l][r][p];
}
void solve(){
    for ( int i = 0; i < str.size(); ++i )
        if ( i & 1 )
            oper[ szb++ ] = str[i];
        else
            numb[ sza++ ] = str[i] - '0';
/*
    for ( int i = 0; i < szb; ++i)
        cout << oper[i] << " ";
    cout << endl;

    for ( int i = 0; i < sza; ++i)
        cout << numb[i] << " "; cout << endl;*/

    for ( int i = 0; i < 32; ++i ) for ( int j = 0; j < 32; ++j )
        dp[i][j][0] = dp[i][j][1] = -1;
    cout << f ( 0, sza - 1, 0 ) << endl;
}
int main(){
    scan();
    solve();
}
