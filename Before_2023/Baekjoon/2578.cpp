#include <iostream>
using namespace std;
int board[5][5];
bool isCheck[5][5];
int calls[25];
void check(int n)
 {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (board[i][j] == n)
				isCheck[i][j] = true;
}
int bingo()
{
	int cnt, lines = 0;
	for (int i = 0; i < 5; i++)
	{
		for (cnt = 0; cnt < 5; cnt++)
			if (isCheck[i][cnt] == false)
				break;
		if (cnt == 5)
			lines++;
		for (cnt = 0; cnt < 5; cnt++)
			if (isCheck[cnt][i] == false)
				break;
		if (cnt == 5)
			lines++;
	}

	for (cnt = 0; cnt < 5; cnt++)
		if (isCheck[cnt][cnt] == false)
			break;
	if (cnt == 5)
		lines++;

	for (cnt = 0; cnt < 5; cnt++)
		if (isCheck[4 - cnt][cnt] == false)
			break;
	if (cnt == 5)
 		lines++;

	return lines;
}
int main(void)
{
	int cnt;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
			isCheck[i][j] = false;
		}
	}

	for (int i = 0; i < 25; i++)
		cin >> calls[i];

	for (cnt = 0; cnt < 25; cnt++)
	{
		check(calls[cnt]);
		if (bingo() >= 3)
		{
			cout << cnt + 1;
			break;
		}
	}
}
