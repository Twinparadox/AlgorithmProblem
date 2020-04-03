#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int cnt = 0, bMax = -1, cMax = -1;
	int N, M;
	vector<int> crane, boxes;

	cin >> N;
	crane.resize(N);
	for (int i = 0; i < N; i++)
		cin >> crane[i];

	cin >> M;
	boxes.resize(M);
	for (int i = 0; i < M; i++)
		cin >> boxes[i];

	sort(crane.begin(), crane.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());
	if (boxes[0] > crane[0])
		cout << -1;
	else
	{
		while (boxes.size())
		{
			int idx = 0;
			for (int i = 0; i < boxes.size(); i++)
			{
				if (idx == N)
					break;
				if (crane[idx] >= boxes[i])
				{
					idx++;
					boxes.erase(boxes.begin() + i);
					i -= 1;
				}
			}
			cnt++;
		}
		cout << cnt;
	}
}