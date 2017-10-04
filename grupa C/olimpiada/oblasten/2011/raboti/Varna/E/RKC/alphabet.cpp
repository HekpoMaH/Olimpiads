#include<iostream>
using namespace std;
int main(){
int m,n,br=1,i,j,br1=0,k,y;
char a,e;
scanf("%d%d",&n,&m);
a='à';
for(br=1;br<=n;br++)
{
a--;
}


a=a-'0';

    for(i=1;i<=m;i++)
    {
        for(;;)
        {
        y++;
        scanf("%c",&e);
            if(e=='.')break;
            else
            {
            e=e-'0';
                if(y==1 && (e==a || e+32==a)){
                br1++;
                k=y;
                printf("win %d",k);
                break;
                }
            }
        }
    }

if(br1==0) printf("lose \n");
return 0;
}
