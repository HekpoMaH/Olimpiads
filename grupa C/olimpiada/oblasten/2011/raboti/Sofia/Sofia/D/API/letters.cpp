#include <string>
#include <iostream>

using namespace std;

int num;
char ch;

string words[10001][4];

void caseSensitiveFix ()
{
    for (int i = 0; i < num; i ++)
    {
        for (int j = 0; j < 4; j ++)
        {
            for (int k = 0; k < words[i][j].size (); k ++)
            {
                if (words[i][j][k] >= 'A' && words[i][j][k] <= 'Z')
                {
                    words[i][j][k] -= ('A' - 'a');
                }
            }
        }
    }
}

int main ()
{
    cin >> num >> ch;

    int i, j;
    for (i = 0; i < num; i ++)
    {
        for (j = 0; j < 4; j ++)
        {
            cin >> words[i][j];
        }
    }

    caseSensitiveFix ();

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    for (i = 0; i < num; i ++)
    {
        for (j = 0; j < 4; j ++)
        {
            int temp = 0;
            switch (j)
            {
                case 0:
                    if (words[i][j][0] == ch)
                    {
                        res1 ++;
                    }
                break;

                case 1:
                    for (int k = 0; k < words[i][j].size (); k ++)
                    {
                        if (words[i][j][k] == ch)
                        {
                            res2 ++;
                            break;
                        }
                    }
                break;

                case 2:
                    for (int k = 0; k < words[i][j].size (); k ++)
                    {
                        if (words[i][j][k] == ch)
                        {
                            temp ++;
                        }
                    }
                    if (temp >= 2)
                    {
                        res3 ++;
                    }
                break;

                case 3:
                    if (words[i][j][words[i][j].size () - 1] == ch)
                    {
                        res4 ++;
                    }
                break;
            }
        }
    }

    printf ("%d %d %d %d\n", res1, res2, res3, res4);

    return 0;
}
