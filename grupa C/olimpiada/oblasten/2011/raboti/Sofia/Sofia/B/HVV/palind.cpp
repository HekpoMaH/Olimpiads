#include <cstdio>
typedef unsigned short int uint16_t;

bool Data[1<<16];
uint16_t MinCount[1<<16], Split[1<<16], i, j, N, Res[1<<16], PalinOddLen[1<<16]/*index==middle*/, PalinEvenLen[1<<16]/*index==right middle*/;
int main(){
    MinCount[0]=0;
    scanf("%hu", &N);
    for(i=1;i<N;i++) MinCount[i]=65535;
    for(i=0;i<N;i++){
        scanf("%hu", &j);
        Data[i]=j;
    }
    for(i=0;i<N;i++){
        for(j=0;j<=i&&i+j<N&&Data[i-j]==Data[i+j];j++);
        PalinOddLen[i]=2*j-1;
        for(j=0;j<i&&i+j<=N&&Data[i-j-1]==Data[i+j];j++);
        PalinEvenLen[i]=2*j;
    }
    for(i=1;i<=N;i++){
        MinCount[i]=MinCount[i-1]+1;
        Split[i]=i-1;
        for(j=2;j<=i;j++){
            if(j%2==0){
                if(PalinEvenLen[i-j/2]<j) continue;
            }else{
                if(PalinOddLen[i-(j+1)/2]<j) continue;
            }
            if(MinCount[i-j]+1<MinCount[i]){
                MinCount[i]=MinCount[i-j]+1;
                Split[i]=i-j;
            }
        }
    }
    printf("%hu\n", MinCount[N]);
    for(i=Split[N],j=0;i!=0;j++,i=Split[i]) Res[j]=i;
    if(j!=0){
        printf("%hu", Res[j-1]);
        if(j>=2) for(i=j-1;i!=0;) printf(" %hu", Res[--i]);
        putchar(10);
    }
    return 0;
}
