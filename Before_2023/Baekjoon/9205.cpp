#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int> > store;
bool bfs(pair<int, int> start, pair<int, int> end)
{
	int size = store.size(), cx, cy;
	vector<bool> check(size, false);
	queue<pair<int, int > > q;

	cx = start.first, cy = start.second;
	q.push(start);
	while (!q.empty())
	{
		cx = q.front().first, cy = q.front().second;
		q.pop();

		if (cx == end.first && cy == end.second)
		{
			return true;
			break;
		}
		for (int i = 0; i < size; i++)
		{
			if (!check[i])
			{
				int dist = abs(cx - store[i].first) + abs(cy - store[i].second);
				if (dist <= 1000)
				{
					q.push(store[i]);
					check[i] = true;
				}
			}
		}
	}	
	return false;
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	bool flag;
	int T, N;
	pair<int, int> start, end;
	
	cin >> T;
	while (T--)
	{
		cin >> N;
		cin >> start.first >> start.second;

		store = vector<pair<int, int> >(N);
		for (int i = 0; i < N; i++)
			cin >> store[i].first >> store[i].second;
		cin >> end.first >> end.second;

		store.push_back(end);
		sort(store.begin(), store.end());

		flag = bfs(start, end);
		if (flag)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}
