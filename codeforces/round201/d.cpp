#include<bits/stdc++.h>
using namespace std;
int n,m,p;
string a,b,virus;
int nxt[109][33];
int dp[109][109][109];
int move[109][109][109];
void read()
{
    ios_base::sync_with_stdio(false);
    cin>>a;
    cin>>b;
    cin>>virus;
}
int getnext(int len,char ch)
{
    int letterindex=ch-'A',i;
    bool fl;
    if(nxt[len][letterindex]!=-1)return nxt[len][letterindex];
    if(virus[len]==ch)return nxt[len][letterindex]=len+1;
    if(len==0)return nxt[len][letterindex]=0;
    for(i=len;i>=1;i--)
        if(virus[i-1]==ch)
        {
            fl=true;
            for(int k1=0,k2=len-i+1;k1<=i-2;k1++,k2++)
            if(virus[k1]!=virus[k2])
            {
                fl=false;
                break;
            }
            if(fl==true)return nxt[len][letterindex]=i;
        }
    return nxt[len][letterindex]=0;
}
int go(int i,int j,int len)
{
    if(dp[i][j][len]!=-1)return dp[i][j][len];
    if(i==n||j==m)return dp[i][j][len]=0;
    int ret,mov;
    int vv1=go(i+1,j,len);
    int vv2=go(i,j+1,len);
    if(vv1>vv2)
    {
        ret=vv1;
        mov=1;
    }
    else
    {
        ret=vv2;
        mov=2;
    }
    if(a[i]==b[j])
    {
        int nxtlen=getnext(len,a[i]);
        if(nxtlen!=p)
        {
            int tmp=go(i+1,j+1,nxtlen)+1;
            if(ret<tmp)
            {
                ret=tmp;
                mov=3;
            }
        }
    }
    move[i][j][len]=mov;
    return dp[i][j][len]=ret;
}
void write(int i, int j, int len) {
	if(!move[i][j][len]) {
		cout << endl;
		return;
	}

	if(move[i][j][len] == 1) write(i + 1, j, len);
	else if(move[i][j][len] == 2) write(i, j + 1, len);
	else {
		int nxtLen = getnext(len, a[i]);
		cout << a[i];
		write(i + 1, j + 1, nxtLen);
	}
}

void solve() {
	n = a.size();
	m = b.size();
	p = virus.size();

	memset(nxt, -1, sizeof(nxt));
	memset(dp, -1, sizeof(dp));

	if(!go(0, 0, 0)) {
		cout << "0\n";
		return;
	}

	write(0, 0, 0);
}

int main()
{
	read();
	solve();

    return 0;
}
