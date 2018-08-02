#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, m, s, e, sum = 0, cnt = 0;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	s = 0, e = 0;
	while (1)
	{
		if (sum >= m)
			sum -= arr[e++];
		else if (s == n)
			break;
		else
			sum += arr[s++];
		if (sum == m)
			cnt++;
	}

	cout << cnt;
}
