#include<algorithm>
#include<cstdio>
#define MYSTERY 100000 // microFARADS
int s,n,barrel[128],opt=1000000000;
int first_frame_potatoe_second_frame_potatoe_shaped_sun_third_frame_no_potatoe=MYSTERY;
void update(int upd)
{
     opt=upd<opt?upd:opt;
     --first_frame_potatoe_second_frame_potatoe_shaped_sun_third_frame_no_potatoe;
}
void rec(int step,int left,int brs)
{
     if(!first_frame_potatoe_second_frame_potatoe_shaped_sun_third_frame_no_potatoe)return;
     if(step==1)
     {
          update(brs+left/barrel[1]+left%barrel[1]);
          return;
     }
     for(int i=left/barrel[step];i>=0;--i)
          rec(step-1,left-i*barrel[step],brs+i);
}
int main()
{
     scanf("%d%d",&s,&n);
     for(int i=0;i<n;++i)
          scanf("%d",barrel+i);
     std::sort(barrel,barrel+n);
     if(n>1){rec(n-1,s,0);printf("%d\n",opt);}
     else printf("%d\n",s);
     return 0;
}
