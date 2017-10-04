#include <iostream>
#include <cstring>
using namespace std;

int one, two, three, four;

int main ()
{

    int n;
    cin >> n;

    char letter;
    cin >> letter;

    char word[50];

    int num;

    for (int i = 0; i < n; i ++)
    {
        cin >> word;

        if (word[0] == letter || word[0] == 'A' + (letter - 'a'))
        {
            one ++;
        }

        cin >> word;

        for (int j = 0; word[j] != '\0'; j ++)
        {
            if (word[j] == letter || word[j] == 'A' + (letter - 'a'))
            {
                two ++;
                break;
            }
        }

        cin >> word;

        num = 0;

        for (int j = 0; word[j] != '\0'; j ++)
        {
            if (word[j] == letter || word[j] == 'A' + (letter - 'a'))
            {
                num ++;
            }
        }

        if (num >= 2)
        {
            three ++;
        }

        cin >> word;

        if (word[strlen(word) - 1] == letter || word[strlen(word) - 1] == 'A' + (letter - 'a'))
        {
            four ++;
        }
    }

    cout << one << " " << two << " " << three << " " << four << endl;
    return 0;
}
