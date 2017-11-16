#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int arr[10001] = { 0, }, n;
	cin >> n;
	for (int i = 0, tmp; i < n; i++)
	{
		cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < arr[i]; j++)
				cout << i << "\n";
}
