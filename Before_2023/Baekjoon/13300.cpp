#include <iostream>
using namespace std;
int main(void)
{
	int n, k, min = 0, s, y, tmp;
	int arr[7][2] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;
		arr[y][s]++;
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (arr[i][j] == 0)
				tmp = 0;
			else if (arr[i][j] % k == 0)
				tmp = arr[i][j] / k;
			else
				tmp = (arr[i][j] / k) + 1;
			min += tmp;
		}
	}
	cout << min;
}
