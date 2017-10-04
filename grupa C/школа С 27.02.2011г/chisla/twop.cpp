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

bool mark[ 5000005 ];

void find_prosti()//generirame vsi4ki prosti 4isla do max 5000000 4rez re6eto  na eratosten
{
    for ( int i = 2; i <= 5000000; i++ )
    {
        if ( !mark[ i ] )//namirame 4islo koeto ne e markirano kato systavno
                        // to togava to e prosto i vsi4ki 4isla delq6ti se na nego ne sa prosti a sa systavni
        {
            for ( int j = i + i; j <= 5000000; j += i )//genenrirame vsi4ki 4isla koito se delqt na tova 4islo
            {
                mark[ j ] = 1;//i gi markirame kato systavni
            }
        }
    }
}
int main()
{
    int n;
    lli a;
    int br = 0;
    int mx = -1;
    
    cin >> n;
    
    find_prosti();//generirame si vsi4ki prosti 4isla
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a;
        for ( int i = 2; i <= a / 2; i++ )//za vsqko 4islo do a/2 
        {
            if ( !mark[ i ] && !mark[ a - i ] ) br++;//proverqvame dali to e prosto i dali a-nego sy6to e prosto
                                                    //i ako e to togava sme namerili edno predstavqne
        }
        mx = max( mx, br );
        br = 0;
    }
    
    cout << mx << endl;
        SP;
	return 0;
}
