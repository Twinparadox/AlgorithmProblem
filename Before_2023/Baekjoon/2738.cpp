#include <iostream>
using namespace std;
int main(void)
{
	int arr1[100][100], arr2[100][100], n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr1[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr2[i][j], arr1[i][j] += arr2[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr1[i][j] << " ";
		cout << "\n";
	}
}
