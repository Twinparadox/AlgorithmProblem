#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int w, h;
	char arr[101][101];
	int min[101][101];

	cin >> w >> h;
	for (int i = 0; i < w; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < h; j++)
		{
			if (arr[i][j] == 'c')
				min[i][j] = 0;
			else
				min[i][j] = -1;
		}
	}
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			if (min[i][j] == 0)
				for (int k = j + 1; k < h && min[i][k] != 0; k++)
					min[i][k] = min[i][k - 1] + 1;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
			cout << min[i][j] << ' ';
		cout << endl;
	}
}