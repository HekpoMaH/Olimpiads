#include<stdio.h>
#include<algorithm>

int main() {
    long a[100];
    long s;;
    int n,i;
    scanf("%ld %d",&s,&n);
    for(i=0;i<n;i++) {
        scanf("%ld",&a[i]);
    }
    std::sort(a,a+n);
    printf("%d\n",s/a[n-1]+2);
    return 0;
}
