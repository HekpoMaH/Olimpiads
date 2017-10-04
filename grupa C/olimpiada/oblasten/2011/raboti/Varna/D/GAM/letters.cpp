#include <cstdlib>
#include <iostream>

using namespace std;

int answ[4]={0};
char word[1024];
char letter;

int uppercase(char a)
{
    if(a>=97) a-=32;
    return a;}

int main()
{
    int n,i,j,k=0;
    cin>>n;
    cin>>letter;
    letter=uppercase(letter);
    for(i=0;i<n;i++)
    {
        cin>>word;
        word[0]=uppercase(word[0]);
        if(word[0]==letter) answ[0]++;
        cin>>word;
        for(j=0;j<strlen(word);j++){
                                        word[j]=uppercase(word[j]);
                                        if(word[j]==letter){ answ[1]++; break;}
                                        }
        cin>>word;
        k=0;
        for(j=0;j<strlen(word);j++){
                                        word[j]=uppercase(word[j]);
                                        if(word[j]==letter) k++;
                                        if(k>=2) { answ[2]++; break;}
                                        }
        cin>>word;
        j=strlen(word)-1;
        word[j]=uppercase(word[j]);
        if(word[j]==letter) answ[3]++;

    }
    cout<<answ[0]<<" "<<answ[1]<<" "<<answ[2]<<" "<<answ[3]<<endl;
    return 0;
}
