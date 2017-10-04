#include <iostream>
using namespace std;

int main ()
{

    double lastPrise;
    cin >> lastPrise;

    double momentPrise;
    cin >> momentPrise;

    int num = 1;
    int res = 1;

    while (momentPrise != 0)
    {
        if (lastPrise <= momentPrise)
        {
            num ++;
        } else
        {
            if (res < num)
            {
                res = num;
            }

            num = 1;
        }

        lastPrise = momentPrise;

        cin >> momentPrise;
    }

    cout << res << endl;
    return 0;
}
