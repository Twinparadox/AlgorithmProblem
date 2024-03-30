#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	int n, k, ans;
	bool visit[100001] = { false, };
	queue<pair<int, int> > q;
	cin >> n >> k;
	
	q.push({ n, 0 });
	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur < 0 || cur > 100000 || visit[cur])
			continue;

		visit[cur] = true;

		if (cur == k)
		{
			ans = cnt;
			break;
		}

		q.push(make_pair(cur - 1, cnt + 1));
		q.push(make_pair(cur + 1, cnt + 1));
		q.push(make_pair(cur * 2, cnt + 1));
	}
	cout << ans;
}
