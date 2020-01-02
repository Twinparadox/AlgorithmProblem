#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<vector<int > > graph(N, vector<int>());
	vector<int> indegree(N, 0);
	vector<int> result(N);
	queue<int> q;

	int K;
	for (int i = 0; i < M; i++)
	{
		cin >> K;

		vector<int> arr(K);
		for (int j = 0; j < K; j++)
			cin >> arr[j];

		for (int j = 1; j < K; j++)
		{
			graph[arr[j - 1] - 1].push_back(arr[j] - 1);
			indegree[arr[j] - 1]++;
		}
	}

	for (int i = 0; i < N; i++)
		if (indegree[i] == 0)
			q.push(i);

	for (int i = 0; i < N; i++)
	{
		if (q.empty())
			break;

		int cur = q.front();
		q.pop();
		result[i] = cur + 1;

		int size = graph[cur].size();
		for (int j = 0; j < size; j++)
			if (--indegree[graph[cur][j]] == 0)
				q.push(graph[cur][j]);
	}

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (result[i] == 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
		cout << 0;
	else
		for (int i = 0; i < N; i++)
			cout << result[i] << '\n';
}