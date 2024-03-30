#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[1000], max = 0, start = 0, end = 0 , cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			if (!cnt)
				start = i;
			end = i + 1;
			cnt++;
		}
		else
		{
			max = max < (arr[end] - arr[start]) ? (arr[end] - arr[start]) : max;
			if (cnt)
				cnt = 0;
		}
	}
	max = max < (arr[end] - arr[start]) ? (arr[end] - arr[start]) : max;
	cout << max;
}
