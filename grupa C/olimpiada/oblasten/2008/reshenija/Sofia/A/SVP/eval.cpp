//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;
#define TRUE 1
#define FALSE 0

int len = 0;
int op = 0;
int ways = 1;
char str[32], s[32];

bool is_sqr_brckt(char a)
{
    if(a == '[' || a == ']') return TRUE;
    return FALSE;
}

bool is_brckt(char a)
{
    if(a == '(' || a == ')') return TRUE;
    return FALSE;
}
    
bool is_op(char a)
{
    if(a == '+' || a == '-') return TRUE;
    if(a == '*' || a == '/') return TRUE;
    if(a == '^') return TRUE;
    return FALSE;
}

char prev_op(int ind)
{
    if(ind > 0)
    {    
        ind--;
        while (!is_op(s[ind]) && ind > 0) ind--;
        if(is_op(s[ind])) return s[ind];
        else return 0;
    }
    else return 0;
} 

char next_op(int ind)
{
    if(ind > 0)
    {    
        ind++;
        while (!is_op(s[ind]) && ind > 0) ind++;
        if(is_op(s[ind])) return s[ind];
        else return 0;
    }
    else return 0;
} 

void solve(int beg, int end)
{
    for(int i = beg; i <= end; ++i)
        if(s[i] == ')')
        {
            s[i] = ']';
            int new_end = i, new_beg;
            for(int j = i - 1; j >= 0; --j)
                if(s[j] == '(') 
                {    
                    s[j] = '[';
                    new_beg = j;
                }
            solve(new_beg, new_end);
        }
 //****************************************
    int m_len = 0, is_prev_div = 0;
    for(int i = beg; i <= end; ++i)
    {
        if(s[i] == '*')
        {
            if(m_len == 0)
            {
                if(prev_op(i) == '/')
                    is_prev_div = 1;
                m_len++;
            }
            else m_len++;
        }
    }
    m_len -= is_prev_div;
    for(int i = 2; i < m_len + 1; i++)
        ways *= i;
//+++++++++++++++++++++++++++++++++++++++++
    int a_len = 0, is_prev_min = 0;
    for(int i = beg; i <= end; ++i)
    {
        if(s[i] == '+')
        {
            if(a_len == 0)
            {
                if(prev_op(i) == '-')
                    is_prev_min = 1;
                a_len++;
            }
            else a_len++;
        }
    }
    a_len -= is_prev_min;
    for(int i = 2; i < a_len + 1; i++)
        ways *= i;    
}       
                        
                  
int main()
{
    gets(str);
    len = strlen(str);
    for(int i = 0, j = 0; i < len; ++i)
    {
        if(is_op(str[i])) 
        {    
            s[j] = str[i];
            op++;
            j++;
        }
        if(is_brckt(str[i]))    
        {    
            s[j] = str[i];
            j++;
        }
    }
    for(int i = 1; i < len - 1; ++i)
        if(is_op(s[i]) && s[i-1] == ')' && s[i+1] == '(')
            ways *= 2;
    solve(0, len-1);
    printf("%d\n", ways);
}
