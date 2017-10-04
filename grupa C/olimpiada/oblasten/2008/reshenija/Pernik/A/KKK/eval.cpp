#include <cstdlib>
#include <iostream>

using namespace std;

int getMulNum(char* string)
{
    int s = 0;
    for(int i = 0; i < strlen(string);i++ )
    {
        if(string[i] == '*' && string[i+2] == '*')
            s++;
    }
    return s;
}
int getMulDivNum(char* string)
{
    int s = 0;
    for(int i = 0; i < strlen(string);i++ )
    {
        if(string[i] == '*' && string[i+2] == '/')
            s++;
    }
    return s;
}
int getAddNum(char* string)
{
    int s = 0;
    for(int i = 0; i < strlen(string);i++ )
    {
        if(string[i] == '+' && string[i+2] == '+')
            s++;
    }
    return s;
}
int getAddSubNum(char* string)
{
    int s = 0;
    for(int i = 0; i < strlen(string);i++ )
    {
        if(string[i] == '+' && string[i+2] == '-')
            s++;
    }
    return s;
}
int getBracketsNum(char* string)
{
    int s = 0;
    for(int i = 1; i < strlen(string);i++ )
    {
        if(string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/')
        {
             if(string[i-1] == ')' && string[i+1] == '(' )
                 s++;
        }
    }
    return s;
}
int main(int argc, char *argv[])
{
    char string[25];
    
    int s = 0;
    
    cout << "Enter string : ";
    cin >> string;
    
    /* Mul By 3 to get the combinations */
    s +=  getAddNum(string)*3;
    s +=  getAddSubNum(string)*3;
    s +=  getMulNum(string)*3;
    s +=  getMulDivNum(string)*3;
    
    /* Finnaly calculate for the brackets exception */
    s += getBracketsNum(string)*2;
    
    if(s == 0)
      s = 1;
    cout << s << endl;
    
    system("PAUSE");
    return 0;
}
