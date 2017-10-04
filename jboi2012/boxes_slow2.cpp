#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
struct bx
{
    int f1[25],f2[25],f3[25],f4[25],f5[25],f6[25],br;
};
bx boxes[100];
int br,mbr=999999,n;
int used[7][7][7][7][7][7];
void msa(int f11,int f12,int f13,int f14,int f15,int f16,int idx)
{
    used[f11][f12][f13][f14][f15][f16]=1;
    boxes[idx].br++;
    boxes[idx].f1[boxes[idx].br]=f11;
    boxes[idx].f2[boxes[idx].br]=f12;
    boxes[idx].f3[boxes[idx].br]=f13;
    boxes[idx].f4[boxes[idx].br]=f14;
    boxes[idx].f5[boxes[idx].br]=f15;
    boxes[idx].f6[boxes[idx].br]=f16;
    if(used[f14][f11][f12][f13][f15][f16]==0)msa(f14,f11,f12,f13,f15,f16,idx);
    if(used[f12][f13][f14][f11][f15][f16]==0)msa(f12,f13,f14,f11,f15,f16,idx);
    if(used[f11][f16][f13][f15][f12][f14]==0)msa(f11,f16,f13,f15,f12,f14,idx);
    if(used[f11][f15][f13][f16][f14][f12]==0)msa(f11,f15,f13,f16,f14,f12,idx);
}
set<int> color;
set<int>::iterator it1,it2,it3,it4,it5,it6;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {//cout<<"WTF"<<endl;
        scanf("%d%d%d%d%d%d",&boxes[i].f1[1],&boxes[i].f2[1],&boxes[i].f3[1],&boxes[i].f4[1],&boxes[i].f5[1],&boxes[i].f6[1]);
        color.insert(boxes[i].f1[1]);
        color.insert(boxes[i].f2[1]);
        color.insert(boxes[i].f3[1]);
        color.insert(boxes[i].f4[1]);
        color.insert(boxes[i].f5[1]);
        color.insert(boxes[i].f6[1]);
        memset(used,0,sizeof(used));
        msa(boxes[i].f1[1],boxes[i].f2[1],boxes[i].f3[1],boxes[i].f4[1],boxes[i].f5[1],boxes[i].f6[1],i);
        /*boxes[i].f1[2]=boxes[i].f4[1]; boxes[i].f2[2]=boxes[i].f1[1];boxes[i].f3[2]=boxes[i].f2[1];boxes[i].f4[2]=boxes[i].f3[1];boxes[i].f5[2]=boxes[i].f5[1];boxes[i].f6[2]=boxes[i].f6[1];
        boxes[i].f1[3]=boxes[i].f3[1]; boxes[i].f2[3]=boxes[i].f4[1];boxes[i].f3[3]=boxes[i].f1[1];boxes[i].f4[3]=boxes[i].f2[1];boxes[i].f5[3]=boxes[i].f5[1];boxes[i].f6[3]=boxes[i].f6[1];
        boxes[i].f1[4]=boxes[i].f2[1]; boxes[i].f2[4]=boxes[i].f3[1];boxes[i].f3[4]=boxes[i].f4[1];boxes[i].f4[4]=boxes[i].f1[1];boxes[i].f5[4]=boxes[i].f5[1];boxes[i].f6[4]=boxes[i].f6[1];
        boxes[i].f1[5]=boxes[i].f1[1]; boxes[i].f2[5]=boxes[i].f4[1];boxes[i].f3[5]=boxes[i].f3[1];boxes[i].f4[5]=boxes[i].f2[1];boxes[i].f5[5]=boxes[i].f6[1];boxes[i].f6[5]=boxes[i].f5[1];
        boxes[i].f1[6]=boxes[i].f4[1]; boxes[i].f2[6]=boxes[i].f3[1];boxes[i].f3[6]=boxes[i].f2[1];boxes[i].f4[6]=boxes[i].f1[1];boxes[i].f5[6]=boxes[i].f6[1];boxes[i].f6[5]=boxes[i].f5[1];
        boxes[i].f1[7]=boxes[i].f3[1]; boxes[i].f2[7]=boxes[i].f2[1];boxes[i].f3[7]=boxes[i].f1[1];boxes[i].f4[7]=boxes[i].f4[1];boxes[i].f5[7]=boxes[i].f6[1];boxes[i].f6[5]=boxes[i].f5[1];
        boxes[i].f1[8]=boxes[i].f2[1]; boxes[i].f2[8]=boxes[i].f1[1];boxes[i].f3[8]=boxes[i].f4[1];boxes[i].f4[8]=boxes[i].f3[1];boxes[i].f5[8]=boxes[i].f6[1];boxes[i].f6[5]=boxes[i].f5[1];
        boxes[i].f1[9]=boxes[i].f1[1]; boxes[i].f2[9]=boxes[i].f5[1];boxes[i].f3[9]=boxes[i].f3[1];boxes[i].f4[9]=boxes[i].f6[1];boxes[i].f5[9]=boxes[i].f4[1];boxes[i].f6[9]=boxes[i].f2[1];
        boxes[i].f1[10]=boxes[i].f6[1];boxes[i].f2[10]=boxes[i].f1[1];boxes[i].f3[10]=boxes[i].f5[1];boxes[i].f4[10]=boxes[i].f3[1];boxes[i].f5[10]=boxes[i].f4[1];boxes[i].f6[10]=boxes[i].f2[1];
        boxes[i].f1[11]=boxes[i].f3[1];boxes[i].f2[11]=boxes[i].f6[1];boxes[i].f3[11]=boxes[i].f1[1];boxes[i].f4[11]=boxes[i].f5[1];boxes[i].f5[11]=boxes[i].f4[1];boxes[i].f6[11]=boxes[i].f2[1];
        boxes[i].f1[12]=boxes[i].f5[1];boxes[i].f2[12]=boxes[i].f3[1];boxes[i].f3[12]=boxes[i].f6[1];boxes[i].f4[12]=boxes[i].f1[1];boxes[i].f5[12]=boxes[i].f4[1];boxes[i].f6[12]=boxes[i].f2[1];
        boxes[i].f1[13]=boxes[i].f1[1];boxes[i].f2[13]=boxes[i].f6[1];boxes[i].f3[13]=boxes[i].f3[1];boxes[i].f4[13]=boxes[i].f5[1];boxes[i].f5[13]=boxes[i].f2[1];boxes[i].f6[13]=boxes[i].f4[1];
        boxes[i].f1[14]=boxes[i].f6[1];boxes[i].f2[14]=boxes[i].f3[1];boxes[i].f3[14]=boxes[i].f5[1];boxes[i].f4[14]=boxes[i].f1[1];boxes[i].f5[14]=boxes[i].f2[1];boxes[i].f6[14]=boxes[i].f4[1];
        boxes[i].f1[15]=boxes[i].f3[1];boxes[i].f2[15]=boxes[i].f5[1];boxes[i].f3[15]=boxes[i].f1[1];boxes[i].f4[15]=boxes[i].f6[1];boxes[i].f5[15]=boxes[i].f2[1];boxes[i].f6[15]=boxes[i].f4[1];
        boxes[i].f1[16]=boxes[i].f5[1];boxes[i].f2[16]=boxes[i].f1[1];boxes[i].f3[16]=boxes[i].f6[1];boxes[i].f4[16]=boxes[i].f3[1];boxes[i].f5[16]=boxes[i].f2[1];boxes[i].f6[16]=boxes[i].f4[1];
        boxes[i].f1[17]=boxes[i].f4[1];boxes[i].f2[17]=boxes[i].f6[1];boxes[i].f3[17]=boxes[i].f2[1];boxes[i].f4[17]=boxes[i].f5[1];boxes[i].f5[17]=boxes[i].f1[1];boxes[i].f6[17]=boxes[i].f3[1];
        boxes[i].f1[18]=boxes[i].f6[1];boxes[i].f2[18]=boxes[i].f2[1];boxes[i].f3[18]=boxes[i].f5[1];boxes[i].f4[18]=boxes[i].f4[1];boxes[i].f5[18]=boxes[i].f1[1];boxes[i].f6[18]=boxes[i].f3[1];
        boxes[i].f1[19]=boxes[i].f2[1];boxes[i].f2[19]=boxes[i].f5[1];boxes[i].f3[19]=boxes[i].f4[1];boxes[i].f4[19]=boxes[i].f6[1];boxes[i].f5[19]=boxes[i].f1[1];boxes[i].f6[19]=boxes[i].f3[1];
        boxes[i].f1[20]=boxes[i].f5[1];boxes[i].f2[20]=boxes[i].f4[1];boxes[i].f3[20]=boxes[i].f6[1];boxes[i].f4[20]=boxes[i].f2[1];boxes[i].f5[20]=boxes[i].f1[1];boxes[i].f6[20]=boxes[i].f3[1];
        boxes[i].f1[21]=boxes[i].f4[1];boxes[i].f2[21]=boxes[i].f5[1];boxes[i].f3[21]=boxes[i].f2[1];boxes[i].f4[21]=boxes[i].f6[1];boxes[i].f5[21]=boxes[i].f3[1];boxes[i].f6[21]=boxes[i].f1[1];
        boxes[i].f1[22]=boxes[i].f5[1];boxes[i].f2[22]=boxes[i].f2[1];boxes[i].f3[22]=boxes[i].f6[1];boxes[i].f4[22]=boxes[i].f4[1];boxes[i].f5[22]=boxes[i].f3[1];boxes[i].f6[22]=boxes[i].f1[1];
        boxes[i].f1[23]=boxes[i].f2[1];boxes[i].f2[23]=boxes[i].f6[1];boxes[i].f3[23]=boxes[i].f4[1];boxes[i].f4[23]=boxes[i].f5[1];boxes[i].f5[23]=boxes[i].f3[1];boxes[i].f6[23]=boxes[i].f1[1];
        boxes[i].f1[24]=boxes[i].f6[1];boxes[i].f2[24]=boxes[i].f4[1];boxes[i].f3[24]=boxes[i].f5[1];boxes[i].f4[24]=boxes[i].f2[1];boxes[i].f5[24]=boxes[i].f3[1];boxes[i].f6[24]=boxes[i].f1[1];*/
    }
    int mk,bk,fk=0;
    int col1,col2,col3,col4,col5,col6,ss[12];
    for(it1=color.begin();it1!=color.end();it1++)
    {
        for(it2=color.begin();it2!=color.end();it2++)
        {
            for(it3=color.begin();it3!=color.end();it3++)
            {
                for(it4=color.begin();it4!=color.end();it4++)
                {
                    for(it5=color.begin();it5!=color.end();it5++)
                    {
                        for(it6=color.begin();it6!=color.end();it6++)
                        {
                            br=0;
                            for(int i=1;i<=n;i++)
                            {
                                mk=999999;
                                for(int j=1;j<=24;j++)
                                {
                                    bk=0;
                                    if(boxes[i].f1[j]!=*it1)bk++;
                                    if(boxes[i].f2[j]!=*it2)bk++;
                                    if(boxes[i].f3[j]!=*it3)bk++;
                                    if(boxes[i].f4[j]!=*it4)bk++;
                                    if(boxes[i].f5[j]!=*it5)bk++;
                                    if(boxes[i].f6[j]!=*it6)bk++;
                                    
                                    if((*it1)==5&&(*it2)==4&&(*it3)==1&&(*it4)==5&&(*it5)==4&&(*it6)==0)
                                    {
                                        if(bk<mk)
                                        {
                                            mk=bk;ss[i]=j;
                                        }
                                    }
                                    else mk=min(bk,mk);
                                    fk+=6;
                                }
                                br+=mk;
                            }
                            if(br<mbr)
                            {
                                mbr=br;
                                col1=*it1;
                                col2=*it2;
                                col3=*it3;
                                col4=*it4;
                                col5=*it5;
                                col6=*it6;
                            }
                        }
                    }
                }
            }
        }
    }
    //cout<<fk<<endl;
    cout<<mbr<<endl;
    //cout<<col1<<" "<<col2<<" "<<col3<<" "<<col4<<" "<<col5<<" "<<col6<<endl;
    //cout<<ss[1]<<" "<<ss[2]<<" "<<ss[3]<<" "<<ss[4]<<" "<<ss[5]<<" "<<ss[6]<<" "<<ss[7]<<endl;
    return 0;
}