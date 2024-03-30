#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;
vector<bool> check;
vector<bool> subCheck;
vector<int> ans;
void dfs(int start, int next)
{
	if (start == next)
	{
		subCheck[next] = true;
		for (int i = 1; i <= N; i++)
			if (subCheck[i])
				check[i] = true;

		return;
	}

	if (!check[next] && !subCheck[next])
	{
		subCheck[next] = true;
		dfs(start, arr[next]);
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	arr.resize(N + 1);
	check.resize(N + 1, false);
	subCheck.resize(N + 1, false);

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
			dfs(i, arr[i]);

		subCheck = vector<bool>(N + 1, false);
	}

	for (int i = 1; i <= N; i++)
		if (check[i])
			ans.push_back(i);

	int size = ans.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << ans[i] << '\n';
}