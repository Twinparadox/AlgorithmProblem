#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > paper;
int white, blue;
int scanColor(int size, int startX, int startY)
{
	int mainColor = paper[startX][startY];

	bool flag = true;
	for (int x = startX; flag && x < startX + size; x++)
	{
		for (int y = startY; flag && y < startY + size; y++)
		{
			if (paper[x][y] != mainColor)
			{
				mainColor = -1;
				flag = false;
				break;
			}
		}
	}

	return mainColor;
}
void divide(int size, int startX, int startY)
{
	int color = scanColor(size, startX, startY);
	if (color == -1)
	{
		divide(size / 2, startX, startY);
		divide(size / 2, startX + size / 2, startY);
		divide(size / 2, startX, startY + size / 2);
		divide(size / 2, startX + size / 2, startY + size / 2);
	}
	else if (color == 1)
		blue++;
	else
		white++;
}
int main(void)
{
	int N;

	cin >> N;
	paper = vector<vector<int> >(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	divide(N, 0, 0);

	cout << white << '\n' << blue;
}