#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int sum = 0, n, i, size;
	vector<int> arr;
	cin >> n;
	while (n > 0)
	{
		for (i = 1; (i*(i + 1) / 2) <= n; i++);
		i--;
		arr.push_back(i);
		n -= (i*(i + 1) / 2);
	}
	size = arr.size();
	for (int i = 0; i < size; i++)
		sum += arr[i];
	cout << sum;
}
