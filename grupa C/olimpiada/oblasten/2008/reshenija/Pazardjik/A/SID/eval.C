#include<stdio.h>
#include<ctype.h>
#include<string.h>

char str[30],actions[30];
int L=0,positions[30];
long int count=1;


void func(int a,int b);
int find(int a,int b);
void do(int a);



void main(void)
{
	int i=0;
	gets(str);

	func(0,strlen(str));
	printf("%d",count);

}



int find(int a,int b)
{
	int i=a;
	int j=0;

	do
	{
	if(isalpha(str[i])==0)
	{
		if(str[i]=='(')
		{
			while(str[i]!=')')
				i++;
			i++;
			actions[j]=str[i];
			positions[j]=i;
			j++;
		}
		else 
		{
			actions[j]=str[i];
			positions[j]=i;
			j++;
		}
	}
	i++;
	}while(i<b);

	return j;

}

void do(int a)
{
	int i=0;
	int j=0;

	if( (str[a+1]=='(')&&(str[a-1]!=')') )
	{
		j=i+2;
		while(str[j]!=')')
			j++;
		func(i+1,j);
	}else  
						
		if( (str[i+1]!='(')&&(str[i-1]==')') )
		{
			j=i-2;
			while(str[j]!='(')
				j--;
			func(i-1,j);
		}else

			if( (str[i+1]=='(')&&(str[i-1]==')') )
			{
				count++;
				j=i-2;
				while(str[j]!='(')
					j--;
				func(i-1,j);
				j=i+2;
				while(str[j]!=')')
					j++;
				func(i+1,j);
			}
}

void func(int a,int b);
{
	int i=0;
	int j;

	j=find(a,b);

	for(;i<j+1;i++)
	{
		if(actions[i]=='^')
		{
			actions[i]=' ';
			do(position[i]);
		}
		else
			if(actions[i]=='*')
				if( (actions[i+1]=='*')||(actions[i+1]=='/') )
				{

					do(position[i]);







