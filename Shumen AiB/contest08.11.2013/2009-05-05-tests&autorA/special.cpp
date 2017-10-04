/*
TASK: special
LANG: C++
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct 
{long long n;
 char cnt,type;
}Spec;
const int NN=32;
Spec a[NN]={{20000000100000002LL,17,0},{200000010000002LL,15,0},{2000001000002LL,13,0},
            {20000100002LL,11,0},{200010002LL,9,0},{2001002LL,7,0},{20102LL,5,0},{212LL,3,1},
            {2121179131852LL,13,0},{3074003LL,7,0},{953671853653LL,12,0},{99704560597822753LL,17,0},
            {7LL,1,1},{6328428636000007LL,16,0},{2118984413357LL,13,0},{97LL,2,0},{997LL,3,0},
            {9997LL,4,0},{99997LL,5,0},{999997LL,6,0},{9999997LL,7,0},{99999997LL,8,0},
            {999999997LL,9,0},{9999999997LL,10,0},{99999999997LL,11,0},{999999999997LL,12,0},
            {9999999999997LL,13,0},{99999999999997LL,14,0},{999999999999997LL,15,0},
            {9999999999999997LL,16,0},{99999999999999997LL,17,0},{3148LL,4,0}
           };
long long b[32];
int N;
int cmp(const void *a, const void *b)
{Spec *p=(Spec *)a,*q=(Spec *)b;
 if (p->n>q->n) return 1; 
 if (p->n<q->n) return -1;
 return 0;
} 
int cmp1(const void *a, const void *b)
{long long *p=(long long *)a,*q=(long long *)b;
 if (*p>*q) return 1; 
 if (*p<*q) return -1;
 return 0;
} 
int SpCnt(int DCnt)
{int c=0,i;
 for (i=0;a[i].cnt<DCnt;i++) c++;
 for (;i<NN && a[i].cnt==DCnt;i++) c+=(1-a[i].type);
 return c;
}
int digCnt(int &n)
{int i;
 n=0;
 for (i=1;n<N;i++) n+=SpCnt(i);
 i--;
 n-=SpCnt(i);
 return i;
}
long long makeIt(void)
{int n,i=0,j;
 int d;
 qsort(a,NN,sizeof(Spec),cmp);
 d=digCnt(n);
 for (j=0;j<NN && a[j].cnt<d;j++)
 {b[i]=a[j].n;
  for (int k=0;k<d-a[j].cnt;k++) b[i]*=10;
  i++;
 }
 for (;j<NN && a[j].cnt==d;j++) if (!a[j].type) b[i++]=a[j].n; 
 qsort(b,i,sizeof(long long),cmp1);
 return b[N-n-1];
}
int main(void)
{
    cin>>N;
    cout<<makeIt()<<endl;
    return 0;
}
