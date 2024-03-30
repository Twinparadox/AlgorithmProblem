#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K, W;
		vector<int> arr, ans, indeg;
		vector<vector<int> > link;
		queue<int> q;

		cin >> N >> K;
		arr.resize(N + 1, 0);
		ans.resize(N + 1, 0);
		indeg.resize(N + 1, 0);
		link.resize(N + 1, vector<int>(N + 1, 0));

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		int X, Y;
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			indeg[Y]++;
			link[X].push_back(Y);
		}
		cin >> W;

		for (int i = 1; i <= N; i++)
		{
			if (indeg[i] == 0)
			{
				q.push(i);
				ans[i] += arr[i];
			}
		}

		while (!q.empty())
		{
			int need = q.front();
			q.pop();

			int size = link[need].size();
			for (int i = 0; i < size; i++)
			{
				int nextNeed = link[need][i];
				int sum = ans[need] + arr[nextNeed];

				ans[nextNeed] = ans[nextNeed] < sum ? sum : ans[nextNeed];

				if (--indeg[nextNeed] == 0)
					q.push(nextNeed);
			}
		}

		cout << ans[W] << '\n';
	}
}