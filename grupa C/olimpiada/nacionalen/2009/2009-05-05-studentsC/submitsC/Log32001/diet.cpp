/*
TASK:diet
LANG:C++
*/

#include <cstdio>

int t10,t20,t30,dni,srqzvaniq;

void slove()
{
     while (t20<0 && t10<0 && t30>0) { t30--; t10++; t20++; srqzvaniq++; } 
     while (t20<0) {
           if ((t10>0) && (t10/2<=(-1)*t20)) { t20+=t10/2; t10=t10%2; }
           if ((t10>0) && (t10/2>(-1)*t20)) { t20=0; t10-=t20*2; }
           if ((t20<0) && (t30>0)) { t10++; t20++; t30--; srqzvaniq++; }
     }
     while (t10<0) {
           while (t10<0 && t20>0) { t20--; t10+=2; srqzvaniq++; }
           if ((t10<0) && (t30>0)) { t30--; t10++; t20++; srqzvaniq++; }
     }
     while (t30<0) {
           while (t10>0 && t20>0) { t10--; t20--; t30++; }
           while (t10/3>0) { t30++; t10-=3; }
           if (t30<0 && t20>0) { t10+=2; t20--; srqzvaniq++; }
     }
}

int main()
{
    scanf("%d%d%d", &t10, &t20, &t30);
    dni=(t10*10+t20*20+t30*30)/60;
    if (dni==0) { printf("0 0\n"); return 0; }
    t10-=dni;
    t20-=dni;
    t30-=dni;
    slove();
    printf("%d %d\n", dni, srqzvaniq);
    return 0;
}
    
