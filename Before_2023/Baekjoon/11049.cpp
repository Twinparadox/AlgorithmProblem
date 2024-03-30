#include <iostream>
#include <climits>
using namespace std;
int dp(int arr[], int size)
{
	int** table;
	int i, j, k, L, tmp, result;

	table = new int*[size + 1];
	for (int i = 0; i < size + 1; i++)
		table[i] = new int[size + 1];

	for (int i = 1; i <= size; i++)
		table[i][i] = 0;

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size - i; j++)
		{
			int k = i + j;
			table[j][k] = INT_MAX;
			for (int L = j; L <= k - 1; L++)
			{
				tmp = table[j][L] + table[L + 1][k] + arr[j - 1] * arr[L] * arr[k];
				if (tmp < table[j][k])
					table[j][k] = tmp;
			}
		}
	}

	result = table[1][size - 1];
	
	for (int i = 0; i < size + 1; i++)
		delete table[i];
	delete table;
	
	return result;
}
int main(void)
{
	int n, a, b;
	int arr[501];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = a;
	}
	arr[n] = b;
	cout<<dp(arr, n + 1);
}
