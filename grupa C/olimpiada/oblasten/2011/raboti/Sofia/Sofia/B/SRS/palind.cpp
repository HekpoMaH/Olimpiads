#include <cstdio>
#include <queue>
#include <stack>
#define maxn 10005
using namespace std;


stack <int> obr;
/*struct Tpoint{
    int x;
    int y;
    int num;
};*/

struct prev{
    int i;
    int num;
};


int n;
int a[maxn];
queue <int> que;

prev pred[maxn];



bool palind(int i, int j){ // i do j vkliu4itelno
    for(int k = i, l = j; k < l; ++k, --l){
        if(a[k] != a[l]){
            return false;
        }
    }
    return true;
}

int main(){



    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i<n; ++i){
        pred[i].num = -1;
    }

    que.push(0);
    int br = 0, next = 1;

    while(que.size()){
        br++;

        for(int j = next, p = 0; j>0; --j, ++p){


            if(p == 0){next = 0;}

            for(int i = que.front(); i<n; ++i){
                if(palind(que.front(), i)){
                    next++;
                    que.push(i+1);
                    if(br < pred[i].num || pred[i].num == -1){
                        pred[i].i = que.front() - 1;
                        pred[i].num = br;

                    }

                    if(i == n-1){
                        printf("%d\n", br);

                        if(br == 1) return 0;

                        int k = n-1;

                        while(pred[k].num > 1){

                            obr.push(pred[k].i);
                            k = pred[k].i;
                        }

                        printf("%d", obr.top()+1 );
                        obr.pop();
                        while(obr.size()){
                            printf(" %d", obr.top()+1);
                            obr.pop();
                        }
                        printf("\n");

                        return 0;
                    }
                }
            }que.pop();

        }

    }printf("\n");


    return 0;
}
/*
16
1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 0
*/