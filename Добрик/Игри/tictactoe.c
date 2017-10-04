#include <stdio.h>
/* ������� ����� */
const char startPlayer = 2;
/* �������� ������������ */
char board[3][3] = {
{ '.', '.', '.' },
{ '.', 'X', '.' },
{ 'X', '.', 'O' }};
/* �����: 1, ��� �������������� � ���������� � ������ ����� 1,
* 2, ��� � ���������� � ������ ����� 2,
* 3, ��� � ���������� ������ � ����
* 0, ��� �������������� �� � ����������.
*/
char terminal(char a[3][3])
{ unsigned i, j;
for (i = 0; i < 3; i++) {
/* �������� �� ������������� */
for (j = 0; j < 3; j++)
if (a[i][j] != a[i][0]) break;
if (3 == j && a[i][0] != '.') {
if (a[i][0] == 'X') return 1; else return 2;
}
/* �������� �� ����������� */
for (j = 0; j < 3; j++)
if (a[j][i] != a[0][i]) break;
if (3 == j && a[i][0] != '.') {
if (a[0][i] == 'X') return 1; else return 2;
}
/* �������� �� ����������� */
if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != '.')
if (a[0][0] == 'X') return 1; else return 2;
if (a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[1][1] != '.')
if (a[2][0] == 'X') return 1; else return 2;
}
/* ���� �� � ���� (���� ������ ������� �� �����) */
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
if (a[i][j] == '.') return 0;
return 3;
}
/* �����: 1, ��� �������������� � ��������� �� ������ player,
* 2, ��� � ������ �
* 3, ��� � ������������ */
char checkPosition(char player, char board[3][3])
{ unsigned i, j, result;
int t = terminal(board);
if (t) {
if (player == t) return 1;
if (3 == t) return 3;
if (player != t) return 2;
}
else {
char otherPlayer, playerSign;
if (player == 1) { playerSign = 'X'; otherPlayer = 2; }
else { playerSign = 'O'; otherPlayer = 1; }
/* char board[3][3];
* �������� ���������
*/
for (i = 0; i < 3; i++) {
for (j = 0; j < 3; j++) {
if (board[i][j] == '.') {
board[i][j] = playerSign;
result = checkPosition(otherPlayer, board);
board[i][j] = '.';
if (result == 2) return 1; /* ����. � ������ �� ����������, */
/* ������������ � ��������� �� ������ player */
if (result == 3) return 3; /* �������������� � ������������ */
}
}
}
/* ������ ���������� �� ��������� ������������ �
* ������������ ���� � ������ �� ������ player */
return 2;
}
}
int main(void) {
printf("%u\n", checkPosition(startPlayer, board));
return 0;
}