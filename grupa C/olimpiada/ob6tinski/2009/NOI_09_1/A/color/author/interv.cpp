//P. Peev
#include <iostream>
using namespace std;

typedef struct
{long start,end;
 char col;
} Interval;
typedef struct List
{Interval i;
 List *link;
};

List *list=NULL,*mp;
long maxLen=0;

void makeInterval(long a, long b, char cl,Interval *i)
{long c;
 if (a>b) {c=a;a=b;b=c;}
 i->start=a;
 i->end=b;
 i->col=cl;
}

void showInterval(Interval i)
{if (i.col) cout<<'['; else cout<<'{';
 cout<<i.start<<","<<i.end;
 if (i.col) cout<<']';else cout<<'}';
}

void showList(List *l)
{while (l)
 {showInterval(l->i);
  l=l->link;
 }
}

long len(Interval a)
{return a.end-a.start+1;
}

int ApplyTo(Interval Old,Interval New,Interval r[3])
{if (Old.end<New.start || Old.start>New.end) return 0;
 if (Old.start>=New.start && Old.end<=New.end)
 {r[0]=Old;
  r[0].col^=New.col;
  return 1;
 }
 if (Old.start>=New.start && Old.end>=New.end)
 {makeInterval(Old.start,New.end,Old.col^New.col,&r[0]);
  makeInterval(New.end+1,Old.end,Old.col,&r[1]);
  return 2;
 }
 if (Old.start<New.start && Old.end>New.end)
 {makeInterval(Old.start,New.start-1,Old.col,&r[0]);
  makeInterval(New.start,New.end,Old.col^New.col,&r[1]);
  makeInterval(New.end+1,Old.end,Old.col,&r[2]);
  return 3;
 }
// if (Old.start<New.start && Old.end<=New.end)
 makeInterval(Old.start,New.start-1,Old.col,&r[0]);
 makeInterval(New.start,Old.end,Old.col^New.col,&r[1]);
 return 2;
}

void FreeList(List **l)
{while (*l)
 {FreeList(&(*l)->link);
  *l=NULL;
 }
}

void solve(void)
{int N,j,t;
 long a,b,k;
 Interval i,r[3];
 List *l,*p,*q;
 cin>>N;
 for (j=0;j<N;j++)
 {cin>>a>>b;
  makeInterval(a,b,1,&i);
  l=list;
  p=NULL;
  while (l)
  {if(l->i.start>i.end) break;
   t=ApplyTo(l->i,i,r);
   switch(t)
   {case 0:break;
    case 1:{l->i=r[0]; break;}
    case 2:{q=new List;if (!q) {cout<<"Memory!\n"; return;}
	    q->i=r[1];
	    q->link=l->link;
	    l->i=r[0];
	    l->link=q;
	    break;
	   }
    case 3:{q=new List;if (!q) {cout<<"Memory!\n"; return;}
	    q->i=r[1];
	    q->link=new List;if (!q->link) {cout<<"Memory!\n"; return;}
	    q->link->i=r[2];
	    q->link->link=l->link;
	    l->i=r[0];
	    l->link=q;
	   }
   }
   if (t>0 && p && p->i.end==l->i.start-1 && p->i.col==l->i.col)
   {p->i.end=l->i.end;
    p->link=l->link;
    delete l;
    l=p;
   }
   for (int i=1;i<t;i++)
   {p=l;
    l=l->link;
   }
   p=l;
   l=l->link;
  }
 }
 l=list;
 while(l)
 {if (l->i.col)
  {k=len(l->i);
   if (k>maxLen) {maxLen=k;mp=l;}
  }
  l=l->link;
 }
}

int main(void)
{Interval i;
 makeInterval(0,500001L,0,&i);
 list = new List;
 list -> i=i;
 list -> link=NULL;
 solve();
 cout<<maxLen<<endl;
 FreeList(&list);
 return 0;
}
