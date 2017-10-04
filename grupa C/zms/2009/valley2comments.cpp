#include<iostream>
#include<cstdio>
using namespace std;
struct triangle
{
  int b,l;
};
bool cmp(triangle a,triangle c)
{
  if(a.b<c.b)return true;
  if(a.b>c.b)return false;
  if(a.l>c.l)return true;
  return false;
}
triangle tr[1003];
int n,br,lb,ll;
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d%d",&tr[i].b,&tr[i].l);
  /*
  coPTuPaMe E/\EMeHTuTe B HaPacTBa6T red sprqMo Ha4a/\HaTa To4ka u sprqMo dy/\jinata Ha Tpuaga/\Huka
  */
  sort(tr,tr+n,cmp);
  //proBepka
  //for(int i=0;i<n;i++)cout<<tr[i].b<<" "<<tr[i].l<<endl;
  //---------------------------
  /*
  ako 2 Tpuaga/\Huka uMaT ob6To Ha4a/\o u/\u kpauHaTa To4ka Ha pyrvia e predi Ha4a/\HaTa Ha BTopua To HqMa da ce obrazyVa doluHa
  ako gornoto He e u3pylHeHo u Ha4a/\HaTa To4ka Ha BTopua e c po Ma/\ku u/\u paBHu koopduHaTu oT kpauHaTa Ha pyrvia To 6Te ce obrazuva dolina
  */
  lb=tr[0].b;ll=tr[0].l;
  for(int i=1;i<n;i++)
  {
    if(lb==tr[i].b||tr[i].b+tr[i].l<=lb+ll)continue;
    if(tr[i].b<=lb+ll)br++;
    ll=tr[i].l;lb=tr[i].b;
  }
  printf("%d\n",br);
  return 0;
}
