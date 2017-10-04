/*
Contest:
Task:
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <set>

#define SP system("pause");
#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

pair< int, int > pt[ 100005 ];
 
int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n * 2; i += 2 )
    {
        cin >> pt[ i ].x;//vyvejdame na4alo na otse4ka
        pt[ i ].y = 1;//i go otbelqzvame kato na4alo
        cin >> pt[ i + 1 ].x;//vyvejdame krai na otse4ka
        pt[ i + 1 ].y = -1;//i go otbelqzvame kato krai
    }
    
    sort( pt, pt + 2 * n );//sortirame koordinatite i po dvata kriteriq
    n *= 2;
    int d = 0;
    int mx = 0;//max debelina
    
    for ( int i = 0; i < n; i++ )//namirame max debelina kato suma 
                                //max debelina 6te e kogato se polu4i max suma ot na4alni i kraini to4ki
    {
        d += pt[ i ].y;
        if ( d > mx ) mx = d;
    }    
    int l = pt[ 0 ].x - 1;
    d = 0;
    int ans = 0;
    for ( int i = 0; i < n; i++ )
    {
        d += pt[ i ].y;
        if ( d == mx )//ako sme v u4astyk s max debelina 
        {
            ans += ( pt[ i + 1 ].x - pt[ i ].x + 1 );//v otgovora dobavqme dyljinata mu
            if ( pt[ i ].x == l ) ans--;//ako predi sme izpolzvali tazi to4ka namalqme s 1 otgovora za da ne q broim pak
            l = pt[ i + 1 ].x;//i zadavame nova posledno izpolzvana to4ka
        }
    }
    cout << ans << endl;
        SP;
	return 0;
}
