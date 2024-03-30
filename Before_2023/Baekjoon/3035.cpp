#include <iostream>
using namespace std;
int main(void)
{
	int r, c, zr, zc;
	char arr[51][51];
	cin >> r >> c >> zr >> zc;

	for (int i = 0; i < r; i++)
		cin >> arr[i];

	for (int i = 0; i < r; i++)
	{
		for (int l = 0; l < zr; l++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int k = 0; k < zc; k++)
					cout << arr[i][j];
			}
			cout << '\n';
		}
	}
}
