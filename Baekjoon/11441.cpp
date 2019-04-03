#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N;
	vector<int> arr(N + 1), sum(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> M;
	while (M--)
	{
		int start, end;
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << '\n';
	}
}