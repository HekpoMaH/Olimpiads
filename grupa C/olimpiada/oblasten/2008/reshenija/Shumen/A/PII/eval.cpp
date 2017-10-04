#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 32;

string s, A;
int ans;
int num[MAX_N];

void input ()
{
	int i;

	cin >> s;

	for (i=0; i<s.size(); i++)
		if (!isalpha(s[i]))
			A += s[i];
}

bool is_valid ()
{
	int i, j, br, m;

	for (i=0; i<A.size()-1; i++) {
		if (A[i]=='(' || A[i]==')') {
			if (A[i]=='(') {
				for (j=i+1, br=1, m=0; br; j++) {
					if (A[j]=='(') br++;
					else if (A[j]==')') br--;
					else m = max(m,num[j]);
				}

				if (i>0 && A[i-1]!='(' && m>num[i-1]) return 0;
				if (j<A.size() && A[j]!=')' && m>num[j]) return 0;
			}
		} else {
			if (A[i+1]!='(' && A[i+1]!=')') {
				if (A[i]=='+') {
					if (A[i+1]!='+' && num[i]<num[i+1]) return 0;
				} else if (A[i]=='-') {
					if (A[i+1]!='+' && A[i+1]!='-' && num[i]<num[i+1]) return 0;
					if (A[i+1]=='-' && num[i]>num[i+1]) return 0;
					if (A[i+1]=='+' && num[i]>num[i+1]) return 0;
				} if (A[i]=='*') {
					if (A[i+1]=='^' && num[i]<num[i+1]) return 0;
				} else if (A[i]=='/') {
					if (A[i+1]=='+' && num[i]>num[i+1]) return 0;
					if (A[i+1]=='-' && num[i]>num[i+1]) return 0;

					if (A[i+1]=='/' && num[i]>num[i+1]) return 0;
					if (A[i+1]=='*' && num[i]>num[i+1]) return 0;

					if (A[i+1]=='^' && num[i]<num[i+1]) return 0;
				} else if (A[i]=='^') {
					if (A[i+1]!='^' && num[i]>num[i+1]) return 0;
					if (A[i+1]=='^' && num[i]<num[i+1]) return 0;
				}
			}
		}
	}

	return 1;
}

void solve ()
{
	int i, j;
	vector<int> P;
	
	for (i=0; i<A.size(); i++)
		if (A[i]!='(' && A[i]!=')')
			P.push_back (i);

	do {
		for (i=0, j=0; i<P.size(); i++) {
			while (A[j]=='(' || A[j]==')') j++;
			num[j++] = P[i];
		}

		if (is_valid ()) {
			ans++;
		}
	} while ( next_permutation(P.begin(), P.end()) );
}

int main ()
{
	input ();
	solve ();

	cout << ans << "\n";

	return 0;
}