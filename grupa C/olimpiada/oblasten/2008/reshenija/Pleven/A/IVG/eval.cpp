#include <iostream>
#include <ctime>

using namespace std;

char all[30];
int top=0,op=0;

int gr[30][30],isop[30],pr[256];


void initpr()
{
	pr['-']=pr['+']=1;
	pr['*']=pr['/']=2;
	pr['^']=3;
}	

void mod(int st,int end)
{
	
	cout<<"moddin "<<st<<" "<<end<<"\n";
	st++;
	end--;
	if(st<end)
	{
		cout<<"wtf\n";
		int next=st+1;
		while(all[next]=='(' || all[next]==')')
			next++;
		if(next<end)
		{
			if(pr[all[st]]>pr[all[st+1]])
				gr[st][st+1]=1;
			if(pr[all[st]]==pr[all[st+1]] && (all[st]=='-' || all[st]=='/'))
				gr[st][st+1]=1;
		}
		
//		cout<<pr[all[end]]<<pr[all[end-1]]<<"\n";
		int prev=end-1;
		while(all[prev]=='(' || all[prev]==')')
			prev--;
		if(prev>=st)
		{
			if(pr[all[end]]>pr[all[end-1]])
				gr[end][end-1]=1;
			if(pr[all[end]]==pr[all[end-1]] && all[end]=='^')
				gr[end][end-1]=1;
		}
	}
	for(int i=st+1;i<end;i++)
	{
		int next=i+1;
		while(all[next]=='(' || all[next]==')')
			next++;
		if(next<end)
		{
			if(pr[all[i]]>pr[all[i-1]])
				gr[i][i-1]=1;
			if(pr[all[i]]==pr[all[i-1]] && all[i]=='^')
				gr[i][i-1]=1;
		}
		
		int prev=end-1;
		while(all[prev]=='(' || all[prev]==')')
			prev--;
		if(prev>=st)
		{
			if(pr[all[i]]>pr[all[i+1]])
				gr[i][i+1]=1;
			if(pr[all[i]]==pr[all[i-1]] && (all[i]=='-' || all[i]=='/'))
				gr[i][i+1]=1;
		}
	}
}


int main()
{
	char t=getchar();
	memset(isop,0,sizeof(isop));
	while(t!=EOF && t!='\n')
	{
		if(!isalpha(t))
			all[top++]=t;
		if(!isalpha(t) && t!='(' && t!=')')
		{
			op++;
			isop[top-1]=1;
		}
		t=getchar();
	}
//	cout<<all<<"\n";
//	cout<<op<<"\n";
/*	memset(gr,0,sizeof(gr));
	initpr();
	

	for(int i=0;i<top;i++)	// everything in brackets is before what's next to the brackets
	{
		if(all[i]!='(')
			continue;
		int j;
		for(j=i+1;j<top;j++)
			if(all[j]==')')
				break;
		if(j==top)
		{
			cout<<"punk...\n";
			return 0;
		}
		for(int k=i+1;k<j;k++)
		{
			if(i)
			{
				
				gr[k][i-1]=1;
			}
			if(j+1<top)
				gr[k][j+1]=1;
		}
		
		mod(i,j);
	}						// done with the brackets and in them...
	
	
	
	
	for(int i=0;i<top;i++)
	{
		cout<<i<<"\t";
		for(int j=0;j<top;j++)
			cout<<gr[i][j];
		cout<<"\n";
	}
	cout<<"0\t";
	for(int i=0;i<top;i++)
		cout<<isop[i];
	cout<<"\n"; */
	
	int res=1;
	for(int i=1;i<=op;i++)
		res*=i;
	cout<<res<<"\n";
	return 0;
}
