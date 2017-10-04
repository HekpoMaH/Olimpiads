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

int main()
{
    pair< int, int > box[ 10 ];
    for ( int i = 0; i < 6; i++ ) 
    {
        cin >> box[ i ].x >> box[ i ].y;
        if ( box[ i ].x > box[ i ].y ) swap( box[ i ].x, box[ i ].y );
    }
    sort( box, box + 6 );
    
    bool isBox = false;
    //sys sledva6tiq if proverqvame dali stranite na ploskostite si syotvetstvat
    if ( box[ 0 ].x == box[ 1 ].x && box[ 0 ].x == box[ 2 ].x && box[ 0 ].x == box[ 3 ].x &&
         box[ 0 ].y == box[ 1 ].y && box[ 0 ].y == box[ 4 ].x && box[ 0 ].y == box[ 5 ].x &&
         box[ 2 ].y == box[ 3 ].y && box[ 2 ].y == box[ 4 ].y && box[ 2 ].y == box[ 5 ].y ) isBox = true;
    if ( isBox ) cout << box[ 0 ].x * box[ 0 ].y * box[ 2 ].y << endl;//ako si syotvetstvat to togava imame kutiq
    else cout << 0 << endl;//ako li ne zna4i nqmame kutiq
        SP;
	return 0;
}
