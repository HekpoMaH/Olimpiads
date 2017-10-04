
/*
Формат на входния файл:
На първия ред са записани 3 числа -  - съответно броя на върховете в ,  и броя на ребрата от L към R.
Следват  реда на които има по 2 числа - съответно връх от  и връх от  които са свързани

Примерен вход("matching.in"):
5 4 8
1 6
2 6
2 8
3 7
3 8
3 9
4 8
5 8

*/


#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

const int N = 1024;
const int NONE = -2;

int n1, n2, m;

vector<int> a[N];


void Input(){
	freopen("matching.in", "rt", stdin);
	scanf("%d%d%d", &n1, &n2, &m);
	for(int i=0; i<m; i++){
		int p, q;
		scanf("%d%d", &p, &q);
		p--;
		q--;
		a[p].push_back(q);
	}
}

void Matching(){
	
	
	int match[N];
	bool used[N];
	int prev[N];
	queue<int> q;
	int i, j;

	for(i=0; i<n1+n2; i++)
		match[i] = NONE;
	

	for(i=0; i<n1; i++){
		
		for(j=0; j<n1+n2; j++){
			used[j] = false;
		}
		
		q.push(i);
		prev[i] = NONE;

		bool found = false;
		while(!q.empty() && !found){
			int tmp = q.front();
			used[tmp] = 1;
			for(j=0; j<a[tmp].size(); j++){
				int next = a[tmp][j];
				if(!used[ next ]){			
					used[ next ] = true;						
					prev[ next ] = tmp;
					q.push(next);
					if(match[ next ] == NONE){							
						found = true;
						break; 
					}
					else{
						prev[ match[ next ] ] = next;
						q.push( match[ next ] );
					}				
				}
			}
			if(found){
				tmp = q.back();
				while(prev[tmp] != NONE){
					if(tmp >= n1)
						match[tmp] = prev[tmp];
					tmp = prev[tmp];					
				}
			}
			else{
				q.pop();
			}

		}
		while(!q.empty())
			q.pop();
	}
	int max = 0;
	for(i=n1; i<n1+n2; i++)
		if(match[i] != NONE)
			max++;
	printf("Maximum matching is %d.\n", max);
	for(i=n1; i<n1+n2; i++)
		if(match[i] != NONE)
			printf("%d - %d\n", match[i]+1, i+1);
	printf("\n");
}

int main(){
	Input();
	Matching();
	return 0;
