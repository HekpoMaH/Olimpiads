#include <stdio.h>
#include <math.h>
float c[500];
int main()
{
    int num,gr;
    scanf("%d%d",&num,&gr);
    for(int i=0;i<num;i++)
    scanf("%f",&c[i]);
    float sr=0;
    for(int i=0;i<num;i++)
    sr+=c[i];
    sr/=num;
    sr/=gr;
    printf("%.4f\n",sr);
    return 0;
}
