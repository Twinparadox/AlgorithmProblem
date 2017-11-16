#include <iostream>
#include <math.h>
using namespace std;
int arr[100001] = { 0, };
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n, t;
	cin >> t;
	for (int i = 2; i <= 100000; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(100000); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 100000; j += i)
			arr[j] = 0;
	}
	while (t--)
	{
		cin >> n;
		int i = 2;
		int list[100001] = { 0, };
		while (n > 1)
		{
			if (arr[i] != 0 && n%arr[i] == 0)
				list[i]++, n /= i;
			else
				i++;
		}
		for (int j = 2; j <= i; j++)
			if (list[j] > 0)
				cout << j << " " << list[j] << "\n";
	}
	return 0;
}
