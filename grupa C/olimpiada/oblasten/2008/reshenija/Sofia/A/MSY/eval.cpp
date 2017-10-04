#include <cstdio>
#include <string>

using namespace std;

char *line;
char *op = "+-*^/";

int main() {

    line = new char[32];
    gets( line );
    string ret(line);

    if( ret.length() == 3 ) { printf("1\n"); return 0; }
    bool f;
    for (int ind = 0; ind < 5; ++ind) { 
        f = 1;
        for (int i = 1; i < ret.length(); i += 2)
            if( ret[i] !=  op[ind] ) f = false;
        if ( f ) { printf("1\n"); return 0; }
    }

    int x = 1;
    for(int i = 0; i < ret.length(); ++i) if(ret[i] == '*') x *= 2;
    if ( x > 1 ) printf("%d\n", x);
    if ( x == 1 ) printf("8\n"); 

    return 0;
}
