#include <iostream>
#include <string>
#include <algorithm>
struct Edge{
    std::size_t to;
    bool left;
    std::size_t prev;
} edge[1<<15];
std::size_t edgeSize=2;
std::size_t first[1<<11];
void addEdge(std::size_t from, std::size_t to){
    edge[edgeSize].to=to;
    edge[edgeSize].left=true;
    edge[edgeSize].prev=first[from];
    first[from]=edgeSize;
    ++edgeSize;
    edge[edgeSize].to=from;
    edge[edgeSize].left=false;
    edge[edgeSize].prev=first[to];
    first[to]=edgeSize;
    ++edgeSize;
    return;
}
bool used[1<<11];
void clear(){
    std::fill(used, used+(1<<11), false);
    return;
}
bool findFlow(std::size_t loc){
    used[loc]=1;
    if(loc==2047) return true;
    for(std::size_t i=first[loc];i;i=edge[i].prev){
        if(used[edge[i].to]||!edge[i].left) continue;
        if(findFlow(edge[i].to)){
            edge[i].left=0;
            edge[i^1].left=1;
            return true;
        }
    }
    return false;
}
std::size_t m, n;
void addDir(std::size_t i1, std::size_t j1, std::size_t i2, std::size_t j2){
    addEdge(2*(i1*m+j1)+1, 2*(i2*m+j2));
    return;
}
bool cat[32][32];
std::size_t construct(){
    for(std::size_t i=0;i<n;i++){
        for(std::size_t j=0;j<m;j++){
            if(i>0&&i+1<n&&j>0&&j+1<m){
                addDir(i, j, i-1, j);
                addDir(i, j, i, j-1);
                addDir(i, j, i+1, j);
                addDir(i, j, i, j+1);
            }else addEdge(2*(i*m+j)+1, 2047);
            if(cat[i][j]) addEdge(2*m*n, 2*(i*m+j)+1);
            else addEdge(2*(i*m+j), 2*(i*m+j)+1);
        }
    }
    return 2*m*n;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin>>n;
    for(std::size_t i=0;i<n;i++){
        std::string l;
        std::cin>>l;
        m=l.size();
        for(std::size_t j=0;j<m;j++){
            cat[i][j]=l[j]=='1';
        }
    }
    std::size_t k=construct();
    std::size_t i=0;
    while(findFlow(k)){
        clear();
        i++;
    }
    std::cout<<i<<'\n';
    return 0;
}
