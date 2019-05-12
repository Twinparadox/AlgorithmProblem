#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, cnt = 0;

	cin >> N >> M;
	vector<vector<int> > graph(N, vector<int>(N, 0));
	vector<bool> isCheck(N, false);
	vector<int> arrVertex(N, 0);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = 1;
		arrVertex[a - 1]++, arrVertex[b - 1]++;
	}

	for (int i = 0; i < N; i++)
		if (!arrVertex[i])
			cnt++;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N && !isCheck[i]; j++)
		{
			if (graph[i][j] && !isCheck[j])
			{
				cnt++;
				queue<int> q;
				q.push(j);
				isCheck[j] = true;
				while (!q.empty())
				{
					int vertex = q.front();
					q.pop();
					for (int idx = 0; idx < N; idx++)
					{
						if (graph[vertex][idx] && !isCheck[idx])
						{
							q.push(idx);
							isCheck[idx] = true;
						}
					}
				}
			}
		}
	}

	cout << cnt;
}