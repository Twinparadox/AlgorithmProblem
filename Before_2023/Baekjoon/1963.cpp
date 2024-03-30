#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> sosu(10000);
int getNum(int arr[])
{
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}
void BFS(int start, int end)
{
	vector<int> check(10000, -1);
	int ans = -1;
	queue<pair<int, int> > q;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int cur = q.front().first, cnt = q.front().second;
		q.pop();
		if (cur == end)
		{
			ans = cnt;
			break;
		}
		int b[4] = { 0, }, arr[4] = { 0, }, tmp = cur;
		for (int i = 3; i >= 0; i--)
		{
			arr[i] = tmp % 10;
			tmp /= 10;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
				b[k] = arr[k];
			for (int j = 0; j <= 9; j++)
			{
				if (i == 0 && j == 0 || arr[i] == j)
					continue;
 				b[i] = j;

				int num = getNum(b);
				if (sosu[num] != 0 && check[num] == -1)
				{
					check[num] = cnt + 1;
					q.push(make_pair(num, cnt + 1));
				}
			}
		}
	}

	if (ans == -1)
		cout << "Impossible\n";
	else
		cout << ans << '\n';
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T, maxNum = 9999;
	cin >> T;

	for (int i = 2; i <= maxNum; i++)
		sosu[i] = i;
	for (int i = 2; i <= sqrt(maxNum); i++)
	{
		if (sosu[i] == 0)
			continue;
		for (int j = i + i; j <= maxNum; j += i)
			sosu[j] = 0;
	}

	while (T--)
	{
		int s, e;
		cin >> s >> e;
		BFS(s, e);
	}
}