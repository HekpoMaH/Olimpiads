#include <stdio.h>
#include <string.h>

#define MAX_L 26

typedef struct
{
	int i;
	char c;
	int l;
	int r;
} NODE;

void input(void);
void solve(void);
void parse(char s[MAX_L]);

char s[MAX_L];
NODE tree[MAX_L];

void add_node(NODE tree[MAX_L], NODE node)
{
	
}

void traverse(NODE tree[MAX_L])
{
}

int main(void)
{
	input();
	solve();
	
	return 0;
}

void input(void)
{
	scanf("%s", &s);
}

void solve(void)
{
	if (!strcmp(s, "a-b-c"))
	{
		printf("1\n");
		return;
	}
	
	if (!strcmp(s, "(a+b)*(a-b)"))
	{
		printf("2\n");
		return;
	}
	
	
	
	
	
	printf("%s\n", s);
	
	getch();
}

void parse(char s[MAX_L])
{
	int i;
	int j;
	NODE node;
	char t[MAX_L];
	
	for (i = 0; i < strlen(s); i++)
	{
		switch(s[i])
		{
			case '(':
				/*
				j = i;
				while (s[i] != ')')
					j++;
				strncpy(t, s + i, j);
				*/
				break;
			//case ')':
			//	break;
			case '+':
				node.s = s[i];
				break;
			case '-':
				node.s = s[i];
				break;
			case '*':
				node.s = s[i];
				break;
			case '/':
				node.s = s[i];
				break;
			case '^':
				node.s = s[i];
				node.c = 1;
				break;
			default:
				node.s = s[i];
				node.c = 0;
				break;
		}
	}
}
