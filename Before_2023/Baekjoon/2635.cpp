#include <iostream>
using namespace std;
int main(void)
{
	int N, max = 2, p;
	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		int cnt = 2, next, cur1 = N, cur2 = i;
		while (1)
		{
			next = cur1 - cur2;
			if (next < 0)
				break;
			cnt++;
			cur1 = cur2;
			cur2 = next;
		}

		if (max < cnt)
		{
			max = cnt;
			p = i;
		}
	}

	int cur1 = N, cur2 = p;
	cout << max << '\n';
	cout << cur1 << ' ' << cur2 << ' ';
	while (1)
	{
		int next = cur1 - cur2;
		if (next < 0)
			break;
		else
			cout << next << ' ';
		cur1 = cur2;
		cur2 = next;
	}
}