#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct point {
    
    int x, y;
    
};

int n;
int dirx[] = { 1, 1, -1, -1 }, diry[] = { 1, -1, 1, -1 }, used[1<<11], ans=1<<30;
point a[1<<11];


int dist ( int i, int j ) {
    
    return max( abs(a[i].x-a[j].x), abs(a[i].y-a[j].y) );
}

void go ( int f, int sum, int prev ) {
    
    if( f == n ) {
        
        if( sum < ans ) ans=sum;
        return;
    }
    
    int i;
    
    for( i=0; i<2*n; ++i ) {
        
        if( !used[i] ) {
            
            used[i]=1;
            go( f+1, sum+dist(i, prev), i );
            used[i]=0;
        }
    }
}
        
    

void read() {
    
    scanf("%d", &n);
    int i;
    for( i=0; i<2*n; ++i ) 
        scanf("%d%d", &a[i].x, &a[i].y);
    
    a[2*n].x=0;
    a[2*n].y=0;
    
    go( 0, 0, 2*n );
        
    printf("%d\n", ans);
    
}

main () {
    
    read();
    return 0;
}
