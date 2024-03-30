#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int m, n;
	int* arr;
	cin >> m >> n;
	arr = new int[n+1];
	for (int i = 2; i <= n; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i)
			arr[j] = 0;
	}
	for (int i = m; i <= n; i++)
		if (arr[i] != 0)
			cout << arr[i] << "\n";
	return 0;
}
