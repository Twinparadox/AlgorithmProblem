// 모든 기간의 가격을 알고 있음
// 특정 구간에서의 등락에 대해서도 사고 파는 작업을 진행해야 함
// 뒤에서부터 지역의 최댓값을 갱신해나가면서 진행하면 됨
// 최대치에서 감소하는 구간이 나타날 떄마다, 이익에 (최대주가 - 해당 시점 주가)를 더해주면 최적의 답
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, T;
	cin >> T;
	while (T--)
	{
		long long ans = 0;
		cin >> N;
		vector<long long> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		long long localMax = arr[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (arr[i] > localMax)
				localMax = arr[i];

			else if (arr[i] < localMax)
				ans += localMax - arr[i];
		}
		cout << ans << '\n';
	}
}