#include<bits/stdc++.h>
using namespace std;
const int MAXK=41;

int k,s,p,d,K;
bool rez[MAXK][MAXK*9][MAXK*9][9];

void lazy(int k,int s,int p,int from){
     if((k == 0) && (s == 0) && (p == 0) && (from == 0))
        rez[0][0][0][0] = true;
     if((k > 0) && (s > 0) && (p > 0) && (!rez[k][s][p][from])){
//        printf("%d %d %d %d\n",k,s,p,from);
//          if(from > 9)
  //           printf("BUG\n");
        rez[k][s][p][from] = true;
        for (int i = 0; i < 10; i++)
            if(k != 1){
               lazy(k - 1,s - i,p - (i * d + from) % 10,(i * d + from) / 10);
      //         printf("%d   %d %d %d %d -> %d %d %d %d  (%d)\n",d,k,s,p,from,k - 1,s - i,p - (i * d + from) % 10,(i * d + from) / 10,i);
            }
            else
                lazy(k - 1,s - i,p - (i * d + from) % 10 - (i * d + from) / 10,0);
     }
}

int solve(int k,int s,int p,int from){
//    if((k == 9))
  //  printf("Now: %d %d %d %d\n",k,s,p,from);
    if(!rez[k][s][p][from])
       while (1);
    //printf("\n\n%d   ",k);
     if(k != K)
        for (int i = 0; i < 10; i++)
            for (int e = 0; e < 9; e++){
                if(k == 0){
                      if((i != 0) && (rez[k + 1][s + i][p + (i * d + e) % 10 + (i * d + e) / 10][e])){
                                printf("%d",i);
                                solve(k + 1,s + i,p + (i * d + e) % 10 + (i * d + e) / 10,e);
                                return 1;
                      }
                }
                else{
                     if(((i * d + e) / 10 == from) && (rez[k + 1][s + i][p + (i * d + e) % 10][e])){
                             printf("%d",i);
                             solve(k + 1,s + i,p + (i * d + e) % 10,e);
                             return 1;
                     }
                }
            }
}


int main(){
           scanf("%d%d%d%d",&k,&s,&p,&d);
           lazy(k,s,p,0);
           K = k;
           if(rez[0][0][0][0])
                      solve(0,0,0,0);
           else
               printf("-1");
}
