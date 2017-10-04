#include <stdio.h>

int check(bool m[],int start, int end) {
    int i = start;
    bool a = 0;
    int k=0;
    for (;i<=(end-start)/2;i++,k++) {
        if (m[i]!=m[end-k]) {
            a = 1;
            break;
        }
    }
    if (a == 1) {
        return 0;
    } else {
        if (k>0 || end/2<start) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main () {
    int N;
    scanf("%d",&N);
    bool *m = new bool [N+1];
    int i=0;
    for (;i<N;i++) {
        scanf("%d",&m[i]);
    }
    if (check(m,0,N-1) == 1) {
        printf("1");
    } else {
        int min=N;
        int k = N-1;
        for (;k>0;k--) {
            if (check(m,0,k) == 1) {
                if (check(m,k+1,N-1)==1) {
                    printf("%d\n%d",2,k+1);
                    break;
                }
            }
        }
    }

    return 0;
}
