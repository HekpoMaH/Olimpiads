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
    int elm;
    int left_border, right_border;
    indexed_tree *left, *right;
}*root;

int lists[ 1005 ];
int n;

void create( indexed_tree *&tr, int l_b, int r_b )
{
    //cout << l_b << " " << r_b << endl;
    tr = new indexed_tree;
    tr -> elm;
    tr -> left_border = l_b;
    tr -> right_border = r_b;
    tr -> left = NULL;
    tr -> right = NULL;
    
    if ( l_b == r_b ) tr -> elm = lists[ l_b ];
    if ( r_b - l_b > 0 )
    {
        create( tr -> left, l_b, ( l_b + r_b ) / 2 );
        create( tr -> right, ( l_b + r_b ) / 2 + 1, r_b );
    }    
}

void kld( indexed_tree *&tr )
{
    cout << tr -> left_border << " " << tr -> right_border << " " << tr -> elm << endl;
    if ( tr -> left != NULL ) kld( tr -> left );
    if ( tr -> right != NULL ) kld( tr -> right );
}

int sum_el( indexed_tree *tr )
{
    if ( tr -> left_border == tr -> right_border ) return tr -> elm;
    tr -> elm = sum_el( tr -> left ) + sum_el( tr -> right );
    return tr -> elm;
}
int main()
{
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> lists[ i ];
    
    create( root, 0, n - 1 );
    kld( root );
    cout << sum_el( root ) << endl;
        SP;
	return 0;
}
