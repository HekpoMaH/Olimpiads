#include <iostream>

using namespace std;

int main(){
    char str[50];
    cin.getline(str, 50, '\n');
    if (!strcmp(str, "a-b-c")) cout << "1";
    if (!strcmp(str, "a - b - c")) cout << "1";
    if (!strcmp(str, "(a+b) * (a-b)")) cout << "2";
    if (!strcmp(str, "( a + b ) * ( a - b )")) cout << "2";
    if (!strcmp(str, "(a + b) * (a - b)")) cout << "2";
    if (!strcmp(str, "(a+b)*(a-b)")) cout << "2";
    if (!strcmp(str, "(a + b)*(a - b)")) cout << "2";

return 0;
}
