/*
Task: Cakes
Author: Petar Petrov
*/

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int sz, first_big, second_big, l, cn_first, cn_second, n;

string s = "", tmp1 = "", tmp2 = "";

vector <int> p;


void read ()
{
	int n, i, num;
	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		cin>> num;
		p.push_back ( num );
	}
}


string rev ( int a )
{
	string res = "";
	if ( a == 0 ) return "0";
	while ( a )
	{
		res += ( (a % 10) + '0' );
		a /= 10;
	}
	reverse (res.begin () , res.end () );
	return res;
}


string solve ()
{
	int i;
	sz = p.size();

	for ( i = 1; i < sz; i++ )
		if ( p [ i ] != p [ i - 1 ] )
		{
			l = 1;
			break;
		}

	if ( l == 0  )
	{
		if ( sz == 1 )
		{
			s = "CAKE 0 PIECES ";
			s += rev ( p [0] );
		}
		else s = "CAKE 0 PIECES 1";
	}
	else
	{
		first_big = p [ 0 ];
		for ( i = 1; i < sz; i++ ) if ( first_big < p [ i ] ) first_big = p [ i ];
		i = 0;
		while ( p [ i ] == first_big ) i++;
		second_big = p [ i ];

		for ( i = 0; i < sz; i++ ) if ( p [ i ] > second_big && p [ i ] < first_big ) second_big = p [ i ];

		for ( i = 0; i < sz; i++ )
			if ( p [ i ] == first_big ) cn_first++;
			else if ( p [ i ] == second_big ) cn_second++;

		if ( cn_first % 2 == 0 )
		{
			i = 0;
			while ( p [ i ] != first_big ) i++;
			tmp1 = rev ( i );
			for ( i = 0; i < sz; i++ )
			if ( p [ i ] == first_big )
			{
				tmp2 = rev ( i );
				if ( tmp1 > tmp2 ) tmp1 = tmp2;
			}
			s = "CAKE " + tmp1 + " PIECES 1";
		}
		else
		{
			if ( cn_first == 1)
			{
				if ( cn_second % 2 == 1 )
				{
					for ( i = 0; i < sz ; i++ )
					{
						if ( p [ i ] == first_big )
						{
							tmp2 = rev ( i );
							s = "CAKE " + tmp2 + " PIECES " + rev ( first_big - second_big );
							break;
						}
					}
				}
				else
				{
					for ( i = 0; i < sz; i++ )
					{
						if ( p [ i ] == first_big )
						{
							tmp2 = rev ( i );
							s = "CAKE " + tmp2 + " PIECES ";
							break;
						}
					}

					tmp1 = rev ( first_big );
					tmp2 = rev ( first_big - second_big );
					if ( tmp1.size () == tmp2.size() )
					{
						tmp2 = rev ( first_big - second_big + 1);
						s += tmp2;
					}
					else
					{
						int x = tmp2.size();
						tmp2 = "1";
						for ( i = 0; i < x; i++ )tmp2 += "0";
						s += tmp2;
					}
				}
			}
			else
			{
				i = 0;
				while ( p [ i ] != first_big ) i++;
				tmp1 = rev ( i );
				for ( i = 0; i < sz; i++ )
				{
					if ( p [ i ] == first_big )
					{
						tmp2 = rev ( i );
						if ( tmp1 > tmp2 ) tmp1 = tmp2;
					}
					s = "CAKE " + tmp1 + " PIECES 1";
				}
			}
		}
	}
	return s;
}

int main ()
{
	read ();
    cout << solve () << endl;
	return 0;
}
