#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct
{
  short x, y;
} points [ 12 ];
short n, n2, record = -1;

void Rec ( vector <short> way, short steps )
{
  if ( record >= 0 && steps >= record )
    return;
  if ( way.size() >= n )
  {
    record = steps;
    return;
  }
  for ( short i = 0, newsteps, x = points[ way.back() ].x, y = points[ way.back() ].y;   i < n2;   i++ )
  {
    bool minat = false;
    for ( short j = 0; j < way.size(); j++ )
    {
      if ( way [ j ] == i )
        {        minat = true;        break;      }
    }
    if ( minat )
      continue;

    if ( abs ( x - points [i].x ) >= abs ( y - points [i].y ) )
      newsteps = abs ( x - points [i].x );
    else
      newsteps = abs ( y - points [i].y );

    vector<short> temp ( way );
    temp . push_back ( i );
    Rec ( temp, steps+newsteps );
  }
}

int main ()
{
  cin >> n;

  n2 = 2*n;

//  points [ 0 ] . x = points [ 0 ] . y = 0;

  for ( short i = 0; i < n2; i++ )
    cin  >>  points [ i ] . x  >>  points [ i ] . y;

  for ( short i = 0; i < n2; i++ )
  {
    vector <short> temp;
    temp.push_back ( i );
    short newsteps;
    if ( abs ( points [i].x ) >= abs ( points [i].y ) )
      newsteps = abs ( points [i].x );
    else
      newsteps = abs ( points [i].y );
    Rec ( temp, newsteps );
  }

  cout << record << endl;

  return 0;
}
