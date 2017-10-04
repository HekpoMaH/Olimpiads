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

int used[ 20 ];
int main()
{
    int n;
    cin >> n;
    if ( n == 90 ) 
    {
        cout << 12345678990LL << endl;
        return 0;
    }
    lli part1;
    lli temp;
    
    if ( n % 10 == 0 )
    {
        if ( n % 3 == 0 ) part1 = 12334000000LL;
        else part1 = 11234000000LL;
        for ( int i = 56789; i <= 98765; i++ )
        {
            for ( int j = 0; j < 20; j++ ) used[ j ] = 0;
            temp = i;
            while ( temp > 0 )
            {
                if ( temp % 10 < 5 ) break;
                if ( used[ temp % 10 ] == 1 ) break;
                used[ temp % 10 ] = 1;
                temp /= 10;
            }
            if ( temp == 0 && ( part1 + 10 * i ) % n == 0 )
            {
                cout << part1 + 10 * i << endl;SP;
                return 0;
            }
        }
    }
    if ( n % 9 == 0 )
    {
        part1 = 10234000000LL;
        for ( int i = 567899; i <= 998765; i++ )
        {
            for ( int j = 0; j < 20; j++ ) used[ j ] = 0;
            temp = i;
            while ( temp > 0 )
            {
                if ( temp % 10 < 5 ) break;
                if ( temp % 10 == 9 && used[ temp % 10 ] > 1 ) break;
                if ( used[ temp % 10 ] > 0 ) break;
                used[ temp % 10 ] = 1;
                temp /= 10;
            }
            if ( temp == 0 && ( part1 + i ) % n == 0 )
            {
                cout << part1 + i << endl;SP;
                return 0;
            }
        }
    }
    if ( n % 3 == 0 )part1 = 10233000000LL;
    else part1 = 10123000000LL;
    for ( int i = 456789; i <= 987654; i++ )
    {
        for ( int j = 0; j < 20; j++ ) used[ j ] = 0;
        temp = i;
        //cout << part1 << endl;
       // cout << part1 + i << endl;SP;
        while ( temp > 0 )
        {
            if ( temp % 10 < 4 ) break;
            if ( used[ temp % 10 ] > 0 ) break;
            used[ temp % 10 ] = 1;
            temp /= 10;
        }
        if ( temp == 0 && ( part1 + i ) % n == 0 )
        {
            cout << part1 + i << endl;SP;
            return 0;
        }
    }
        SP;
	return 0;
}
