#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

#define SP system("pause")
#define maxn 32767

using namespace std;

bool ok( int x )
{ int mark[ 10 ]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//deklarirame masiv v koito 6te markirame kogato 
                                                  // sre6tnem dadena cifra
  
  while ( x > 0 )//otdelqme cifrite  na 4isloto
  { int d = x % 10;
    if( mark[ d ] == 1 ) return false;//ako ve4e sme markirali teku6tata cifra vry6tame false za6toto v 
                                    //4isloto imaa dve ednakvi cifri
    mark[ d ] = 1;//ako teku6tata cifra q nqma q markirame
    x /= 10;
  }
  return true;//ako sled kato sme otdeleli cifrite na 4isloto ne sme vyrnali false tova ozna4ava 4e 
            //4isloto nqma dve ednakvi cifri i vry6tame true
} 
int main()
{
    int a, b;
    cin >> a >> b;
    int br = 0;//broq4 za 4islata koito nqmata dve ednakvi cifri
    for ( int i = a; i <= b; i++ )//za vsqko 4islo v intervala [a;b]
        if ( ok( i ) == true ) br++;//proverqvame dali nqma dve ednakvi cifr
    cout << br << endl;
return 0;
}
