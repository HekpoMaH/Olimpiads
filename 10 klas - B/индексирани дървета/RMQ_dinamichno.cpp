// Dinamichno RMQ 
//komanda 1 za min elenemt v [ i; j ]
//komanda 2 za promqna na i-tiq elemnt sys stoinost j
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<fstream>
#include<limits>

#define x first
#define y second

using namespace std;

typedef long long int LL;

struct indexed_tree
{
    int min_in_interval;
    int left_border, right_border;
    indexed_tree *left, *right;
}*root;

int lists[ 10005 ];

void create( indexed_tree *&tr, int l_b, int r_b )
{
    //cout << l_b << " " << r_b << endl;
    tr = new indexed_tree;
    tr -> min_in_interval = 99999;
    tr -> left_border = l_b;
    tr -> right_border = r_b;
    tr -> left = NULL;
    tr -> right = NULL;
    
    if ( l_b == r_b ) tr -> min_in_interval = lists[ l_b ];
    if ( r_b - l_b > 0 )
    {
        create( tr -> left, l_b, ( l_b + r_b ) / 2 );
        create( tr -> right, ( l_b + r_b ) / 2 + 1, r_b );
    }    
}

pair< int, int > find_min( indexed_tree *tr, int i, int j )
{
    if ( tr -> left_border == tr -> right_border ) return make_pair( tr -> min_in_interval, tr -> left_border );
    int mid = ( tr -> left_border + tr -> right_border ) / 2;
    if ( i <= mid && mid < j )
    {
        pair< int, int > f, s;
        f = find_min( tr -> left, i, j );
        s = find_min( tr -> right, i, j );
        return ( f.x < s.x ) ? f : s;
    }
    else if ( i <= mid && j <= mid )
    {
        return find_min( tr -> left, i, j );
    }
    return find_min( tr -> right, i, j );
}

void change( indexed_tree *&tr, int k, int p )
{
    if ( tr -> left_border == tr -> right_border && tr -> left_border == k ) 
    {
        tr -> min_in_interval = p;
        return;
    }
    int mid = ( tr -> left_border + tr -> right_border ) / 2;
    if ( k <= mid ) change( tr -> left, k, p );
    else change( tr -> right, k, p );
}
int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> lists[ i ];
    
    create( root, 0, n - 1 );
    pair< int, int > a;
    int com, i, j;
    while ( cin >> com >> i >> j )
    {
        if ( com == 1 )
        {
            a = find_min( root, i, j );
            cout << a.x << " " << a.y << endl;
        }
        else 
        {
            change( root, i, j );
        }
    }
    system("pause");
    return 0;
}
