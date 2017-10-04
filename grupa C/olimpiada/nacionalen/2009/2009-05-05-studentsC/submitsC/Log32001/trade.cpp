/*
TASK:trade
LANG:C++
*/

#include <cstdio>

int n,first,second,third;
double o;
int s,e;
double a[1001][2];
int b[1001][2];
double otg[1001];

void read()
{
     scanf("%d", &n);
     for (int i=0;i<n;i++) {
         scanf("%d %d %f", &s, &e, o);
         if (b[s][0]==0) { b[s][0]=e; a[s][0]=2*o; }
         else { b[s][1]=e; a[s][1]=2*o; }
         if (b[e][0]==0) { b[e][0]=s; a[e][0]=2*o; }
         else { b[e][1]=s; a[e][1]=2*o; }
     }
}

int find()
{
    for (int i=0;i<n;i++) {
        if (b[b[b[i][0]][0]][0]==i) { first=i; second=0; third=0; }
        if (b[b[b[i][0]][0]][1]==i) { first=i; second=0; third=0; }
        if (b[b[b[i][0]][1]][0]==i) { first=i; second=0; third=1; }
        if (b[b[b[i][0]][1]][1]==i) { first=i; second=0; third=1; }
        if (b[b[b[i][1]][0]][0]==i) { first=i; second=1; third=0; }
        if (b[b[b[i][1]][0]][1]==i) { first=i; second=1; third=0; }
        if (b[b[b[i][1]][1]][0]==i) { first=i; second=1; third=1; }
        if (b[b[b[i][1]][1]][1]==i) { first=i; second=1; third=1; }
    }
}

/*void slove()
{
       double c1=0;
       c1=a[first][second]-a[first][third];
       otg[b[first][second]]=a[b[first][second]]
}*/

int main()
{
    read();
    find();
    if((first==second)&&(second==third)) { printf("imposible\n"); return 0;}
    //slove();
    //print();
    printf("too many\n");
    return 0;
}
