#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, cnt = 0, tmp;
	priority_queue<int> pq;
	cin >> N;

	for (int i = 0; i < N*N; i++)
	{
		cin >> tmp;

		pq.push(-tmp);
		if (pq.size() > N)
			pq.pop();
	}
	cout << -pq.top();
}