#include <functional>
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	int N, ans = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<int> > pq;
	int A;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		pq.push(A);
	}

	ans = 0;
	while (pq.size() > 1)
	{
		int a1, a2;
		a1 = pq.top();
		pq.pop();
		a2 = pq.top();
		pq.pop();
		pq.push(a1 + a2);
		ans += (a1 + a2);
	}
	cout << ans;
}