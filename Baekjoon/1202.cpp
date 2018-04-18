#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
	vector<pair<int, int> > jewels;
	vector<int> bags;
	priority_queue<int> pq;
	int n, k;
	long long sum = 0;
	cin >> n >> k;
	for (int i = 0, cost, weight; i < n; i++)
	{
		cin >> weight >> cost;
		jewels.push_back(make_pair(weight, cost));
	}
	for (int i = 0, weight; i < k; i++)
	{
		cin >> weight;
		bags.push_back(weight);
	}

	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());
	
	for (int i = 0, j = 0; i < k; i++)
	{
		while (j < n && jewels[j].first <= bags[i])
			pq.push(jewels[j++].second);

		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
