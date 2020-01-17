#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, x;
	priority_queue<int, vector<int>, less<int> > pq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x)
			pq.push(x);
		else
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}