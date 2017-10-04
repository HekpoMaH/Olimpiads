#include<cstdio>
using namespace std;




main ()
{
    char s;
    int operation = 1;
    //1 - plus, 2 - minus, 3 - *
    int res = 0;
    while ( 1 )
    {
        scanf("%c",&s);
        if ( s == '\n' || s =='\0') break;
        if ( s >= '0' && res <='9')
         {
             if ( operation == 1) res += s-48;
             if ( operation == 2) res -= s-48;
             if ( operation == 3) res *= s-48;
         }
        else
        {
            if ( s == '*') operation = 3;
            if ( s == '+') operation = 1;
            if ( s == '-') operation = 2;
        }
    }

    printf("%d\n",res);

    return 0;
}
