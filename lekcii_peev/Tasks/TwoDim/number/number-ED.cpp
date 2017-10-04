#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_S (9 * 100)
#define MAX_P (9 * 9 * 100)
#define MAX_LEN 100

using namespace std;

int len[MAX_S + 1][MAX_P + 1];
int last_dig[MAX_S + 1][MAX_P + 1];
int numb[MAX_LEN];
int i, j, k, t, sz;
int s, p;

int main(){
memset(last_dig, -1, sizeof(last_dig));
memset(len, -1, sizeof(len));

for(i=1; i<=9; i++) len[i][i * i] = 1, last_dig[i][i * i] = i;

for(i=2; i<=MAX_S; i++)
for(j=2; j<=MAX_P; j++)
if(len[i][j] == -1)
            for(k=1; k<=9 && i - k >= 0 && j - k * k >= 0; k++)
            if(len[i - k][j - k*k] != -1  && (len[i][j] == -1 || len[i - k][j - k*k] + 1 < len[i][j]))
            {
            len[i][j] = len[i - k][j - k*k] + 1;
            last_dig[i][j] = k;
            }


scanf("%d", &t);
while(t--)
        {
        scanf("%d%d", &s, &p);
        if(s > MAX_S || p > MAX_P) printf("No solution\n"); 
        else if(len[s][p] == -1 || len[s][p] > MAX_LEN) printf("No solution\n");
        else {
             sz = 0;
             while(!(s == 0 || p == 0) ) {
                      numb[sz] = last_dig[s][p];
                      s = s - numb[sz];
                      p = p - numb[sz] * numb[sz];
                      sz++;
                      }
             
             for(i=0; i<sz; i++) printf("%d", numb[i]);
             printf("\n");
             }
        }

return 0;
}
