#include<iostream>
using namespace std;
int n,a[1000004];
int reps[1000004];
int next[1000004];
int ansstart,ansend,ansrep;
int curstart,curend,currep;
struct tlargenumber
{
  int n,rep,dig[1000004];
};
void readinput()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
}
int getseqcount(int ind)
{
  int count=1,i=ind;
  while(i+1<n&&a[i+1]==a[i])
  {count++;i++;}
  return count;
}
void updateans()
{
  int i,j,anspast,curpast;
  int updateflag=1;
  if(curend-curstart<ansend-ansstart)return;
  if(curend-curstart>ansend-ansstart)
  {
    ansstart=curstart;
    ansend=curend;
    ansrep=currep;
  }
  else
  {
    anspast=0;curpast=0;
    i=ansstart;j=curstart;
    while(i<=ansend&&j<=curend)
    {
      if(a[j]>a[i])break;
      else if(a[i]=a[j])
      {
        updateflag=0;break;
      }
      if(anspast+next[i]-i<curpast+next[j]-j)
      {
        anspast+=anspast+next[i]-i;
        i=next[i];
      }
      else if(anspast+next[i]-i>curpast+next[j]-j)
      {
        curpast+=curpast+next[j]-j;
        j=next[j];
      }
      else
      {
        anspast+=anspast+next[i]-i;
        i=next[i];
        curpast+=curpast+next[j]-j;
        j=next[j];
      }
    }
    if(updateflag)
    {
      ansstart=curstart;
      ansend=curend;
      ansrep=currep;
    }
  }
}
void solve()
{
  int nextseq,rep,i=0;
  while(i<n)
  {
    reps[i]=getseqcount(i);
    nextseq=i+reps[i];
    next[i]=nextseq;
    while(i+1<n&&a[i+1]==a[i])
    {
      i++;
      reps[i]=reps[i-1];
      next[i]=nextseq;
    }
    i++;
  }
  ansstart=0;ansend=-1;
  currep=0;
  i=0;
  while(i<n)
  {
    rep=reps[i];
    if(currep==0)
    {
      if(a[i]!=0)
      {
        curstart=i;
        curend=next[i]-1;
        currep=rep;
      }
    }
    else
    {
      if(rep==currep)
      {
        curend=next[i]-1;
      }
      else if(rep>currep)
      {
        curend=i+currep-1;
        updateans();
        if(a[i]==0)currep=0;
        else
        {
          curstart=i;
          curend=next[i]-1;
          currep=rep;
        }
      }
      else
      {
        updateans();
        curstart=i-rep;
        curend=next[i]-1;
        currep=rep;
      }
    }
    i=next[i];
  }
  if(currep>0)updateans();
  if(ansend==-1)
  {
    cout<<0<<endl;
    return;
  }
  for(i=ansstart;i<=ansend;i++)cout<<a[i];
  cout<<endl;
}
int main()
{
  readinput();
  solve();
  return 0;
}
