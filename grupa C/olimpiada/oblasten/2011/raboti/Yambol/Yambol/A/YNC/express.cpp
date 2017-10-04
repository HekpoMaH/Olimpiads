#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char ex[32];

bool smi[32][32], smx[32][32];
long long mi[32][32];
long long mx[32][32];

long long MIN( long long a, long long b )
{
    if ( a < b ) return a;
    return b;
}

long long MAX( long long a, long long b )
{
    if ( a > b ) return a;
    return b;
}

long long eval( int le )
{
    if ( ex[le+1] == '+' )
        return ( (long long)(ex[le]-'0') + (long long)(ex[le+2]-'0') );
    if ( ex[le+1] == '-' )
        return ( (long long)(ex[le]-'0') - (long long)(ex[le+2]-'0') );
    if ( ex[le+1] == '*' )
        return ( (long long)(ex[le]-'0') * (long long)(ex[le+2]-'0') );
    return 0LL;
}

long long gmx( int le, int ri );

long long gmi( int le, int ri )
{
    if ( smi[le][ri] != 0 )
        return mi[le][ri];
    if ( ri == le )
    {
        smi[le][ri] = 1;
        mi[le][ri] = (long long)( ex[le]-'0' );
        return mi[le][ri];
    }
    if ( ri == le + 2 )
    {
        smi[le][ri] = 1;
        mi[le][ri] = eval( le );
        return mi[le][ri];
    }
    int i;
    long long r = (1LL<<62);
    for ( i = le; i < ri; i = i + 2 )
    {
        if ( ex[i+1] == '+' )
        {
            r = MIN( r, gmi( le, i ) + gmi( i+2, ri ) );
        }
        else if ( ex[i+1] == '-' )
        {
            r = MIN( r, gmi( le, i ) - gmx( i+2, ri ) );
        }
        else if ( ex[i+1] == '*' )
        {
            r = MIN( r, gmi( le, i )*gmi( i+2, ri ) );
            r = MIN( r, gmi( le, i )*gmx( i+2, ri ) );
            r = MIN( r, gmx( le, i )*gmi( i+2, ri ) );
            r = MIN( r, gmx( le, i )*gmx( i+2, ri ) );
        }
    }
    smi[le][ri] = 1;
    mi[le][ri] = r;
    return mi[le][ri];
}

long long gmx( int le, int ri )
{
    if ( smx[le][ri] != 0 )
        return mx[le][ri];
    if ( ri == le )
    {
        smx[le][ri] = 1;
        mx[le][ri] = (long long)(ex[le]-'0');
        return mx[le][ri];
    }
    if ( ri == le + 2 )
    {
        smx[le][ri] = 1;
        mx[le][ri] = eval( le );
        return mx[le][ri];
    }
    int i;
    long long r = -(1LL<<62);
    for ( i = le; i < ri; i = i + 2 )
    {
        if ( ex[i+1] == '+' )
        {
            r = MAX( r, gmx( le, i ) + gmx( i+2, ri ) );
        }
        else if ( ex[i+1] == '-' )
        {
            r = MAX( r, gmx( le, i ) - gmi( i+2, ri ) );
        }
        else if ( ex[i+1] == '*' )
        {
            r = MAX( r, gmi( le, i )*gmi( i+2, ri ) );
            r = MAX( r, gmi( le, i )*gmx( i+2, ri ) );
            r = MAX( r, gmx( le, i )*gmi( i+2, ri ) );
            r = MAX( r, gmx( le, i )*gmx( i+2, ri ) );
        }
    }
    smx[le][ri] = 1;
    mx[le][ri] = r;
    return mx[le][ri];
}

int main()
{
    int i, j, k;
    memset( smi, 0, sizeof( smi ) );
    memset( smx, 0, sizeof( smx ) );
    scanf( "%s", ex );
    cout << gmi( 0, strlen( ex ) -1 ) << endl;
//    printf( "%I64d\n", gmi( 0, strlen( ex ) -1 ) );
    return 0;
}
