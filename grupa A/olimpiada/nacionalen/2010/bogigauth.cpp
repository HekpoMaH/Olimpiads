#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>

using namespace std;

int mas[100];
int n;

char dp[1<<20];

void print(int num)
{
   for(int i = 0; i < n;++i) ( num & (1<<i) ) ? printf("1") : printf("0"); printf(" be6e %d\n",num);
}
int go(int mask)
{
    if( dp[mask] != 0 ) return dp[mask];

    dp[mask] = '0';
    int tmp;

    for( int i = 1; i < n; ++i )
    if( i == n - 1 || (mask & (1<<(i+1))))
    {

     for( int j = i - 1; j >= 0; --j)
      if( (mask & (1<<(j+1))) ){

        tmp = mask >> (i+1);

        tmp <<= (i-j-1);
        tmp|=((mask & ((1<<i) - 1)) >> (j+1));
        tmp <<= 1;

        tmp <<= (j+1);
        tmp|=(mask&((1<<(j+1))-1));

        dp[mask] = max(dp[mask], (char)((((int)go(tmp)-(int)('0'))^1)+'0'));
        if(dp[mask]=='1') {return '1'; }
      }
    }
return dp[mask];
}

int main()
{
    scanf("%d", &n);
    for( int i = 0; i < n; ++i )
     scanf("%d", &mas[i]);

    sort(mas, mas + n);

    int mask = 0, prev = mas[0];

    for( int i = 1; i < n; ++i )
    {
     if( mas[i] != prev ) mask ^= (1<<i);
     prev = mas[i];
    }

   // memset(dp, -1, sizeof(dp));//printf("%d\n",mask);
    printf("%c\n", go(mask));
return 0;
}

