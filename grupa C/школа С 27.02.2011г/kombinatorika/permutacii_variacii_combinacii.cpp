#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <set>

#define SP system("pause");
#define maxn 20000000;

using namespace std;

int n = 5;
int k = 3;
int a[] = { 1, 2, 3, 4, 5 };//na4alna podredba
int used[ 10 ];
int m[ 10 ];

void perm( int s )
{
    if ( s >= n )//ako sme namerili nova permutaciq
    {
        for ( int i = 0; i < n; i++ )//q otpe4atvame
        {
            cout << m[ i ] << " ";
        }
        cout << endl;
    }
    else
    {
        for ( int i = 0; i < n; i++ )//ako ne sme namerili nova tyrsim elementi koito moje da izpolzvame
        {
            if ( used[ i ] == 0 )//ako otkriem takyv
            {
                   m[ s ] = a[ i ];//slagame go v masiva
                   used[ i ] = 1;//markirame go kato izpolzvan
                   perm( s + 1 );//rekursivno vikame perm za sledva6tiq element
                   used[ i ] = 0;//i razmarkirvame teku6tiq element za da moje da go izpolzvame pak
            }
        }
    }
}

void var( int s )
{
    if ( s >= k )//ako sme namerili nova variaciq
    {
        for ( int i = 0; i < s; i++ )//q otpe4atvame
        {
            cout << m[ i ] << " ";
        }
        cout << endl;
    }
    else
    {
        for ( int i = 0; i < n; i++ )//ako ne sme namerili nova tyrsim elementi koito moje da izpolzvame
        {
            if ( used[ i ] == 0 )//ako otkriem takyv
            {
                m[ s ] = a[ i ];//slagame go v masiva
                used[ i ] = 1;//markirame go kato izpolzvan
                var( s + 1 );//rekursivno vikame var za sledva6tiq element
                used[ i ] = 0;//i razmarkirvame teku6tiq element za da moje da go izpolzvame pak
            }
        }
    }
}

void comb( int s, int after )
{
    if ( s >= k )//ako sme namerili nova kombinaciq
    {
        for ( int i = 0; i < s; i++ )//q otpe4atvame
        {
            cout << m[ i ] << " ";
        }
        cout << endl;
    }
    else
    {
        for ( int i = after + 1; i < n; i++ )//zapo4vame cikyla ot after + 1 za6toto pro kombinaciite
                                            //nqma zna4enie dali 4islata sa 1 2 3 ili 3 2 1 zatova s 
                                            //tova after + 1 izbqgvame povtoreniqta
        {
                m[ s ] = a[ i ];
                comb( s + 1, i );
        }
    }
}

int main()
{
    cout << "  Permutacii " << endl;
    perm( 0 );
    cout << "  Variacii na 5 - elementa ot 3 - klas " << endl;
    var( 0 );
    cout << "  Combinacii na 5 - elementa ot 3 - klas " << endl;
    comb( 0, -1 );//izvikvame funkciqta s -1 na mqstoto na after za6toto -1 +1 = 0
    SP;
	return 0;
}



