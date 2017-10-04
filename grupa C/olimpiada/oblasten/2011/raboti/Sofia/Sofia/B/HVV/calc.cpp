#include <cstdio>
typedef unsigned int uint32_t;
uint32_t MinCount[1<<20], i, j, N, Sum, C;
bool Found[1<<20];
void Find(uint32_t i){
    if(Found[i]) return;
    uint32_t j;
    for(j=2;j<=N;j++){
        Find(i/j);
        C=MinCount[i/j]+1+(i%j==0?0:1);
        if(C<MinCount[i]){
            MinCount[i]=C;
        }
    }
    Found[i]=1;
    return;
}
int main(){
    scanf("%u %u", &Sum, &N);
    for(i=1;i<=Sum;i++){
        MinCount[i]=(i+N-1)/N;
    }
    for(i=1;i<=N;i++) Found[i]=1;
    Find(Sum);
    printf("%u\n", MinCount[Sum]);
    return 0;
}
