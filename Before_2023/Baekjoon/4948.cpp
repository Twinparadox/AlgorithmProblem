#include <iostream>
#include <math.h>
using namespace std;
int arr[246913];
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n, cnt = 0;
	for (int i = 2; i <= 246913; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(246913); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 246913; j += i)
			arr[j] = 0;
	}
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = n + 1; i <= 2 * n; i++)
			if (arr[i] != 0)
				cnt++;
		cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}
