
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#define SZ size()
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define x first
#define y second

#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define PI pair<int,int>
#define PD pair<double,double>
#define PLL pair<LL,LL>
#define PULL pair<ULL,ULL>
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define SI set<int>
#define PQ priority_queue
#define VVI vector<vector<int> >
#define IT iterator

#define sign(a) ((a)>0)-((a)<0)
#define sqr(a) ((a)*(a))
#define Repi(n) for (int i=0; i<n; i++)
#define Repj(n) for (int j=0; j<n; j++)
#define Repk(n) for (int k=0; k<n; k++)

#define Pi 3.1415926535897932384626433832795028841971693993751
#define INF 2000000000
#define EPS 1e-6

#define pause system("pause")

using namespace std;

int n,m;
int N;
char s1[256];

bool M[128][128],oM[128][128]; int ps[128],cs[128];
int pos[128];

int omg(char* s,int n)
{

	int skob=0,last=0;
	VI op,p;
	Repi(n)
	{
	 if (s[i]=='(') skob++;
	 else if (s[i]==')') skob--;
	 else if (!skob && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')) op.PB(i);
	}
//	Repi(op.SZ) cout<<s[op[i]]<<" "; cout<<endl;
	 
	Repi(op.SZ) { p.PB(N+i); pos[N+i]=op[i]+s-s1; }
	
	for (int i=op.SZ-1; i>0; i--)
	 if (s[op[i]]=='^' && s[op[i-1]]=='^') M[i+N][i+N-1]=1;
	for (int i=0; i<op.SZ-1; i++)
	 if (s[op[i]]=='/')
	  {
			int j=i+1;
			while (j<op.SZ && op[j]=='^') j++;
			if (j<op.SZ)
			  M[i+N][j+N]=1;
	  } 
	for (int i=0; i<op.SZ-1; i++)
	 if (s[op[i]]=='-')
	  {
			int j=i+1;
			while (j<op.SZ && !(s[op[j]]=='+' || s[op[j]]=='-')) j++;
			if (j<op.SZ)
		 	 M[i+N][j+N]=1;
	  }
	 
	Repi(op.SZ)
	 if (s[op[i]]=='^') 
	  {
	   int j=i-1;
	   while (j>-1 && s[op[j]]=='^') j--;
	   if (j>-1) M[i+N][j+N]=1;
	   j=i+1;
	   while (j<op.SZ && s[op[j]]=='^') j++;
	   if (j<op.SZ) M[i+N][j+N]=1;
	  //Repj(op.SZ) if (s[op[j]]!='^')
	  // M[i+N][j+N]=1;
	  }
	Repi(op.SZ)
	 if (s[op[i]]=='/' || s[op[i]]=='*')
	  {
	   int j=i-1;
	   while (j>-1 && !(s[op[j]]=='+' || s[op[j]]=='-')) j--;
	   if (j>-1) M[i+N][j+N]=1;
	   j=i+1;
	   while (j<op.SZ && !(s[op[j]]=='+' || s[op[j]]=='-')) j++;
	   if (j<op.SZ) M[i+N][j+N]=1;
	  }
	Repi(op.SZ)
	 M[N+i][N+op.SZ]=1;
	N+=op.SZ+1;   int ret=N-1;
	
	op.insert(op.begin(),-1); p.insert(p.begin(),0);
	op.PB(n); p.PB(0);
	Repi(op.SZ-1)
	 if (op[i+1]-op[i]>3)
	  {
	   int pp=omg(s+op[i]+2,op[i+1]-op[i]-3);
	   if (i) M[pp][p[i]]=1;
	   if (i<op.SZ-2) M[pp][p[i+1]]=1;
	  }
	
	pos[ret]=0;
	return ret;
}

bool u[128]; int br,brbad;
int t[128];

void Count(int Pos)
{
	if (Pos==N) { 
		br++; return; }
	Repi(N)
	 if (!u[i] && !ps[i])
	  {
			u[i]=1;
			Repj(N) if (M[i][j]) ps[j]--;
			Count(Pos+1);
			Repj(N) if (M[i][j]) ps[j]++;
			u[i]=0;
	  }
}

int brute(int n)
{
	int ans=0;
	VI tmp;
	Repi(N) if (pos[i]) tmp.PB(i);
	do
	{
		bool stava=1;
		Repi(tmp.SZ)
		 Repj(tmp.SZ)
		  if (j>i && M[tmp[j]][tmp[i]])
		   { stava=0; break; }
		if (stava) 
		 {ans++;
//		 Repi(tmp.SZ) cout<<pos[tmp[i]]<<" "; cout<<endl;
		 }
	}while (next_permutation(ALL(tmp)));
	return ans;
}

int main()
{
    int i,j,k,l;
    string S="(a+b)/5/3^7*3-2^b^c/y";
  //  S="(a-b)-(c+d)*g+d";
    cin>>S;
    if (S.SZ<3) { cout<<"1\n"; return 0; }
    Repi(S.SZ-2)
     if (S[i]=='(' && S[i+2]==')')
      { S.erase(S.begin()+i); S.erase(S.begin()+i+1); i-=2; }
  //  cout<<S<<endl;
   // S="(a+b+c)*(a+b+c)";
   
    strcpy(s1,S.c_str());
    
        
    N=0;
    omg(s1,strlen(s1));
    
	Repi(N)
	 Repj(N)
	  {
			ps[j]+=M[i][j];
			cs[i]+=M[i][j];
	  }
	Repi(N)
	 if (pos[i]==0)
	  {
	   Repj(N)
	    Repk(N)
	     if (M[j][i] && M[i][k])
	      M[j][k]=1;
	   Repj(N)
	    { M[j][i]=1; M[i][j]=0; }
	   brbad++;
	  }
	memcpy(oM,M,sizeof(oM));
	



    if (S.SZ<20)
     {
			cout<<brute(strlen(s1))<<"\n";
			return 0;
	 }
    
	Count(0);
	cout<<br<<"\n";
    
   // pause;
    return 0;
}
