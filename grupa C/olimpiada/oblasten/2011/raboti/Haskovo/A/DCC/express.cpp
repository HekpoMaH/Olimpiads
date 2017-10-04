#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
    string niz;
    cin >> niz;
    stack< long long int > dig, ndig;
    stack< char > znak, nznak;

    int sz = ( int )niz.size();
    long long int d;
    int j;

    for ( int i = 0; i < sz; i++ )
    {
        if ( niz[ i ] >= '0' && niz[ i ] <= '9' )
        {
            d = 0;
            j = i;
            while ( niz[ j ] >= '0' && niz[ j ] <= '9' && j < sz )
            {
                d = d * 10 + ( niz[ j ] - '0' );
                j++;
            }
            dig.push( d );
        }
        else znak.push( niz[ i ] );
    }
    long long int p, q;
    char z;

    while ( !znak.empty() )
    {
        z = znak.top();
        znak.pop();
        if ( z == '*' )
        {
            p = dig.top();
            dig.pop();
            q = dig.top();
            dig.pop();
            dig.push( p * q );
        }
        else
        {
            nznak.push( z );
            ndig.push( dig.top() );
            dig.pop();
        }
    }
    ndig.push( dig.top() );
    dig.pop();

    d = 0;

    while ( !nznak.empty() )
    {
        z = nznak.top();
        nznak.pop();
        if ( z == '+' )
        {
            p = ndig.top();
            ndig.pop();
            q = ndig.top();
            ndig.pop();
            ndig.push( p + q );
        }
        else
        {
            p = ndig.top();
            ndig.pop();
            q = ndig.top();
            ndig.pop();
            ndig.push( p - q );
        }
    }

    cout << ndig.top() << endl;
    return 0;
}