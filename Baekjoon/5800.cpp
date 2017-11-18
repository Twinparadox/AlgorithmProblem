#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main(void)
{
	int list[100][50];
	int clas[100][3];
	int n, k, gap;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		gap = -1;
		for (int j = 0; j < n; j++)
			cin >> list[i][j];
		sort(list[i], list[i] + n, greater<int>());
		for (int j = 1; j < n; j++)
			gap = gap < (list[i][j - 1] - list[i][j]) ? (list[i][j - 1] - list[i][j]) : gap;
		clas[i][0] = list[i][0], clas[i][1] = list[i][n - 1], clas[i][2] = gap;
	}
	for (int i = 0; i < k; i++)
		cout << "Class " << i + 1 << '\n' << "Max " << clas[i][0] << ", Min " << clas[i][1] << ", Largest gap " << clas[i][2] << '\n';
}
