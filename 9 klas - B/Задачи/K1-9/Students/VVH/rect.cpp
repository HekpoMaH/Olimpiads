#include <iostream>
#include <algorithm>
using namespace std;
struct line{
       int x1;
       int y1;
       int x2;
       int y2;
};
struct line hor[502][5000];
struct line ver[502][5000];
int ihor[501];
int iver[501];
int n;
int ophor(const void* p1,const void* p2){
    struct line* a;
    struct line* b;
    a=(struct line*)p1;
    b=(struct line*)p2;
    if(a->x1<b->x1) return -1;
    if(a->x1>b->x1) return 1;
    return 0;
}
int opver(const void* p1,const void* p2){
    struct line* a;
    struct line* b;
    a=(struct line*)p1;
    b=(struct line*)p2;
    if(a->y1<b->y1) return -1;
    if(a->y1>b->y1) return 1;
    return 0;
} 
int main(){
    int i,j,k,l;
    int x1,y1,x2,y2;
    cin>>n;
    for(i=0;i<n;i++){
                     cin>>x1>>y1>>x2>>y2;
                     if(x1>x2){
                               j=x1;
                               x1=x2;
                               x2=j;
                              }
                     if(y1>y2){
                               j=y1;
                               y1=y2;
                               y2=j;
                              }
                     ver[x1][iver[x1]].x1=x1;                    
                     ver[x1][iver[x1]].y1=y1;
                     ver[x1][iver[x1]].x2=x1;
                     ver[x1][iver[x1]].y2=y2;
                     iver[x1]++;
                     ver[x2][iver[x2]].x1=x2;
                     ver[x2][iver[x2]].y1=y1;
                     ver[x2][iver[x2]].x2=x2;
                     ver[x2][iver[x2]].y2=y2;
                     iver[x2]++;
                     hor[y1][ihor[y1]].x1=x1;
                     hor[y1][ihor[y1]].y1=y1;
                     hor[y1][ihor[y1]].x2=x2;
                     hor[y1][ihor[y1]].y2=y1;
                     ihor[y1]++;
                     hor[y2][ihor[y2]].x1=x1;
                     hor[y2][ihor[y2]].y1=y2;
                     hor[y2][ihor[y2]].x2=x2;
                     hor[y2][ihor[y2]].y2=y2;
                     ihor[y2]++; 
                    }             
    for(i=0;i<=500;i++){
                        qsort(hor[i],ihor[i],sizeof(struct line),ophor);
                        qsort(ver[i],iver[i],sizeof(struct line),opver);
                       }
    long br=0;
    long tek;
    long beg;
    long end;
    for(i=0;i<=500;i++){
                        if(iver[i]==0) continue;
                        beg=ver[i][0].y1;
                        end=ver[i][0].y2;
                        for(j=1;j<iver[i];j++){
                                               if(ver[i][j].y2<=end) continue;
                                               if(ver[i][j].y1<=end) end=ver[i][j].y2;
                                               else {
                                                     br=br+end-beg;
                                                     beg=ver[i][j].y1;
                                                     end=ver[i][j].y2;
                                                    }
                                              }
                        br=br+end-beg;
                       }
   for(i=0;i<=500;i++){
                       if(ihor[i]==0) continue;
                       beg=hor[i][0].x1;
                       end=hor[i][0].x2;
                       for(j=1;j<ihor[i];j++){
                                              if(hor[i][j].x2<=end) continue;
                                              if(hor[i][j].x1<=end) end=hor[i][j].x2;
                                              else {
                                                    br=br+end-beg;
                                                    beg=hor[i][j].x1;
                                                    end=hor[i][j].x2;
                                                   }      
                                             }
                        br=br+end-beg;
                       }                                                                         
    cout<<br<<'\n';
    //system("pause");
    return 0;
}                         
