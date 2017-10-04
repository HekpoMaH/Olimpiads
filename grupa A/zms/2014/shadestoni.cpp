
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef int var;
struct query
{
    var r1,c1,r2,c2;
};
struct cell
{
    var x,y,z;
};
const var MAXN=555,MAXQ=15;
var n,m,q,grid[MAXN][MAXN];
var wr,wc,br,bc;
var used[MAXN][MAXN][5];
cell previous[MAXN][MAXN][5];
vector<char> moves1,moves2,moves3;
query queries[MAXQ];
void read()
{
    var i,j;
    char x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%c",&x);
        for(j=1;j<=m;j++)
        {
            scanf("%c",&x);
            if(x=='W')grid[i][j]=-1;
            else grid[i][j]=1;
           
        }
    }
    //for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++){
    //      cout<<grid[i][j]<<" ";
    //   }
    //   cout<<"\n";
    //}
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&queries[i].r1,&queries[i].c1);
        scanf("%d%d",&queries[i].r2,&queries[i].c2);
        //cout<<queries[i].r1<<" "<<queries[i].c1<<" "<<queries[i].r2<<" "<<queries[i].c2<<"\n";
    }
    //exit(0);
}
var defineGrid()
{
    var i,j,flagw,flagb;
    flagw=flagb=0;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        {
            if(grid[i][j]==-1)
            {
                if(grid[i+1][j]==-1)flagw++;
                else
                if(grid[i][j+1]==-1)flagw++;
            }
            if(grid[i][j]==1)
            {
                if(grid[i+1][j]==1)flagb++;
                else
                if(grid[i][j+1]==1)flagb++;
            }
            if(flagw==1)
            {
                wr=i;
                wc=j;
                flagw++;
            }
            if(flagb==1)
            {
                br=i;
                bc=j;
                flagb++;
            }
        }
    //printf("@%d %d %d %d\n",wr,wc,br,bc);
    if(!flagw&&!flagb)return 1;
    if(flagw&&flagb)return 2;
    return 3;
}
void solveFirst(var index)
{
    if((queries[index].r1+queries[index].c1)%2==(queries[index].r2+queries[index].c2)%2)
    {
        printf("-1\n");
        return;
    }
    var i,path,currentr,currentc;
    currentr=queries[index].r1;
    currentc=queries[index].c1;
    path=abs(queries[index].r1-queries[index].r2);
    path+=abs(queries[index].c1-queries[index].c2)+1;
    printf("%d ",path);
    while(currentr!=queries[index].r2||currentc!=queries[index].c2)
    {
        if(currentr>queries[index].r2)
        {
            currentr--;
            printf("U");
        }
        if(currentr<queries[index].r2)
        {
            currentr++;
            printf("D");
        }
        if(currentc>queries[index].c2)
        {
            currentc--;
            printf("L");
        }
        if(currentc<queries[index].c2)
        {
            currentc++;
            printf("R");
        }
    }
    printf("\n");
}
void solveSecond(var index)
{
    if((queries[index].r1+queries[index].c1)%2==(queries[index].r2+queries[index].c2)%2)
    {
        printf("-1\n");
        return;
    }
    var i,path,currentr,currentc,black,white;
    moves1.clear();
    moves2.clear();
    moves3.clear();
    black=white=0;
    currentr=queries[index].r1;
    currentc=queries[index].c1;
    if(grid[currentr][currentc]==1)black++;
    else white++;
    while(currentr!=wr||currentc!=wc)
    {
        if(currentr>wr)
        {
            currentr--;
            moves1.push_back('U');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentr<wr)
        {
            currentr++;
            moves1.push_back('D');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc>wc)
        {
            currentc--;
            moves1.push_back('L');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc<wc)
        {
            currentc++;
            moves1.push_back('R');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
    }
    while(currentr!=br||currentc!=bc)
    {
        if(currentr>br)
        {
            currentr--;
            moves2.push_back('U');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentr<br)
        {
            currentr++;
            moves2.push_back('D');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc>bc)
        {
            currentc--;
            moves2.push_back('L');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc<bc)
        {
            currentc++;
            moves2.push_back('R');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
    }
    while(currentr!=queries[index].r2||currentc!=queries[index].c2)
    {
        if(currentr>queries[index].r2)
        {
            currentr--;
            moves3.push_back('U');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentr<queries[index].r2)
        {
            currentr++;
            moves3.push_back('D');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc>queries[index].c2)
        {
            currentc--;
            moves3.push_back('L');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
        if(currentc<queries[index].c2)
        {
            currentc++;
            moves3.push_back('R');
            if(grid[currentr][currentc]==1)black++;
            else white++;
        }
    }
    path=moves1.size()+moves2.size()+moves3.size();
    path+=abs(white-black)+1;
    printf("%d ",path);
    for(i=0;i<moves1.size();i++)
        printf("%c",moves1[i]);
    if(white<black)
    {
        for(i=1;i<=(black-white)/2;i++)
            if(wr+1<=n&&grid[wr+1][wc]==-1)printf("DU");
            else printf("RL");
    }
    for(i=0;i<moves2.size();i++)
        printf("%c",moves2[i]);
    if(white>black)
    {
        for(i=1;i<=(white-black)/2;i++)
            if(br+1<=n&&grid[br+1][bc]==1)printf("DU");
            else printf("RL");
    }
    for(i=0;i<moves3.size();i++)
        printf("%c",moves3[i]);
    printf("\n");
    //printf("%d %d\n",white,black);
}
bool valid(int x,int y,int z)
{
    if(x<1||x>n)return false;
    if(y<1||y>m)return false;
    if(z<0||z>2)return false;
    return true;
}
void print(cell el)
{
    cell el1;
    el1=previous[el.x][el.y][el.z];
    //printf("%d %d %d ! %d %d %d\n",el.x,el.y,el.z,el1.x,el1.y,el1.z);
    if(el1.z==-1)return;
    print(el1);
    if(el1.x==el.x-1)printf("D");
    if(el1.x==el.x+1)printf("U");
    if(el1.y==el.y-1)printf("R");
    if(el1.y==el.y+1)printf("L");
}
void solveThird(var index)
{
    if((queries[index].r1+queries[index].c1)%2==(queries[index].r2+queries[index].c2)%2)
    {
        printf("-1\n");
        return;
    }
    var i,j,path;
    queue<cell> reached;
    cell el,el1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            used[i][j][0]=used[i][j][1]=used[i][j][2]=0;
    el.x=queries[index].r1;
    el.y=queries[index].c1;
    el.z=1+grid[el.x][el.y];
    reached.push(el);
    used[el.x][el.y][el.z]=1;
    previous[el.x][el.y][el.z].z=-1;
    while(!reached.empty())
    {
        el=reached.front();
        reached.pop();
        if(el.x==queries[index].r2&&el.y==queries[index].c2&&el.z==1)break;
        el1.x=el.x+1;
        el1.y=el.y;
        el1.z=el.z+grid[el1.x][el1.y];
        if(valid(el1.x,el1.y,el1.z)&&!used[el1.x][el1.y][el1.z])
        {
            reached.push(el1);
            used[el1.x][el1.y][el1.z]=used[el.x][el.y][el.z]+1;
            previous[el1.x][el1.y][el1.z]=el;
        }
        el1.x=el.x-1;
        el1.y=el.y;
        el1.z=el.z+grid[el1.x][el1.y];
        if(valid(el1.x,el1.y,el1.z)&&!used[el1.x][el1.y][el1.z])
        {
            reached.push(el1);
            used[el1.x][el1.y][el1.z]=used[el.x][el.y][el.z]+1;
            previous[el1.x][el1.y][el1.z]=el;
        }
        el1.x=el.x;
        el1.y=el.y+1;
        el1.z=el.z+grid[el1.x][el1.y];
        if(valid(el1.x,el1.y,el1.z)&&!used[el1.x][el1.y][el1.z])
        {
            reached.push(el1);
            used[el1.x][el1.y][el1.z]=used[el.x][el.y][el.z]+1;
            previous[el1.x][el1.y][el1.z]=el;
        }
        el1.x=el.x;
        el1.y=el.y-1;
        el1.z=el.z+grid[el1.x][el1.y];
        if(valid(el1.x,el1.y,el1.z)&&!used[el1.x][el1.y][el1.z])
        {
            reached.push(el1);
            used[el1.x][el1.y][el1.z]=used[el.x][el.y][el.z]+1;
            previous[el1.x][el1.y][el1.z]=el;
        }
    }
    if(!used[queries[index].r2][queries[index].c2][1])
    {
        printf("-1\n");
        return;
    }
    el.x=queries[index].r2;
    el.y=queries[index].c2;
    el.z=1;
    path=used[el.x][el.y][el.z];
    printf("%d ",path);
    print(el);
    printf("\n");
}
int main()
{
    var i,subtask;
    read();
    subtask=defineGrid();
    for(i=1;i<=q;i++)
    {
        if(subtask==1)solveFirst(i);
        if(subtask==2)solveSecond(i);
        if(subtask==3)solveThird(i);
    }
}
