#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct letel
{
    char let;
    int st;
};
letel ls[8];
int lsize;
string s1,s2,s3;
string s;
int n,k,s1s,s2s,s3s,sum;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)if(s[i]=='+'){k=i;break;}
    s1=s.substr(0,k);
    s.erase(0,k+1);
    //cout<<s<<endl;
    //cout<<s1<<endl;
    //cout<<k<<endl;
    n=s.size();
    for(int i=0;i<n;i++)if(s[i]=='='){k=i;break;}
    s2=s.substr(0,k);
    s.erase(0,k+1);
    //cout<<s<<endl;
    //cout<<s2<<endl;
    s3=s;
    //cout<<s3<<endl;
    s1s=s1.size();
    s2s=s2.size();
    s3s=s3.size();
    int fl;
    for(int i=0;i<s1s;i++)
    {
        fl=0;
        if(s1[i]>='A'&&s1[i]<='Z')
            {
            if(lsize==0)
            {
                lsize++;
                ls[lsize].let=s1[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
            }
            }
        for(int j=1;j<=lsize;j++)
        {
            if(s1[i]>='A'&&s1[i]<='Z')
            {
            if(s1[i]==ls[j].let)
            {
                fl=1;
            }
            if(i==0&&s1[i]==ls[j].let)ls[j].st=1;
            }
        }
        if(fl==0&&s1[i]>='A'&&s1[i]<='Z')
        {
                lsize++;
                ls[lsize].let=s1[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
        }
    }//cout<<"s2="<<s2s<<endl;
    for(int i=0;i<s2s;i++)
    {
        fl=0;//cout<<i<<" s2="<<s2[i]<<" "<<fl<<endl;
        if(s2[i]>='A'&&s2[i]<='Z')
            {
            if(lsize==0)
            {
                lsize++;
                ls[lsize].let=s2[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
            }
            }
        for(int j=1;j<=lsize;j++)
        {
            if(s2[i]>='A'&&s2[i]<='Z')
            {
            if(s2[i]==ls[j].let)
            {
                fl=1;
            }
            if(i==0&&s2[i]==ls[j].let)ls[j].st=1;
            }
        }
        if(fl==0&&s2[i]>='A'&&s2[i]<='Z')
        {

                lsize++;
                ls[lsize].let=s2[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
        }
    }
    for(int i=0;i<s3s;i++)
    {
        fl=0;
        if(s3[i]>='A'&&s3[i]<='Z')
        {
            if(lsize==0)
            {
                lsize++;
                ls[lsize].let=s3[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
            }
        }
        for(int j=1;j<=lsize;j++)
        {
            if(s3[i]>='A'&&s3[i]<='Z')
            {
            if(s3[i]==ls[j].let)
            {
                fl=1;
            }
            if(i==0&&s3[i]==ls[j].let)ls[j].st=1;
            }
        }
        if(fl==0&&s3[i]>='A'&&s3[i]<='Z')
        {
                lsize++;
                ls[lsize].let=s3[i];
                if(i==0)ls[lsize].st=1;
                else ls[lsize].st=0;
                //break;
        }
    }
    int parvo=0,vtoro=0,treto=0,help,brc,br;
    //for(int i=1;i<=lsize;i++)cout<<ls[i].let<<" "<<ls[i].st<<endl;
    int checker[11];
    for(int first=ls[1].st;first<=9;first++)
    {
        if(lsize==1)
        {
                        parvo=0;vtoro=0;treto=0;
                        for(int i=0;i<=11;i++)checker[i]=0;
                        for(int i=0;i<s1s;i++)
                        {
                            if(s1[i]>='0'&&s1[i]<='9'){parvo=parvo*10+s1[i]-'0';}
                            if(s1[i]>='A'&&s1[i]<='Z')
                            {
                                if(s1[i]==ls[1].let)help=first;
                                //if(s1[i]==ls[2].let)help=second;
                                //if(s1[i]==ls[3].let)help=third;
                                //if(s1[i]==ls[4].let)help=forth;
                                //if(s1[i]==ls[5].let)help=fifth;
                                parvo=parvo*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s2s;i++)
                        {
                            if(s2[i]>='0'&&s2[i]<='9'){vtoro=vtoro*10+s2[i]-'0';}
                            if(s2[i]>='A'&&s2[i]<='Z')
                            {
                                if(s2[i]==ls[1].let)help=first;
                                //if(s2[i]==ls[2].let)help=second;
                                //if(s2[i]==ls[3].let)help=third;
                                //if(s2[i]==ls[4].let)help=forth;
                                //if(s2[i]==ls[5].let)help=fifth;
                                vtoro=vtoro*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s3s;i++)
                        {
                            if(s3[i]>='0'&&s3[i]<='9'){treto=treto*10+s3[i]-'0';}
                            if(s3[i]>='A'&&s3[i]<='Z')
                            {
                                if(s3[i]==ls[1].let)help=first;
                                //if(s3[i]==ls[2].let)help=second;
                                //if(s3[i]==ls[3].let)help=third;
                                //if(s3[i]==ls[4].let)help=forth;
                                //if(s3[i]==ls[5].let)help=fifth;
                                treto=treto*10+help;
                                //checker[help]++;
                            }
                        }
                        if(lsize>=1)checker[first]++;
                        //if(lsize>=2)checker[second]++;
                        //if(lsize>=3)checker[third]++;
                        //if(lsize>=4)checker[forth]++;
                        //if(lsize>=5)checker[fifth]++;
                        br=0;
                        for(int i=0;i<=9;i++)if(checker[i]>=1)br++;
                        //if(br==lsize){cout<<parvo<<" "<<vtoro<<" "<<treto<<" "<<br<<endl;system("pause");}
                        if(parvo+vtoro==treto&&br==lsize){sum++;}
                    }
        for(int second=ls[2].st;second<=9;second++)
        {
            if(lsize==2)
            {
                        parvo=0;vtoro=0;treto=0;
                        for(int i=0;i<=11;i++)checker[i]=0;
                        for(int i=0;i<s1s;i++)
                        {
                            if(s1[i]>='0'&&s1[i]<='9'){parvo=parvo*10+s1[i]-'0';}
                            if(s1[i]>='A'&&s1[i]<='Z')
                            {
                                if(s1[i]==ls[1].let)help=first;
                                if(s1[i]==ls[2].let)help=second;
                                //if(s1[i]==ls[3].let)help=third;
                                //if(s1[i]==ls[4].let)help=forth;
                                //if(s1[i]==ls[5].let)help=fifth;
                                parvo=parvo*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s2s;i++)
                        {
                            if(s2[i]>='0'&&s2[i]<='9'){vtoro=vtoro*10+s2[i]-'0';}
                            if(s2[i]>='A'&&s2[i]<='Z')
                            {
                                if(s2[i]==ls[1].let)help=first;
                                if(s2[i]==ls[2].let)help=second;
                                //if(s2[i]==ls[3].let)help=third;
                                //if(s2[i]==ls[4].let)help=forth;
                                //if(s2[i]==ls[5].let)help=fifth;
                                vtoro=vtoro*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s3s;i++)
                        {
                            if(s3[i]>='0'&&s3[i]<='9'){treto=treto*10+s3[i]-'0';}
                            if(s3[i]>='A'&&s3[i]<='Z')
                            {
                                if(s3[i]==ls[1].let)help=first;
                                if(s3[i]==ls[2].let)help=second;
                                //if(s3[i]==ls[3].let)help=third;
                                //if(s3[i]==ls[4].let)help=forth;
                                //if(s3[i]==ls[5].let)help=fifth;
                                treto=treto*10+help;
                                //checker[help]++;
                            }
                        }
                        if(lsize>=1)checker[first]++;
                        if(lsize>=2)checker[second]++;
                        //if(lsize>=3)checker[third]++;
                        //if(lsize>=4)checker[forth]++;
                        //if(lsize>=5)checker[fifth]++;
                        br=0;
                        for(int i=0;i<=9;i++)if(checker[i]>=1)br++;
                        //if(br==lsize){cout<<parvo<<" "<<vtoro<<" "<<treto<<" "<<br<<endl;system("pause");}
                        if(parvo+vtoro==treto&&br==lsize){sum++;}
                    }
            
            for(int third=ls[3].st;third<=9;third++)
            {
                if(lsize==3)
                {
                        parvo=0;vtoro=0;treto=0;
                        for(int i=0;i<=11;i++)checker[i]=0;
                        for(int i=0;i<s1s;i++)
                        {
                            if(s1[i]>='0'&&s1[i]<='9'){parvo=parvo*10+s1[i]-'0';}
                            if(s1[i]>='A'&&s1[i]<='Z')
                            {
                                if(s1[i]==ls[1].let)help=first;
                                if(s1[i]==ls[2].let)help=second;
                                if(s1[i]==ls[3].let)help=third;
                                //if(s1[i]==ls[4].let)help=forth;
                                //if(s1[i]==ls[5].let)help=fifth;
                                parvo=parvo*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s2s;i++)
                        {
                            if(s2[i]>='0'&&s2[i]<='9'){vtoro=vtoro*10+s2[i]-'0';}
                            if(s2[i]>='A'&&s2[i]<='Z')
                            {
                                if(s2[i]==ls[1].let)help=first;
                                if(s2[i]==ls[2].let)help=second;
                                if(s2[i]==ls[3].let)help=third;
                                //if(s2[i]==ls[4].let)help=forth;
                                //if(s2[i]==ls[5].let)help=fifth;
                                vtoro=vtoro*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s3s;i++)
                        {
                            if(s3[i]>='0'&&s3[i]<='9'){treto=treto*10+s3[i]-'0';}
                            if(s3[i]>='A'&&s3[i]<='Z')
                            {
                                if(s3[i]==ls[1].let)help=first;
                                if(s3[i]==ls[2].let)help=second;
                                if(s3[i]==ls[3].let)help=third;
                                //if(s3[i]==ls[4].let)help=forth;
                                //if(s3[i]==ls[5].let)help=fifth;
                                treto=treto*10+help;
                                //checker[help]++;
                            }
                        }
                        if(lsize>=1)checker[first]++;
                        if(lsize>=2)checker[second]++;
                        if(lsize>=3)checker[third]++;
                        //if(lsize>=4)checker[forth]++;
                        //if(lsize>=5)checker[fifth]++;
                        br=0;
                        for(int i=0;i<=9;i++)if(checker[i]>=1)br++;
                        //if(br==lsize){cout<<parvo<<" "<<vtoro<<" "<<treto<<" "<<br<<endl;system("pause");}
                        if(parvo+vtoro==treto&&br==lsize){sum++;}
                    }
                for(int forth=ls[4].st;forth<=9;forth++)
                {
                    if(lsize==4)
                    {
                        parvo=0;vtoro=0;treto=0;
                        for(int i=0;i<=11;i++)checker[i]=0;
                        for(int i=0;i<s1s;i++)
                        {
                            if(s1[i]>='0'&&s1[i]<='9'){parvo=parvo*10+s1[i]-'0';}
                            if(s1[i]>='A'&&s1[i]<='Z')
                            {
                                if(s1[i]==ls[1].let)help=first;
                                if(s1[i]==ls[2].let)help=second;
                                if(s1[i]==ls[3].let)help=third;
                                if(s1[i]==ls[4].let)help=forth;
                                //if(s1[i]==ls[5].let)help=fifth;
                                parvo=parvo*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s2s;i++)
                        {
                            if(s2[i]>='0'&&s2[i]<='9'){vtoro=vtoro*10+s2[i]-'0';}
                            if(s2[i]>='A'&&s2[i]<='Z')
                            {
                                if(s2[i]==ls[1].let)help=first;
                                if(s2[i]==ls[2].let)help=second;
                                if(s2[i]==ls[3].let)help=third;
                                if(s2[i]==ls[4].let)help=forth;
                                //if(s2[i]==ls[5].let)help=fifth;
                                vtoro=vtoro*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s3s;i++)
                        {
                            if(s3[i]>='0'&&s3[i]<='9'){treto=treto*10+s3[i]-'0';}
                            if(s3[i]>='A'&&s3[i]<='Z')
                            {
                                if(s3[i]==ls[1].let)help=first;
                                if(s3[i]==ls[2].let)help=second;
                                if(s3[i]==ls[3].let)help=third;
                                if(s3[i]==ls[4].let)help=forth;
                                //if(s3[i]==ls[5].let)help=fifth;
                                treto=treto*10+help;
                                //checker[help]++;
                            }
                        }
                        if(lsize>=1)checker[first]++;
                        if(lsize>=2)checker[second]++;
                        if(lsize>=3)checker[third]++;
                        if(lsize>=4)checker[forth]++;
                        //if(lsize>=5)checker[fifth]++;
                        br=0;
                        for(int i=0;i<=9;i++)if(checker[i]>=1)br++;
                        //if(br==lsize){cout<<parvo<<" "<<vtoro<<" "<<treto<<" "<<br<<endl;system("pause");}
                        if(parvo+vtoro==treto&&br==lsize){sum++;}
                    }
                    
                    if(lsize==5)
                    for(int fifth=ls[5].st;fifth<=9;fifth++)
                    {
                        parvo=0;vtoro=0;treto=0;
                        for(int i=0;i<=11;i++)checker[i]=0;
                        for(int i=0;i<s1s;i++)
                        {
                            if(s1[i]>='0'&&s1[i]<='9'){parvo=parvo*10+s1[i]-'0';}
                            if(s1[i]>='A'&&s1[i]<='Z')
                            {
                                if(s1[i]==ls[1].let)help=first;
                                if(s1[i]==ls[2].let)help=second;
                                if(s1[i]==ls[3].let)help=third;
                                if(s1[i]==ls[4].let)help=forth;
                                if(s1[i]==ls[5].let)help=fifth;
                                parvo=parvo*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s2s;i++)
                        {
                            if(s2[i]>='0'&&s2[i]<='9'){vtoro=vtoro*10+s2[i]-'0';}
                            if(s2[i]>='A'&&s2[i]<='Z')
                            {
                                if(s2[i]==ls[1].let)help=first;
                                if(s2[i]==ls[2].let)help=second;
                                if(s2[i]==ls[3].let)help=third;
                                if(s2[i]==ls[4].let)help=forth;
                                if(s2[i]==ls[5].let)help=fifth;
                                vtoro=vtoro*10+help;
                                //checker[help]++;
                            }
                        }
                        for(int i=0;i<s3s;i++)
                        {
                            if(s3[i]>='0'&&s3[i]<='9'){treto=treto*10+s3[i]-'0';}
                            if(s3[i]>='A'&&s3[i]<='Z')
                            {
                                if(s3[i]==ls[1].let)help=first;
                                if(s3[i]==ls[2].let)help=second;
                                if(s3[i]==ls[3].let)help=third;
                                if(s3[i]==ls[4].let)help=forth;
                                if(s3[i]==ls[5].let)help=fifth;
                                treto=treto*10+help;
                                //checker[help]++;
                            }
                        }
                        if(lsize>=1)checker[first]++;
                        if(lsize>=2)checker[second]++;
                        if(lsize>=3)checker[third]++;
                        if(lsize>=4)checker[forth]++;
                        if(lsize>=5)checker[fifth]++;
                        br=0;
                        for(int i=0;i<=9;i++)if(checker[i]>=1)br++;
                        //if(br==lsize){cout<<parvo<<" "<<vtoro<<" "<<treto<<" "<<br<<endl;system("pause");}
                        if(parvo+vtoro==treto&&br==lsize){sum++;}
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
//ABC+BCA=1000
//3BBCC+58DC3=CDEC2
//1XXW+WUV=2VU6
//ABCD+BDC=EAEA
//AB+ABC=6DD
