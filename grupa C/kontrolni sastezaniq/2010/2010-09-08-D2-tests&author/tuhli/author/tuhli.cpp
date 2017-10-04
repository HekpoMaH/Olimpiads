#include <cstdio>
typedef unsigned int ui;
struct BrickT{
    ui a, b, h;
};
ui BrickTypes;
BrickT Bricks[2048];
bool CanPut[2048][2048];
ui Max=0;
ui MaxH[2048];
ui DFS(ui k){
    ui i;
    if(MaxH[k]!=0) return MaxH[k];
    for(i=0;i<BrickTypes;i++){
        if(CanPut[i][k]) if(MaxH[k]<DFS(i)) MaxH[k]=MaxH[i];
    }
    MaxH[k]+=Bricks[k].h;
    if(MaxH[k]>Max) Max=MaxH[k];
    return MaxH[k];
}
ui i, j;
inline static void swap(ui &a, ui &b){
    ui c=a;a=b;b=c;
    return;
}
int main(){
    scanf("%u", &BrickTypes);
    BrickTypes*=3;
    for(j=0;j<BrickTypes;j+=3){
        scanf("%u %u %u", &Bricks[j].a, &Bricks[j].b, &Bricks[j].h);
        Bricks[j+1]=Bricks[j];
        swap(Bricks[j+1].b, Bricks[j+1].h);
        Bricks[j+2]=Bricks[j];
        swap(Bricks[j+2].a, Bricks[j+2].h);
        if(Bricks[j].a>Bricks[j].b) swap(Bricks[j].a, Bricks[j].b);
        if(Bricks[j+1].a>Bricks[j+1].b) swap(Bricks[j+1].a, Bricks[j+1].b);
        if(Bricks[j+2].a>Bricks[j+2].b) swap(Bricks[j+2].a, Bricks[j+2].b);
    }
    for(i=0;i<BrickTypes;i++){
        for(j=0;j<BrickTypes;j++){
            CanPut[i][j]=Bricks[i].a<Bricks[j].a&&Bricks[i].b<Bricks[j].b;
        }
    }
    for(i=0;i<BrickTypes;i++){
        DFS(i);
    }
    printf("%u\n", Max);
    return 0;
}
