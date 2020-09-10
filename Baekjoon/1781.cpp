/*
[G1] 1781 - 컵라면
그리디 알고리즘
Priority Queue를 이용해서 문제를 접근하는 게 좋음
데드라인 1순위, 보상 2순위로 결정해서 접근한다
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, dead, reward, idx;
	long long ans = 0;
	vector<pair<int, int> > arr;
	priority_queue<int> pq;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		arr[i].first--;
	}
	sort(arr.begin(), arr.end());

	idx = N - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		for (; idx >= 0 && arr[idx].first == i; idx--)
			pq.push(arr[idx].second);
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}