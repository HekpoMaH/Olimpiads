#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std ;


int n , m ;
int a[ 100007 ] ;
int b[ 100007 ] ;
int mindist[ 100007 ] ;
int eating[ 100007 ];
int brhungry ;


void input ( ) ;
void solve ( ) ;
pair < int , int >  getclosest( int ind ) ;

void dostep1( int x , int y ) ;

void dostep2( int x , int y , int y1 ) ;


int main ( )
	{
	input ( ) ;
	solve ( ) ;
	return 0 ;
	}


void input ( )
	{
	scanf ( "%d%d" , &n , &m ) ;
	int u , u1 ;
	scanf ( "%d%d" , &u , &u1 ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ )
		{
		scanf ( "%d" , &a[ i ] ) ;
		}
	for ( i = 0 ; i <  m ; i ++ )
		{
		scanf ( "%d" , &b[ i ] ) ;
		mindist[ i ] = 1000000000 ;
		}

	}

pair < int , int >  getclosest( int ind )
	{
	int l , r ;
	l = 0 ;
	r = m  ;
	int mid ;
	while ( r - l > 1 )
		{
		mid = ( r + l ) / 2 ;
		if ( b[ mid ] > a[ ind ] ) r = mid ;
		else l = mid ;
		}
	if ( b[ l ] < a[ ind ] ) l ++ ;
	pair < int , int > ans ;
	ans.first = l - 1 ;
	ans.second = l ;
	return ans ;
	}


void solve ( )
	{
	if ( m == 0 ) { printf ( "%d\n", n ) ; return ; }
	int i , j ;
	pair < int , int > p ;
	int mn = 10000;
	int mn1 = 10000;
	for ( i = 0 ; i < n ; i ++ )
		{
		p = getclosest( i ) ;
		///printf ( "%d %d\n" , p.first , p.second ) ;
		mn = 10000007 ;
		mn1 = 10000007 ;
		if ( p.first != -1 )
			{
			mn = a[ i ] - b[ p.first ] ;
			}
		if ( p.second != m )
			{
			mn1 = b[ p.second ] - a[ i ] ;
			}
		if ( mn == mn1 ) dostep2( i , p.first , p.second ) ;
		else
			{
			if ( mn < mn1 ) dostep1 ( i , p.first ) ;
			else dostep1 ( i , p.second ) ;
			}
		}
	printf ( "%d\n" , brhungry ) ;
	}



void dostep1( int x , int y )
	{
	int dist = abs( a[ x ] - b[ y ] ) ;
	if ( dist == mindist[ y ] ) { eating[ y ] ++ ; return ; }
	if ( dist > mindist[ y ] ) { brhungry ++ ; return ; }
	brhungry += eating[ y ] ;
	eating[ y ] = 1 ;
	mindist[ y ] = dist ;
	}

void dostep2( int x , int y , int y1 )
	{
	int dist = abs ( a[ x ] - b[ y ] ) ;
	int dist1 = abs ( a[ x ] - b[ y1 ] ) ;
	if ( dist == mindist[ y ] ) { eating[ y ] ++ ; return ; }
	///if ( dist1 == mindist[ y1 ] ) { eating[ y1 ] ++ ; return ; }
	///if ( dist > mindist[ y ] ) { brhungry ++ ; return ; }
	///else if ( dist1 > mindist[ y1 ] ) { brhungry ++ ; return ; }
	int mn ;
	if ( eating[ y ] <= eating[ y1 ] ) mn = y ;
	else mn = y1 ;

	brhungry += eating[ mn ] ;
	eating[ mn ] = 1 ;
	mindist[ mn ] = dist ;
	}