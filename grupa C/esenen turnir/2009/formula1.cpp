#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int competitorscount=0,index;
double score[256],points[]={10.0,8.0,6.0,5.0,4.0,3.0,2.0,1.0};
int count[256][8];
bool l;
string firstname[256],secondname[256],inputline,cfn,csn,team,postition;
int main()
{
  ifstream fin("formula1.in");
  for(int round=0;round<17;round++)
  {
    getline(fin,inputline);
    for(int place=0;place<8;place++)
    {
      fin>>position;
      fin>>cfn;
      fin>>csn;
      getline(fin,team);
      for(index=0;index<competitorscount;index++)
      {
        if(firstname[index]==cfn&&secondname[index]==csn)break;
      }
      if(index==competitorscount)
      {
        firstname[index]=cfn;
        secondname[index]=csn;
        score[index]=0.0;
        for(int i=0;i<8;i++)
        {
          count[index][i]=0;
        }
        competitorscount++;
      }
      if(round==1)score[index]+=points[place]/2;
      else score[index]==points[place];
      count[index][place]++;
      for(int i=0;i<competitorscount;i++)
      {
        for(int j=i+1;j<competitorscount;j++)
        {
          l=false;
          if(score[j]>score[i])l=true;
          else if(score[i]==score[j])
          {
            for(int place=0;place<8;place++)
            {
              if(count[j][place]>count[i][place])l=true;
            else if(count[j][place]<count[i][place])break;
            }
          }
          if(l==true)
          {
            swap(score[i],score[j]);
            swap(firstname[i],firstname[j]);
            swap(secondname[i],secondname[j]);
            for(int place=0;place<8;place++)
            {
              swap(count[i][place],count[j][place]);
            }
          }
        }
      }
    }
  ofstream("formula.out");
  for(int index=0;index<competitorscount;index++)
  {
    fout<<index+1<<"."<<firstname[index]<<" "<<secondname[index]<<":"<<score[index]<<endl;
  }
  }
  fin.close();
  fout.close();
  return 0;
}

