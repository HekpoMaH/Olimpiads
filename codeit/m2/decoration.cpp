#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
struct decor
{
    int a[109][109],like,inidx;
    vector<pair<int,int> > edinici;
    int p,q;
};
vector<decor> forma,forma2;
decor finn;
int generalcnt;
struct prozorec
{
    int nr,nc;
    int a[109][109],slike,brf,bred,inidx;
    //set<pair<int,int> > svobed;
};
prozorec prozorci[109];
//int ans[109][4];
struct creature
{
    int tip[111];
    long long evolst;int evans[109][4];
};
vector<creature> planet;
clock_t tim;
void output();
bool cmp(creature x,creature y)
{
    if(x.evolst>y.evolst)return true;
    return false;
}
bool cmpzatos(int x,int y)
{
    if(forma[x].like>forma[y].like)return true;
    return false;
}
bool cmpzatos2(int x,int y)
{
    if(forma[x].edinici.size()<forma[y].edinici.size())return true;
    return false;
}
bool cmpzaprozorci(prozorec x,prozorec y)
{
    if(x.nr*x.nc>y.nr*y.nc)return true;
    return false;
}
void read()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ifstream fin("decoration.in");
    //ofstream fout("decoration.out");
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>prozorci[i].nr>>prozorci[i].nc;generalcnt+=prozorci[i].nr*prozorci[i].nc;
        //inid=i;
        prozorci[i].inidx=i;
    }
    for(int i=1;i<=m;i++)
    {
        fin>>finn.p>>finn.q>>finn.like;
        finn.inidx=i;
        finn.edinici.clear();
        for(int i1=1;i1<=finn.p;i1++)
        {
            for(int j1=1;j1<=finn.q;j1++)
            {
                fin>>finn.a[i1][j1];
                if(finn.a[i1][j1]==1)finn.edinici.push_back(make_pair(i1,j1)),generalcnt++;
            }
        }
        forma.push_back(finn);
    }
}
bool getcorner(int &xx,int &yy,int ip,int idf)
{
    int l;
    if(prozorci[ip].nr*prozorci[ip].nc-prozorci[ip].bred<forma[idf].edinici.size())return false;
    for(int i=1;i<=prozorci[ip].nr-forma[idf].p+1;i++)
    {
        for(int j=1;j<=prozorci[ip].nc-forma[idf].q+1;j++)
        {
            l=1;
            //if(prozorci[ip].bred>forma[idf].edinici.size())continue;
            //cout<<"matrix from node "<<i<<" "<<j<<" of size "<<forma[idf].p<<" "<<forma[idf].q<<endl;
            for(int i1=0;i1<forma[idf].edinici.size();i1++)
            {
                //cout<<"eee"<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
                if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
                {
                    sort(planet.begin(),planet.end(),cmp);
                    output();exit(0);
                }
                //cout<<prozorci[ip].a[i1][j1]<<" ";
                //if(i1>prozorci[ip].nr&&j1>prozorci[ip].nc&&i1-i+1>forma[idf].p&&j1-j+1>forma[idf].q)cout<<"Aaaa"<<endl;
                if(prozorci[ip].a[i+forma[idf].edinici[i1].first-1][j+forma[idf].edinici[i1].second-1]==1){l=0;break;}
            }
                //cout<<endl;
            //cout<<ip<<" i="<<i<<" j="<<j<<" l="<<l<<"\n";
            if(l==1)
            {
                xx=i;
                yy=j;
                return true;
            }
        }
    }
    return false;
}
bool getcorner2(int &xx,int &yy,int ip,int idf)
{
    int l;if(prozorci[ip].nr*prozorci[ip].nc-prozorci[ip].bred<forma[idf].edinici.size())return false;
    for(int j=1;j<=prozorci[ip].nc-forma[idf].q+1;j++)
    {
        for(int i=1;i<=prozorci[ip].nr-forma[idf].p+1;i++)
        {
            l=1;
            //if(prozorci[ip].bred>forma[idf].edinici.size())continue;
            //cout<<"matrix from node "<<i<<" "<<j<<" of size "<<forma[idf].p<<" "<<forma[idf].q<<endl;
            for(int i1=0;i1<forma[idf].edinici.size();i1++)
            {
                //cout<<"eee"<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
                if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
                {
                    sort(planet.begin(),planet.end(),cmp);
                    output();exit(0);
                }
                //cout<<prozorci[ip].a[i1][j1]<<" ";
                //if(i1>prozorci[ip].nr&&j1>prozorci[ip].nc&&i1-i+1>forma[idf].p&&j1-j+1>forma[idf].q)cout<<"Aaaa"<<endl;
                if(prozorci[ip].a[i+forma[idf].edinici[i1].first-1][j+forma[idf].edinici[i1].second-1]==1){l=0;break;}
            }
                //cout<<endl;
            //cout<<ip<<" i="<<i<<" j="<<j<<" l="<<l<<"\n";
            if(l==1)
            {
                xx=i;
                yy=j;
                return true;
            }
        }
    }
    return false;
}
bool getcorner3(int &xx,int &yy,int ip,int idf)
{
    int l;if(prozorci[ip].nr*prozorci[ip].nc-prozorci[ip].bred<forma[idf].edinici.size())return false;
    for(int i=prozorci[ip].nr-forma[idf].p+1;i>=1;i--)
    {
        for(int j=1;j<=prozorci[ip].nc-forma[idf].q+1;j++)
        {
            l=1;
            //if(prozorci[ip].bred>forma[idf].edinici.size())continue;
            //cout<<"matrix from node "<<i<<" "<<j<<" of size "<<forma[idf].p<<" "<<forma[idf].q<<endl;
            for(int i1=0;i1<forma[idf].edinici.size();i1++)
            {
                //cout<<"eee"<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
                if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
                {
                    sort(planet.begin(),planet.end(),cmp);
                    output();exit(0);
                }
                //cout<<prozorci[ip].a[i1][j1]<<" ";
                //if(i1>prozorci[ip].nr&&j1>prozorci[ip].nc&&i1-i+1>forma[idf].p&&j1-j+1>forma[idf].q)cout<<"Aaaa"<<endl;
                if(prozorci[ip].a[i+forma[idf].edinici[i1].first-1][j+forma[idf].edinici[i1].second-1]==1){l=0;break;}
            }
                //cout<<endl;
            //cout<<ip<<" i="<<i<<" j="<<j<<" l="<<l<<"\n";
            if(l==1)
            {
                xx=i;
                yy=j;
                return true;
            }
        }
    }
    return false;
}
bool getcorner4(int &xx,int &yy,int ip,int idf)
{
    int l;if(prozorci[ip].nr*prozorci[ip].nc-prozorci[ip].bred<forma[idf].edinici.size())return false;
    for(int i=prozorci[ip].nr-forma[idf].p+1;i>=1;i--)
    {
        for(int j=prozorci[ip].nc-forma[idf].q+1;j>=1;j--)
        {
            l=1;

            //cout<<"matrix from node "<<i<<" "<<j<<" of size "<<forma[idf].p<<" "<<forma[idf].q<<endl;
            for(int i1=0;i1<forma[idf].edinici.size();i1++)
            {
                //cout<<"eee"<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
                if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
                {
                    sort(planet.begin(),planet.end(),cmp);
                    output();exit(0);
                }
                //cout<<prozorci[ip].a[i1][j1]<<" ";
                //if(i1>prozorci[ip].nr&&j1>prozorci[ip].nc&&i1-i+1>forma[idf].p&&j1-j+1>forma[idf].q)cout<<"Aaaa"<<endl;
                if(prozorci[ip].a[i+forma[idf].edinici[i1].first-1][j+forma[idf].edinici[i1].second-1]==1){l=0;break;}
            }
                //cout<<endl;
            //cout<<ip<<" i="<<i<<" j="<<j<<" l="<<l<<"\n";
            if(l==1)
            {
                xx=i;
                yy=j;
                return true;
            }
        }
    }
    return false;
}
int computefor(creature &pp)
{
    //generalcnt++;
    //cout<<generalcnt<<endl;
    creature ppe=pp;
    int cx=-1,cy=-1;
    unsigned int lala;
    bool toput;
    ppe.evolst=0;memset(ppe.evans,0,sizeof(ppe.evans));
    for(int i=1;i<=n;i++)memset(prozorci[i].a,0,sizeof(prozorci[i].a)),prozorci[i].slike=0,prozorci[i].brf=0,prozorci[i].bred=0;
    for(int f=1;f<=m;f++)for(int k=1;k<=n;k++)
    {
        //cout<<"EEEEEEEE "<<forma[ppe.tip[f]].p<<" "<<forma[ppe.tip[f]].q<<" "<<k<<endl;
        ////cout<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
        cx=-1,cy=-1;
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
        {
            sort(planet.begin(),planet.end(),cmp);
            output();exit(0);
        }
        toput=false;//lala=rand()%2;
        toput=getcorner(cx,cy,k,ppe.tip[f]);
        if(toput==true&&forma[ppe.tip[f]].p<=prozorci[k].nr&&forma[ppe.tip[f]].q<=prozorci[k].nc)
        {
            ppe.evans[ppe.tip[f]][1]=prozorci[k].inidx;
            ppe.evans[ppe.tip[f]][2]=cx;
            ppe.evans[ppe.tip[f]][3]=cy;
            //cout<<f<<"->"<<ppe.tip[f]<<" "<<cx<<" a "<<cy<<" b "<<k<<"\n";
            prozorci[k].slike+=forma[ppe.tip[f]].like;
            prozorci[k].brf++;
            for(int i=0;i<forma[ppe.tip[f]].edinici.size();i++)
            {
                prozorci[k].a[forma[ppe.tip[f]].edinici[i].first+cx-1][forma[ppe.tip[f]].edinici[i].second+cy-1]=1;
                //prozorci[k].bred++;
            }
            prozorci[k].bred+=forma[ppe.tip[f]].edinici.size();
            break;
        }
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
        {
            if(ppe.evolst>pp.evolst)pp=ppe;
            sort(planet.begin(),planet.end(),cmp);
            output();exit(0);
        }
    }
    ppe.evolst=0;
    for(int i=1;i<=n;i++)ppe.evolst+=prozorci[i].brf*prozorci[i].slike;
    pp=ppe;
    return pp.evolst;
}
void output()
{
    ofstream fout("decoration.out");
    for(int i=0;i<m;i++)
    {
        if(planet[0].evans[i][1]==0)fout<<"-1 -1 -1\n";
        else
        {
            fout<<planet[0].evans[i][1]<<" "<<planet[0].evans[i][2]<<" "<<planet[0].evans[i][3]<<"\n";
        }
    }
}
void solvesaspalnoiz4erpvane()
{
    creature sb;
    planet.push_back(sb);
    for(int i=1;i<=m;i++)sb.tip[i]=i-1;
    do
    {
        computefor(sb);
        if(sb.evans>planet[0].evans)planet[0]=sb;
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
        {
            sort(planet.begin(),planet.end(),cmp);
            output();exit(0);
        }
    }while(next_permutation(sb.tip+1,sb.tip+m+1));
    output();
}
void solve()
{
    int tos[111];srand(47);
    sort(prozorci+1,prozorci+n+1,cmpzaprozorci);
    creature sb;
    if(m<=8)
    {
        solvesaspalnoiz4erpvane();
        exit(0);
    }
    int granica=200;
    int plus=0;//cout<<"generalcnt="<<generalcnt<<endl;
    if(generalcnt>=100000)plus=15;
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int j=1;j<=m;j++)sb.tip[j]=j-1;
        memset(sb.evans,0,sizeof(sb.evans));
        sb.evolst=0;
        planet.push_back(sb);
    for(int i=1;i<=m;i++){tos[i]=i-1;}//if(i==1)cout<<tos[i]<<" ";}cout<<endl;//return;
    sort(tos+1,tos+m+1,cmpzatos);
    for(int j=1;j<=m;j++)sb.tip[j]=tos[j];
        memset(sb.evans,0,sizeof(sb.evans));
        sb.evolst=0;
        planet.push_back(sb);/*
    sort(tos+1,tos+m+1,cmpzatos2);
    for(int j=1;j<=m;j++)sb.tip[j]=tos[j];
        memset(sb.evans,0,sizeof(sb.evans));
        sb.evolst=0;
        planet.push_back(sb);*/
    for(int i=1;i<=granica;i++)
    {
        random_shuffle(tos+1,tos+m+1);
        for(int j=1;j<=m;j++)sb.tip[j]=tos[j];
        memset(sb.evans,0,sizeof(sb.evans));
        sb.evolst=0;
        planet.push_back(sb);
        //cout<<"-----------------------------"<<endl;
    }
    granica=planet.size();
    for(int i=0;i<granica;i++)
    {
        computefor(planet[i]);
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
        {
            sort(planet.begin(),planet.end(),cmp);
            output();exit(0);
        }

    }
    //cout<<"rR"<<endl;
    sort(planet.begin(),planet.end(),cmp);
    int ridxpl;
    int ridxc1,ridxc2,prevdz,moe,b51;
    while((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<4.98)
    {
        //cout<<(double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<<endl;
        b51=granica/2;
        planet.erase(planet.begin()+b51+plus,planet.end());
        cout<<planet[0].evolst<<"\n";
        prevdz=planet.size();
        while(planet.size()<granica)
        {
            moe=5;

                ridxpl=rand()%prevdz;
                sb=planet[ridxpl];
                memset(sb.evans,0,sizeof(sb.evans));
                sb.evolst=-11;
                ridxc1=rand()%m+1;
                ridxc2=rand()%m+1;
                swap(sb.tip[ridxc1],sb.tip[ridxc2]);
                planet.push_back(sb);
            /*else
            {
                ridxpl=rand()%prevdz;
                sb=planet[ridxpl];
                memset(sb.evans,0,sizeof(sb.evans));
                sb.evolst=-11;
                ridxc1=rand()%m+1;
                ridxc2=ridxc1+rand()%(m-ridxc1);
                cout<<"begin shuffle"<<" "<<ridxc1<<" "<<ridxc2<<" "<<m<<endl;
                random_shuffle(sb.tip+9,sb.tip+11);
                cout<<"end shuffle"<<endl;
            }*/

        }

        for(int i=b51+plus-1;i<granica;i++)
        {
            computefor(planet[i]);
            if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>4.98)
            {
                sort(planet.begin(),planet.end(),cmp);
                output();exit(0);
            }
        }
        sort(planet.begin(),planet.end(),cmp);
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>2.99)
        {
            granica=100;
            if(generalcnt>=100000)plus=5;
        }
    }
    output();exit(0);

}
/*
*/
int main()
{
    tim=clock();
    read();
    solve();

}
