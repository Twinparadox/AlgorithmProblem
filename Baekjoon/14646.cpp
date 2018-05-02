#include <iostream>
using namespace std;
int main(void)
{
	int n, max = 0, current = 0, tmp;
	int arr[100001] = { 0, };
	cin >> n;
	for (int i = 0; i < n*2; i++)
	{
		cin >> tmp;
		if (arr[tmp] == 0)
			current++, arr[tmp]++;
		else
			current--, arr[tmp]++;
		if (current > max)
			max = current;
	}
	cout << max;
}
