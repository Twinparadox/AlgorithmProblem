#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<int> > link(N + 1, vector<int>());
	vector<int> arr(N + 1, 0);
	queue<int> q;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		link[A].push_back(B);
		arr[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0)
			q.push(i);
	}

	vector<int> result(N + 1);
	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
			break;

		int x = q.front();
		q.pop();
		result[i] = x;

		int size = link[x].size();
		for (int j = 0; j < size; j++)
		{
			int y = link[x][j];
			arr[y]--;
			if (arr[y] == 0)
			{
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << ' ';
}