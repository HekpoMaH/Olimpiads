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
#include <cstdio>
#include <fstream>
#include <set>

#define SP system("pause");
#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    for ( int i = a.size() - 1; i >= 0; i-- ) b += a[ i ];//kopirame na4alniq niz no v obratna posoka
    for ( int i = 0; i < a.size(); i++ )
    {
        if ( a[ i ] == a[ a.size() - 1 ] )//ako otkriem simvol koito e ednakyv s krainiq
        {
            if ( a.substr( i, ( a.size() - i ) /2  ) == b.substr( 0, ( a.size() - i ) / 2 ) )
            /*opitvame da generirame podniz ot teku6tata poziciq v originalniq niz s dyljina do kraq
            i prover1vame dali i ednakyv s podniz ot kopiraniq niz zapo4va6t ot 0 s dyljina do i-tata kletka*/
            {
                cout << i << endl;//ako sme polu4ili ednakvi nizove to tova e i otgovora
                break;
            }
        }
    }
                SP;
	return 0;
}
