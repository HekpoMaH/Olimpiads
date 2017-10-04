#include <stdio.h>

int main () {
    short int n;
    int s;
    scanf("%d",&s);
    scanf("%d",&n);
    int min=0;
    if (n==0) {
        min = 0;
    } else {
    if (n>1 && s/n<n && s-n!=0) {
        min = 2;
    } else {
    bool flag2 = 0;
        for (int i=n;i>0;i--) {
            int copy = s;
            int br=0;
            bool flag = 0;
            while (copy>0 && flag==0) {
                for (int j=i;j>0 && copy>0;j--) {
                    if (copy%n == 0 && n!=j) {
                        j = n;
                    }
                    bool flag7 = 0;
                    for (int h=n;h>1;h--) {
                        if (copy%h==0 && copy - j != 0) {
                            copy /= h;
                            flag7 = 1;
                            break;
                        }
                    }
                    if (flag7==0) {
                    if (copy%j == 0 && j!=1 && copy - j != 0) {
                        copy /= j;
                    } else {
                        if (copy - j<0) {
                            flag = 1;
                            break;
                        }
                        int k=1;
                        bool flag3=0;
                        int best=0;
                        int proiz = s;
                        bool flag4=0;
                        for (;k<=n && copy - j != 0;k++) {
                            int t=n;
                            for (;t>1;t--) {
                                if ((copy-k)%t==0) {
                                    flag4=1;
                                    if ((copy-k)/t<proiz) {
                                        best = k;
                                        proiz = (copy-k)/t;
                                    }
                                }
                            }
                        }
                        if (flag4==1) {
                            copy -= best;
                        } else {
                            copy -= j;
                        }
                    }
                    }
                    br++;
                }
            }
            if (flag2==0) {
                min = br;
                flag2 = 1;
            }
            if (br<min && flag==0) {
                min = br;
            }
        }
    }
    }
    printf("%d",min);
    return 0;
}
