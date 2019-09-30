#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int windowSize;
	int min = 0;
	deque<pair<int, int> > dq;

	cin >> n;
	cin >> windowSize;
	for (int i = 0, tmp; i < n; i++)
	{
		cin >> tmp;
		while (!dq.empty() && dq.front().second <= i - windowSize)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > tmp)
			dq.pop_back();
		dq.push_back({ tmp,i });
		cout << dq.front().first << ' ';
	}
}