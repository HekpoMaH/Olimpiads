#include <cstdio>
#include<iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 110000

int n, p, k;
int a[MAXN];
int more[MAXN];
int col, me;

int main(){
           //freopen("sport.in", "rt", stdin);
           //freopen("sport.out", "wt", stdout);
           scanf("%d%d%d", &n, &p, &k);
           p--;
           int rest = n - 1;
           for (int i = 0; i < n; i++)
               scanf("%d", &a[i]);
           col = 0;
           for (int i = 0; i < n; i++){
               if ((a[i] > a[p]) || ((a[i] == a[p]) && (i >= p))){
                         more[col] = i;
                         col++;
               }
               if (i == p)
                  me = col - 1;
           }
           string rez = "";
           int dist = more[0];
           for (int i = 0; i < me; i++){
              cout<<more[i]<<"\n";
               dist += more[i + 1] - more[i] - 1;
               rez.push_back('-');
               rest--;
           }
           return 0;
           more[col] = n;
           int i = me;
           while (rest != 0){
                 if (k >= rest){
                    k--;
                    rez.push_back('+');
                 }
                 else{
                      rez.push_back('-');
                      if (i < col)
                         dist += more[i + 1] - more[i] - 1;
                         i++;
                 }
                 rest--;
           }
           printf("%d\n",  dist + 1);
           for (int i = 0; i < n - 1; i++)
               printf("%c", rez[i]);
           return 0;
}
