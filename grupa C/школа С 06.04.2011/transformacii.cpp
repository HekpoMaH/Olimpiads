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

string a, b;
int k, n;

int main()
{
    cin >> k >> a >> b;
    n = int( a.size() );
    
    int br = 0;
    int izmenenie;
    
    for ( int i = 0; i < n - k + 1; i++ )
    {
         izmenenie = ( 9 + b[ i ] - a[ i ] ) % 9;
         
         br += izmenenie;
         
         for ( int j = i; j < i + k; j++ )
         {
            a[ j ] = '1' + ( a[ j ] - '1' + izmenenie ) % 9;
         } 
    }
    if ( a == b ) cout << br << endl;
    else cout << 0 << endl;
        SP;
	return 0;
}
