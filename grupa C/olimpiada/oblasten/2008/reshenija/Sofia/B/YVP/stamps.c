#include <stdio.h>
#define min(a,b) (a>b)?b:a
//C!!!

int N;
int A[3001];

int M[5001];
int B[5001];
int S;

int rec(int i)
{
    if(i<0) return 0;
    if(B[i]) {return M[i];}
    int j,k;
    int minc=5001;
    for(j=0; j<N; j++)
    {
             k=i-A[j];
             if(k<0) continue;
             if(k==0) {return 1;}
             minc = min(minc, rec(k));
    }
    B[i]=1; M[i]=minc+1;
    return minc+1;
}

int main()
{
    scanf("%d %d", &S, &N);
    int i;
    for(i=0; i<N; i++)
    {
            scanf("%d", &A[i]);
    }
    printf("%d", rec(S));
    return 0;
}
