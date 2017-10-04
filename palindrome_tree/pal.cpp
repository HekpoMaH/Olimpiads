// Link to the task. Russian statement.
// http://informatics.mccme.ru//mod/statements/view.php?chapterid=1750#1

#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
const int nmax = 1e5 + 9;

struct node {
   int next[26];  // Edges of the node  
   int len;          // Length of the palindrome in the node
   int sufflink;    // Suffix link
   int num;        // Number of differentsubstring palindromes of the current one
};

string s;
node tree[nmax]; // Array with the nodes of the tree
int num;         // Number of nodes in the tree
int suff;        // Numer of the node with the largest suffix-palindrome

void inittree() {
   num = 2;
   suff = 2;
   tree[1].len = -1;
   tree[1].sufflink = 1;
   tree[2].len = 0;
   tree[2].sufflink = 1;
}

// The following function returns the number of the palindromes obtained when
// appending the letter at position pos in the given string.
int addletter(int pos) {
   // tree[suff].len is the length of the current suffix-palindrome
   int curr = suff, currlen = 0;
   int let = s[pos]-'a';
   // The number of the current node is curr
   // Checking if the current position is strictly greater than the current length
   // and that the letter at position pos-1-currlen is equal to pos that is xAx
   // If it's still not, we go back using the suffix link
   currlen = tree[curr].len;
   while (pos - 1 - currlen < 0 || s[pos - 1 - currlen] != s[pos]) {
      curr = tree[curr].sufflink;
      currlen = tree[curr].len;
   }
   if (tree[curr].next[let]) {
      // If appending letter the letter s[pos] leads to an existing node than return we see that such node already exists then link to it and exit
      suff = tree[curr].next[let];
      return tree[suff].num;
   }

   // We haven't found such palindrome so far,
   // thus the largest suffix of p+x is represented by node
   // num which is of length num+2 (xAx)
   // Also we add a link from the current node
   // to the new node (representing xAx)
   // If the new palindrome is an letter string, then the suffinx link from
   // that node leads to the node with len 0 (that is node 2)
   num++;
   suff = num;
   tree[num].len = tree[curr].len + 2;
   tree[curr].next[let] = num;
 
   if (tree[num].len == 1) {
      // Suffix is of length 1
      tree[num].sufflink = 2;
      tree[num].num = 1;
      return tree[num].num;
   }
   
   // Suffix is larger
   // Then we need to find the suffix link of this new node by tracing
   // the links from the current (old) node
   // Now we check if the letter on the two positions are equal
   //If they are, the sufflink from the new node is tree[curr].next[let]
   do {
      curr = tree[curr].sufflink;
      currlen = tree[curr].len;
   } while (pos - 1 - currlen < 0 || s[pos - 1 - currlen] != s[pos]);
   tree[num].sufflink = tree[curr].next[let];

   // Also the number of palindromes derived from here is the number of palindromes
   // in the suffix link+1
   tree[num].num = 1 + tree[tree[num].sufflink].num;
   return tree[num].num;
}

int main() {
   lli ans=0;
   int len;
   cin >> s;
   len = s.size();
   inittree();
   for (int i = 0; i < len; i++) {
      ans += addletter(i);
   }
   cout << ans <<"\n";
   return 0;
}
