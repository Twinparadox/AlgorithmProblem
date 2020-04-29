#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<bool> > adj;
vector<bool> visit;
vector<int> cow, house;
bool dfs(int idx)
{
	if (visit[idx])
		return false;

	visit[idx] = true;

	for (int i = 1; i <= M; i++)
	{
		if (adj[idx][i])
		{
			if (!house[i] || dfs(house[i]))
			{
				cow[idx] = i;
				house[i] = idx;

				return true;
			}
		}
	}

	return false;
}
int match()
{
	int size = 0;
	for (int i = 1; i <= N; i++)
	{
		visit = vector<bool>(N + 1, false);

		if (dfs(i))
			size++;
	}
	return size;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	adj.resize(N + 1, vector<bool>(M + 1, false));
	cow.resize(N + 1, 0);
	house.resize(M + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int num = 0, no;

		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> no;
			adj[i][no] = true;
		}
	}

	cout << match();
}