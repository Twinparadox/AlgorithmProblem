#include <iostream>
#include <vector>
using namespace std;
int n, m;
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
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && (arr.empty() || arr.back() < i))
			{
				visit[i] = true;
				arr.push_back(i);
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
	visit = vector<bool>(n + 1, false);
	dfs();
}