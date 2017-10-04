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

struct indexed_tree
{
    int min_in_interval;
    int left_border, right_border;
    indexed_tree *left, *right;
}*root;

int lists[ 1005 ];
int n;

void create( indexed_tree *&tr, int l_b, int r_b )
{
    //cout << l_b << " " << r_b << endl;
    tr = new indexed_tree;
    tr -> min_in_interval = maxn;
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

void kld( indexed_tree *&tr )
{
    cout << tr -> left_border << " " << tr -> right_border << " " << tr -> min_in_interval << endl;
    if ( tr -> left != NULL ) kld( tr -> left );
    if ( tr -> right != NULL ) kld( tr -> right );
}

int min_el( indexed_tree *tr )
{
    if ( tr -> left_border == tr -> right_border ) return tr -> min_in_interval;
    return tr -> min_in_interval = min( min_el( tr -> left ), min_el( tr -> right ) );
}
int main()
{
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> lists[ i ];
    
    create( root, 0, n - 1 );
    kld( root );
    cout << min_el( root ) << endl;
        SP;
	return 0;
}
