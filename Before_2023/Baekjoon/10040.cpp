#include <iostream>
using namespace std;
int main(void)
{
	int n, m, max = -1, maxIdx;
	int a[1000], b[1000], arr[1000] = { 0, };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i] >= a[j])
			{
				arr[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (max < arr[i])
			max = arr[i], maxIdx = i;
	
	cout << maxIdx + 1;
}
