#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	long long q, next;

	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (arr[0] * arr[2] == arr[1] * arr[1])
	{
		q = arr[1] / arr[0];
		next = arr[n - 1] * q;
	}
	else
	{
		q = arr[1] - arr[0];
		next = arr[n - 1] + q;
	}
	cout << next;
}