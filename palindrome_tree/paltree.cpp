
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 105000;

struct node {
	int next[26];
	int len;
	int sufflink;
	int num;
};

int len;
char s[MAXN];
node tree[MAXN]; 
int num; 			// node 1 - root with len -1, node 2 - root with len 0
int suff; 			// max suffix palindrome
long long ans;

bool addLetter(int pos) {
   cout<<"Length of the suffix is "<<tree[suff].len<<".\n";
	int cur = suff, curlen = 0;
	int let = s[pos] - 'a';

	while (true) {
		curlen = tree[cur].len;
                cout<<"Current node is "<<cur<<"\n";
                cout<<"Current lenght is "<<curlen<<".\n";
                cout<<"Checing if the current position is strictly larger than current length: "<<pos<<"-"<<1<<"-"<<curlen<<"\n";
                cout<<" and that the letter at position "<<pos-1-curlen<<" is equal to "<<pos<<".\n";
                cout<<s[pos-1-curlen]<<"?="<<s[pos]<<"\n";
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])    	{
                   cout<<"Yes it is.\n";
			break;	
                }
                cout<<"No its not. We go back, using the chainlink.\n";
		cur = tree[cur].sufflink;
	}		
	if (tree[cur].next[let]) {	
               cout<<"When appending letter "<<s[pos]<<" to node " <<cur<<" we see that there exists such node\n";
		suff = tree[cur].next[let];
		return false;
	}
        cout<<"We havent found such palindrome so far, thus the largest suffix of p+x is represented by node ";

	num++;
	suff = num;
	tree[num].len = tree[cur].len + 2;
	tree[cur].next[let] = num;
         cout<<num<<" which is of length the current length of of p+2 (xAx): "<<tree[cur].len+2<<".\nAlso we add a link from the current node (representing p) to the new node (representing x+p+x)\n";
           cout<<"If the new palindrome is an letter string, then the suffinx link from that node leads to the node with len 0 (that is node 2)\n";
           cout<<"What is more, the number of palindromes which this node adds is num\n";
	if (tree[num].len == 1) {
           cout<<"suff of len 1\n";
		tree[num].sufflink = 2;
		tree[num].num = 1;
		return true;
	}
      cout<<"suff of larger len\n";
      cout<<"We need to find the suffix link of this new node by tracing the links from the current (old) node\n";
	while (true) {

		cur = tree[cur].sufflink;
                
		curlen = tree[cur].len;
                cout<<"Current node, Current length ->"<<cur<<","<<curlen<<"\n";
                cout<<"Now we check if the letter on the two positions are equal\n";
                cout<<pos-1-curlen<<" "<<pos<<"\n";
                cout<<s[pos-1-curlen]<<" "<<s[pos]<<"\n";
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                   cout<<"they are thus the sufflink from the new node is "<<tree[cur].next[let]<<"\n";
			tree[num].sufflink = tree[cur].next[let];
			break;
		}    	
	}           
         //why???
        cout<<"Also the number of palindromes derived from here is "<<"1+"<<tree[tree[num].sufflink].num<<"\n";
        
	tree[num].num = 1 + tree[tree[num].sufflink].num;


	return true;
}

void initTree() {
	num = 2; suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));

	gets(s);
	len = strlen(s);

	initTree();

	for (int i = 0; i < len; i++) {
                cout<<"\n\n\n\nadding letter "<<s[i]<<"\n";
		addLetter(i);
		ans += tree[suff].num;
	}

	cout << ans << endl;

	return 0;
}   
