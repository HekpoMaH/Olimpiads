#include <cstdio>
#define min(a, b) (((a)<(b))?(a):(b))
#define max(a, b) (((a)<(b))?(b):(a))
struct SegmentT{
    double a, b; //y=ax+b ; if a=inf, then x=b
    int MinX, MaxX, MinY, MaxY;
} Seg[1024];
bool Cr[1024][1024];
const double Inf=1.0/0.0;
bool Cross(const SegmentT &a, const SegmentT &b){
    double x, y;
    if(a.a==Inf){
        if(b.a==Inf){
            return a.b==b.b&&((b.MinY<=a.MinY&&a.MinY<=b.MaxY)||(a.MinY<=b.MinY&&b.MinY<=a.MaxY));
        }else{
            y=b.a*a.b+b.b;
            return a.MinY<=y&&y<=a.MaxY&&b.MinX<=a.b&&a.b<=b.MaxX;
        }
    }else{
        if(b.a==Inf){
            y=a.a*b.b+a.b;
            return b.MinY<=y&&y<=b.MaxY&&a.MinX<=b.b&&b.b<=a.MaxX;
        }else{
            if(a.a==b.a){
                if(a.b!=b.b) return 0;
                return (b.MinX<=a.MinX&&a.MinX<=b.MaxX)||(a.MinX<=b.MinX&&b.MinX<=a.MaxX);
            }else{
                x=(a.b-b.b)/(b.a-a.a);
                return a.MinX<=x&&x<=a.MaxX&&b.MinX<=x&&x<=b.MaxX;
            }
        }
    }
    return 1;
}
int i, j, a, b, c, d, N, Count;
bool Used[1024];
void DFS(int Curr){
    Used[Curr]=1;
    Count++;
    for(int i=0;i<N;i++){
        if(Used[i]) continue;
        if(Cr[Curr][i]) DFS(i);
    }
    return;
}
int main(){
    for(N=0;scanf("%u %u %u %u", &a, &b, &c, &d)==4;N++){
        if(a==c){
            Seg[N].a=Inf;
            Seg[N].b=a;
        }else{
            Seg[N].a=double(b-d)/double(a-c);
            Seg[N].b=b-Seg[N].a*a;
        }
        Seg[N].MinX=min(a, c);
        Seg[N].MaxX=max(a, c);
        Seg[N].MinY=min(b, d);
        Seg[N].MaxY=max(b, d);
    }
    for(i=0;i<N;i++){
        Cr[i][i]=0;
        for(j=0;j<i;j++){
            Cr[i][j]=Cr[j][i]=Cross(Seg[i], Seg[j]);
        }
    }
    DFS(N-1);
    printf("%d\n", N-Count);
    return 0;
}
