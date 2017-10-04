#include <iostream>

using namespace std;

int n, p, i, j, maxc, din, din2, i_it, i_p, i_a, i_ar, num_parts;
double a[ 500 ], s[ 500 ], d[ 500 ];
double min_sum = 100000.0, sum;
int c[ 500 ];

double arithm( int id, int num ) {
       double s_a = 0;
       for( i_ar = 0; i_ar < num; i_ar++ ) s_a += a[ id + i_ar ];
       s_a /= num;
       return s_a;
}

double printc() {
     sum = 0;
     num_parts = 0;
     for( i_it = 0; i_it < p; i_it++ ) {
         d[ i_it ] = 0;
         s[ i_it ] = arithm( num_parts, c[ i_it ] );
         cout<<s[ i_it ]<<'\n';
         for( j = 0; j < c[ i_it ]; j++ ) {
              d[ i_it ] += ( s[ j ] - a[ num_parts + j ] ) * ( s[ j ] - a[ num_parts + j ] );
              cout<<d[ i_it ]<<'\n';
         }
         sum += d[ i_it ];
         num_parts += c[ i_it ];
     }
     if( sum < min_sum ) min_sum = sum;
     cout<<sum<<"\n\n";
}

void advance( int x ) {
     if( c[ x ] == maxc - din2 ) return;
     if( x == p - 2 ) {
         c[ x ]++;
         c[ x + 1 ]--;
         printc();
         return;
     }
     
     if( c[ x + 1 ] < din ) advance( x + 1 );
     else {
     for( i_a = x + 1; i_a < p - 1; i_a++ ) {
          c[ i_a ] = 1;
     }
     if( din > 1 ) {
         din--;
         c[ x ]++;
         c[ p - 1 ] = din;
     } else {
         din2++;
         din = maxc - din2;
         if( x == 0 ) c[ x ]++;
         c[ p - 1 ] = din;   
     }
     printc();
     }
     if( c[ x ] < maxc ) advance( x );
     return;             
}
    
int main () {
    cin>>n>>p;
    for( i = 0; i < n; i++ ) cin>>a[ i ];

    for( i = 0; i < p - 1; i++ ) c[ i ] = 1;
    c[ p - 1 ] = n - p + 1;
    maxc = n - p + 1;
    din = maxc;
    din2 = 0;
    
    printc();
    advance( 0 );
    
    printf( "%.4f\n", min_sum );
    
/*    for( i = p - 3; i >= 0; i-- ) { 
         maxc = n - ( p - i );
         while( itterate( i ) ) printc();
    }
*/    
    return 0;
}
