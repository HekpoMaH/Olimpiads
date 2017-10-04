# include <iostream>

using namespace std;

int main () {

    long s;
    int n;

    cin >> s >> n;

    int x;

    cin >> x;

    int max = x;

    for ( int i = 1 ; i < n ; i ++ ) {

         cin >> x;

         if ( max < x )
              max = x;

    }

    int t1 = s/max, t2 = 0;

    if ( s%max )
         t2 ++;

    cout << t1 + t2 << endl;

    return 0;

  }