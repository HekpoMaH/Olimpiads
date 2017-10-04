#include <iostream>
using namespace std;
typedef struct
{int n;
 char c[64];
} Long;
Long game[4];
void mulDig(int d, Long *b)
{int carry=0,r;
 for (int i=0;i<b->n;i++)
 {r=(b->c[i]-'0')*d+carry;
  b->c[i]=r%10+'0';
  carry=r/10;
 }
 if (carry) b->c[b->n++]=carry+'0';
}
void mul20(Long *b)
{mulDig(2,b);
 memmove(&b->c[1],b->c,b->n++);
 b->c[0]='0';
}
void Dec(Long *b)
{int i;
 for (i=0;i<b->n;i++) 
  if (b->c[i]=='0') b->c[i]='9';
  else break;
 b->c[i]--;
}
int cmp(const Long *a, const Long *b)
{if (a->n<b->n) return -1;
 if (a->n>b->n) return 1;
 for (int i=a->n-1;i>=0;i--)
 {if (a->c[i]<b->c[i]) return -1;
  if (a->c[i]>b->c[i]) return 1;
 }
 return 0;
}
void setLong(Long *a, char *s)
{a->n=strlen(s);
 for (int i=a->n-1,j=0;i>=0;i--,j++) 
  a->c[j]=s[i];
}
void Solve(void)
{Long Start,CurrStart,CurrEnd;
 int i,r[4];
 for (i=0;i<4;i++) r[i]=-1;
 setLong(&Start,"10");
 for (i=0;i<4;i++) if (cmp(&game[i],&Start)<0) r[i]=2;
 while (r[0]<0 || r[1]<0 || r[2]<0 || r[3]<0)
 {CurrStart=Start;
  CurrEnd=Start;
  mulDig(2,&CurrEnd);
  Dec(&CurrEnd);
  for (i=0;i<4;i++)
   if (cmp(&game[i],&CurrStart)>=0 && 
       cmp(&game[i],&CurrEnd)<=0) r[i]=0;
  mulDig(2,&CurrStart);
  CurrEnd=CurrStart;
  mulDig(2,&CurrEnd);
  Dec(&CurrEnd);
  for (i=0;i<4;i++) if (cmp(&game[i],&CurrStart)>=0 && 
                        cmp(&game[i],&CurrEnd)<=0) r[i]=1;
  mulDig(2,&CurrStart);
  CurrEnd=CurrStart;
  mulDig(2,&CurrEnd);
  Dec(&CurrEnd);
  for (i=0;i<4;i++) if (cmp(&game[i],&CurrStart)>=0 && 
                        cmp(&game[i],&CurrEnd)<=0) r[i]=0;
  mulDig(2,&CurrStart);
  CurrEnd=CurrStart;
  mulDig(2,&CurrEnd);
  Dec(&CurrEnd);
  for (i=0;i<4;i++) if (cmp(&game[i],&CurrStart)>=0 && 
                        cmp(&game[i],&CurrEnd)<=0) r[i]=1;
  mulDig(2,&CurrStart);
  mul20(&Start);
  CurrEnd=Start;
  Dec(&CurrEnd);
  for (i=0;i<4;i++) if (cmp(&game[i],&CurrStart)>=0 && 
                        cmp(&game[i],&CurrEnd)<=0) r[i]=2;
 }
 for (i=0;i<4;i++) cout<<r[i];
 cout<<endl;
}
void inp(void)
{char b[64];
 for (int i=0;i<4;i++)
 {cin>>b;
  setLong(&game[i],b);
 }
}
int main(void)
{int p;
 inp();
 Solve();
 return 0;
}
