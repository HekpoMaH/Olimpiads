#include <iostream>
using namespace std;
int m[1000], c[1000];
int N, M;
int calculate( int t, int next_i )
{
    int maxst = 0, st;
    for ( int i = next_i; i < N; i++ )
        if ( t - m[i] >= 0 )
        {
            st = calculate( t - m[i], i + 1 ) + c[i];
            if (st>maxst) maxst = st;

        }
   return maxst;
}
int main()
{
    cin >> M >> N;
    for ( int i = 0; i < N; i++ ) cin >> m[i] >> c[i];
    cout << calculate( M, 0 ) << endl;
	return 0;
}

/*
Вход:
7
8
3 5
7 3
6 9
1 1
2 1
4 2
5 5
5 2
Изход:10
*/

