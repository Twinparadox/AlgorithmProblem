#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1);
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << sum[e] - sum[s] + arr[s] << '\n';
	}
}