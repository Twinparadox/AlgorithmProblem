#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> su;
vector<bool> visit;
vector<int> arr;
void dfs()
{
	if (arr.size() == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (arr.empty() || arr.back() <= su[i])
			{
				visit[i] = true;
				arr.push_back(su[i]);
				dfs();
				visit[i] = false;
				arr.pop_back();
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	su = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> su[i];

	sort(su.begin(), su.end());
	visit = vector<bool>(n, false);
	dfs();
}