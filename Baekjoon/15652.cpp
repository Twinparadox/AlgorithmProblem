#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> arr;
void dfs(int cnt, int start)
{
	if (cnt == M)
	{
		for (int i = 1; i <= M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i <= N; i++)
	{
		arr.push_back(i);
		dfs(cnt + 1, i);
		arr.pop_back();
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	arr.push_back(0);
	dfs(0, 1);
}