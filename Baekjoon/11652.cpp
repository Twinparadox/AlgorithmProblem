#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int cnt = 1, n, max = 0;
	long long* list, ans;
	cin >> n;
	list = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	ans = list[0], max = 1;
	for (int i = 1; i < n; i++)
	{
		if (list[i] == list[i - 1])
			cnt++;
		else
			cnt = 1;
		if (max < cnt)
			max = cnt, ans = list[i];
	}
	cout << ans;
}
