#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, A, B;
vector<int> indegree;
vector<vector<int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	indegree = vector<int>(N + 1, 0);
	arr = vector<vector<int> >(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		arr[A].push_back(B);
		indegree[B]++;
	}
	for (int i = 1; i <= N; i++)
		if (!indegree[i])
			pq.push(i);

	while (pq.size())
	{
		int cur = pq.top();
		pq.pop();
		cout << cur << ' ';

		int size = arr[cur].size();
		for (int i = 0; i < size; i++)
		{
			indegree[arr[cur][i]]--;
			if (!indegree[arr[cur][i]])
				pq.push(arr[cur][i]);
		}
	}
}