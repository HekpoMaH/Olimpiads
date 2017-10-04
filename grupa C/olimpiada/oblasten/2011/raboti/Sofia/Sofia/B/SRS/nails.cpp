#include <cstdio>
#include <queue>
#define maxn 1005
#define maxc 10000
using namespace std;

struct nail{
    int
    x1, y1,
    x2, y2,
    chek;
};
struct Tpoint{
    int x;
    int y;
};


nail a[maxn];

queue <nail> que;

int s(int x1, int y1, int  x2, int y2, int x3, int y3){ // 2, 1 i 0 za leji na pravata

    int rez;
    rez = (y1+y2)*(x2 - x1) + (y2+y3)*(x3 - x2) + (y1+y3)*(x1 - x3);

    //printf(" (%d %d), (%d %d), (%d %d) --> %d\n", x1, y1, x2, y2, x3, y3, rez);

    if(rez > 0){
        return 2;
    }else if(rez < 0){
        return 1;
    }else return 0;

}



bool x(nail a, nail b){
    Tpoint c, d;
    c.x = b.x1 + (b.x1 - a.x1);
    c.y = b.y1 + (b.y1 - a.y1);
    d.x = b.x2 + (b.x2 - a.x1);
    d.y = b.y2 + (b.y2 - a.y1);

    int rez1, rez2;

    rez1 = s(b.x1, b.y1, a.x2, a.y2, c.x, c.y );
    rez2 = s(b.x2, b.y2, a.x2, a.y2, d.x, d.y);

    //printf("b1a2c = %d, b2a2d = %d\n", rez1, rez2);

    if( (rez1 != rez2) || (rez1 == 0 || rez2 == 0)){
        if( (s(b.x1, b.y1, a.x2, a.y2, b.x2, b.y2 ) == s(b.x1, b.y1, c.x, c.y, b.x2, b.y2)) || s(b.x1, b.y1, a.x2, a.y2, b.x2, b.y2) == 0 ){
            return true;
        }
    }
}

int br;

int main(){

    int k = 0;
    while(scanf("%d %d %d %d", &a[k].x1, &a[k].y1, &a[k].x2, &a[k].y2) == 4){
        a[k].chek = 0;
        a[k].x1 += maxc;
        a[k].x2 += maxc;
        a[k].y1 += maxc;
        a[k].y2 += maxc;
        ++k;
    }

    que.push(a[k-1]);

    while(que.size()){

        for(int i = 0; i<k-1; ++i){
            if(!a[i].chek && que.size()!= -12){
                if( x(que.front(), a[i])){

                    //printf("i = %d\n", i);

                    br++;
                    que.push(a[i]);
                    a[i].chek = 1;
                }
            }


        }que.pop();
    }

    printf("%d\n", br);


    return 0;
}


/*
5 2 8 2
3 4 3 1
7 1 6 4
3 3 0 3
6 3 1 1
^Z
*/