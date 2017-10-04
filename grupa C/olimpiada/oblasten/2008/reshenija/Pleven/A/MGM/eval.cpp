#include <iostream>
#include <string>
using namespace std;


#define f(i, n) for(int i = 0; i < n; i ++)

#define sz size()


string inp;
int ans;



void Read()
{
string p;
	
	
	cin >> p;
	
	f(i, p.sz) if(!isalpha(p[i])) inp += p[i];
}

void rec(string s)
{
	if(s == "00")
	{
		ans ++;
		
		return;
	}
	
	while(s.find("()")!= string::npos)
	{
		int pos = s.find("()");
		
		s.erase(pos, 2);
	}
	
	f(i, s.sz)
	{
		if(s[i] == '+') if((s[i - 1] == '0' || s[i - 1] == '+' || s[i - 1] == '(') && s[i + 1] != '*' && s[i + 1] != '/' && s[i + 1] != '^') if(s[i - 1] != ')' && s[i + 1] != '(')
		{
			rec(s.substr(0, i) + s.substr(i + 1));
		}
		
		if(s[i] == '-') if((s[i - 1] == '0' || s[i - 1] == '+' || s[i - 1] == '(') && s[i + 1] != '*' && s[i + 1] != '/' && s[i + 1] != '^') if(s[i - 1] != ')' && s[i + 1] != '(')
		{
			rec(s.substr(0, i) + s.substr(i + 1));
		}
		
		if(s[i] == '*') if((s[i - 1] == '0' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '(') && s[i + 1] != '^') if(s[i - 1] != ')' && s[i + 1] != '(')
		{
			rec(s.substr(0, i) + s.substr(i + 1));
		}
		
		if(s[i] == '/') if((s[i - 1] == '0' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '(') && s[i + 1] != '^') if(s[i - 1] != ')' && s[i + 1] != '(')
		{
			rec(s.substr(0, i) + s.substr(i + 1));
		}
		
		if(s[i] == '^') if(s[i + 1] != '^') if(s[i - 1] != ')' && s[i + 1] != '(')
		{
			rec(s.substr(0, i) + s.substr(i + 1));
		}
	}
}

void Solve()
{
	ans = 0;
	
	rec("0" + inp + "0");
}

void Write()
{
	printf("%d\n", ans);
}

int main()
{
	Read();
	
	Solve();
	
	Write();
	
	
	return 0;
}
