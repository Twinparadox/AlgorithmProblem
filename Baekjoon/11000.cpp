#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<pair<int, int > > arr;
	priority_queue<int, vector<int>, greater<int> > pq;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());

	pq.push(arr[0].second);
	for (int i = 1; i < N; i++)
	{
		if (pq.top() > arr[i].first)
			pq.push(arr[i].second);
		else
		{
			pq.pop();
			pq.push(arr[i].second);
		}
	}
	cout << pq.size();
}