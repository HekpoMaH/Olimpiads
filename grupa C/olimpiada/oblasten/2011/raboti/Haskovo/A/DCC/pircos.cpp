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
    set< long long int > s;
    set< long long int > :: iterator it;

    int n;
    cin >> n;

    long long int a;
    bool yes;

    for ( int i = 0; i < n; i++ )
    {
        cin >> a;
        yes = true;

        for ( it = s.begin(); it != s.end(); it++ )
        {
            if ( *it == a )
            {
                yes = false;
                break;
            }
        }

        if ( !yes ) s.erase( a );
        else s.insert( a );

    }
    it = s.begin();
    cout << *it << " ";
    it++;
    cout << *it << endl;
//    cout << *s.begin() << " " << *s.end() << endl;
    return 0;
}