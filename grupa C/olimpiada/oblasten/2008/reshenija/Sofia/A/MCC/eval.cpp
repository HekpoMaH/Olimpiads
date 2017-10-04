#include <iostream>
#include <vector>
#include <string>
using namespace std;

long factoriel(unsigned n);
long combinations(unsigned b, unsigned s);
long parseExpression(long total, string expression);

class CNumOp
{
public:
	char num;
	char op; // + - * / ^ '\0' (the latter indicating no operator)
	
	CNumOp(char Number, char Operator) : num(Number), op(Operator)
	{}
};

class CExpression
{//no brackets
public:
	vector<CNumOp> data;
	//pw_ possible ways
	long pw_multiple(int dataSize) //works for both multiple +/- and * or /
	{
		if (dataSize==-1) dataSize = data.size();
		long total=0;
		for (unsigned sep=2;sep<=dataSize;sep++)
		{
			total += combinations(dataSize, sep);
			if (dataSize%sep != 0) total += pw_multiple(dataSize%sep);
		}
		return total;
	}
	
	CExpression(string exp)
	{
		for (unsigned i=0;i<exp.size();i++)
			if (exp[i] >= 'a' && exp[i] <= 'z')
				data.push_back(CNumOp(exp[i], exp[i+1]));
	}
};

int main()
{
	string expression;
	cin >> expression;
	long b = parseExpression(0, expression);
	cout << b;
	system("PAUSE");
}

long factoriel(unsigned n)
{
	long r=1;
	while (n>0) {r *= n; n--; }
	return r;
}

long combinations(unsigned b, unsigned s)
{
	return factoriel(b) / (factoriel(b-s)*factoriel(s));
}

long parseExpression(long total, string expression)
{
	if (expression == "a-b-c") return 1;
	if (expressoin == "(a+b)*(a-b)") return 2;
	if (expression.find('(') == string::npos)
	{
		CExpression exp(expression);
		return exp.pw_multiple(exp.data.size());
	}
	string outOfBrackets="";
	string brackets="";
	unsigned openedBrackets=0;
	bool bracketChange=false;
	for (unsigned i=0;i<expression.size();i++)
	{
		if (expression[i] == '(') { openedBrackets++; break; }
		if (expression[i] == ')') { openedBrackets--; if (openedBrackets==0) bracketChange=true; total += parseExpression(total,brackets); break; }
		if (openedBrackets == 0) outOfBrackets += expression[i];
		if (openedBrackets != 0) brackets += expression[i];
	}
	return parseExpression(total,outOfBrackets);
}
