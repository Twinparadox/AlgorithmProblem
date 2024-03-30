#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	char arr[10][11];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
			cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
			cout << arr[i][j];
		cout << '\n';
	}
}
