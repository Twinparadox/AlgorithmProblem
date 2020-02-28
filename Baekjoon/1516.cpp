#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;

	vector<vector<int> > link(N + 1, vector<int>());
	vector<int> arr(N + 1, 0);
	vector<int> indeg(N + 1, 0);
	vector<int> ans(N + 1, 0);
	queue<int> q;

	int t;
	for (int i = 1; i <= N; i++)
	{
		cin >> t;

		arr[i] = t;

		int need;
		while (1)
		{
			cin >> need;
			if (need == -1)
				break;

			indeg[i]++;
			link[need].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int need = q.front();
		q.pop();

		int size = link[need].size();
		for (int i = 0; i < size; i++)
		{
			int nextNeed = link[need][i];
			int sum = ans[need] + arr[need];

			ans[nextNeed] = ans[nextNeed] < sum ? sum : ans[nextNeed];

			if (indeg[nextNeed] - 1 == 0)
				q.push(nextNeed);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << ans[i] + arr[i] << '\n';
}