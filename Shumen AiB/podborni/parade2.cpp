
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(a) (int)a.size()
#define zero(a) memset (a, 0, sizeof(a))
#define mp make_pair

#define right fdnskgldnfghgfkl_right
#define left fdgfhggfhmlfdsgf_left

#define taskname "parade"



const int MAXN = 110000;
const int MAXLST = 1<<17;
const int MAXSZ = 2*MAXLST + 100;
const int MAXN_assert = 100000;
const int inf = 2e9;

pair<int,int> tree[MAXSZ];
int n;

int ans[MAXN];
int a[MAXN];
int lst = 0;

int left[MAXN];
int right[MAXN];

void NO(){
	printf("Impossible\n");
	exit(0);
}

void build(){
	 lst = 2;
	 while (lst < n)
	 	lst *= 2;
	 for (int i = lst; i < lst + n; i++)
	 	 tree[i] = mp(a[i-lst],i-lst);
	 for (int i = lst -1; i > 0; i--)
	 	tree[i] = max(tree[2*i],tree[2*i+1]);
}

pair<int,int> get(int v,int l,int r,int L,int R){
	if ( r < L || R < l)
		return mp(-inf,-inf);
	if (L <= l && r <= R)
		return tree[v];
	return max(get(2*v,l,(l+r)/2,L,R), get(2*v+1,(l+r)/2+1,r,L,R));
}

void solve(int l,int r,int lup,int rup,int ldown,int rdown){

		//cerr << l <<" "<<r<<" "<<lup <<" "<<rup << " "<<ldown<<" "<<rdown<<endl;
		//cerr << ans[0] <<" "<<ans[1] <<" "<<ans[2] <<" "<<ans[3] << endl;
		//cerr << endl;
	   if (l > r)
	   		return;
	   if (!(ldown < a[r] && a[r] < rdown)){
	   	  if (!(lup < a[r] && a[r] < rup))
	   		  NO();
	   	  ans[r] = 1;
	   	  solve(l,r-1,lup,a[r],ldown,rdown);
	   	  return;
	   }

	   if (!(lup < a[l] && a[l] < rup)){
	   	  //cerr <<"!!!!"<<endl;
	   	  if (!(ldown < a[l] && a[l] < rdown))
	   		  NO();
	   	  ans[l] = 0;
	   	  solve(l+1,r,lup,rup,ldown,a[l]);
	   	  return;
	   }
	   
	   int mid = get(1,0,lst-1,l,r).second;

	   //cerr << mid << endl;

	   bool qup = (lup < a[mid] && a[mid] < rup && (mid == r || right[mid+1] >= (r-mid)));
	   bool qdown = (ldown < a[mid] && a[mid] < rdown && (mid == l || left[mid-1] >= (mid-l)));

	   //cerr << qup <<" "<<qdown << endl;
	   
	   if (qup && qdown){
	   	  for (int i = l; i < mid; i++)
	   	  	ans[i] = 1;
	   	  return;
	   }

	   if (!qup && !qdown)
	   	 NO();

	   if (qup){
	   	  ans[mid] = 1;
	   	  solve(l,mid-1,lup,a[mid],(mid == r?ldown:a[mid+1]),rdown);
	   	  return;
	   }

	   for (int i = l; i < mid; i++)
	   	ans[i] = 1;

	   solve(mid+1,r,(mid == l?lup:a[mid-1]),rup,ldown,a[mid]);
}


int main (void)
{
  assert(freopen (taskname".in", "r", stdin));
  freopen (taskname".out", "w", stdout);

  assert(scanf("%d",&n) == 1);
  assert(1 <= n && n <= MAXN_assert);
  for (int i = 0; i < n; i++)
  	assert(scanf("%d",&a[i]) == 1), assert(1 <= a[i] && a[i] <= 1000000000);

  build();

  for (int i = 0; i < n; i++){
  	left[i] = (i?left[i-1]:0);
  	if (!i || a[i] > a[i-1])
  		left[i]++;
  	else
  		left[i] = 1;
  }

  for (int i = n-1; i >= 0; i--){
  	right[i] = (i!=n-1?right[i+1]:0);
  	if (i==n-1 || a[i] > a[i+1])
  		right[i]++;
  	else
  		right[i] = 1;
  }

  solve(0,n-1,0,inf,0,inf);
  //cerr << ans[0] <<" "<<ans[1] << " "<<ans[2] <<" "<<ans[3] << endl;

  int cnt = 0;
  for (int i = 0; i < n; i++)
  	if (ans[i] == 1)
  		cnt++;

  if (cnt == 0 || cnt == n){
  	ans[1] ^= 1;
  	if (cnt == 0)
  		cnt = 1;
  	else
  		cnt = n-1;
  }

  //cerr << ans[0] <<" "<<ans[1] << " "<<ans[2] <<" "<<ans[3] << endl;

  printf("%d\n",cnt);
  for (int i = 0; i < n; i++)
  	if (ans[i] == 1)
  		printf("%d ",i+1);
  printf("\n");
  return 0;
}
