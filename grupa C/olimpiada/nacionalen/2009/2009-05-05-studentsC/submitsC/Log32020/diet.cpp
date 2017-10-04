/*
TASK: diet
LANG: C++
*/
#include <cstdio>
int one;
int two;
int three;
int days;
int min(int a, int b) {
    if (a < b) return a;
    return b;
}
int main() {
    scanf("%d %d %d", &one, &two, &three);
    days = one + 2 * two + 3 * three;
    days /= 6;
    printf("%d ", days);
    int mini = min(min(one, two), three);
    one -= mini;
    two -= mini;
    three -= mini;
    days -= mini;
    if (three == 0) {
        mini = min(one, two);
        one -= mini;
        two -= mini;
        if (two == 0) {
            printf("0");
        } else {
            if ((two + 1) % 3 == 0) {
                two++;
            } else if ((two - 1) % 3 == 0) two--;
            printf("%d", two / 3);
        }
    } else if (two == 0) {
        
    } else {
        
    }
    puts("");
    return 0;
}
