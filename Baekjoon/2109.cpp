/* [G4] 2109 - 순회강연 */
/*
Greedy Algorithm
문제의 핵심은, '기한 내 어떤 날짜라도' 강연할 수 있단 의미
따라서, 3일 이내라고 하는 것은 1일차에 강연해도 상관 없다는 의미
날짜를 거꾸로 생각해서, 가장 기한이 긴 시점부터 탐색해가며 최대한 많은 돈을 버는 것이 핵심

예제를 기준으로 할 때, 20일차부터 1일차까지 역순으로 탐색
이 과정에서 같은 기한을 가진 여러 강연이 있을 경우, 최대 힙에 넣어놓고 다음과 같이 활용
최대 힙에 들어 있는 강연들은 '모두 기한 내 강연'임

1. 어떤 날을 기한으로 잡는 강연이 없을 때, 최대 힙에서 하나 꺼내와서 강연 배치
2. 어떤 날을 기한으로 잡는 강연이 있는 경우, 최대 힙과 비교해서 둘 중 큰 것을 배치하고, 나머지는 최대 힙에 모두 추가
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int N, d, p, ans = 0, curIdx = 0, cur = 0, maxD = 0;
	vector<vector<int> > days;
	priority_queue<int, vector<int>, less<int> > pq;
	cin >> N;

	days.resize(1e4 + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		days[d].emplace_back(p);
		maxD = max(maxD, d);
	}
	for (int i = maxD; i >= 1; i--)
	{
		int size = days[i].size();
		if (size)
		{
			sort(days[i].begin(), days[i].end(), greater<int>());
			if (!pq.empty())
			{
				if (pq.top() > days[i][0])
				{
					ans += pq.top();
					pq.pop();
					for (int j = 0; j < size; j++)
						pq.push(days[i][j]);
				}
				else
				{
					ans += days[i][0];
					for (int j = 1; j < size; j++)
						pq.push(days[i][j]);
				}
			}
			else
			{
				ans += days[i][0];
				for (int j = 1; j < size; j++)
					pq.push(days[i][j]);
			}
		}
		else if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}