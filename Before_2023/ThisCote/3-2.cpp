/*
이것이 코테다
그리디 - 큰 수의 법칙
오름차순 정렬하고 arr[N-1]을 K번 더하고 arr[N-2]를 한 번 더하고,
다시 arr[N-1]을 K번 더하는 식으로 풀이
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, M, K;
	long long ans = 0;
	vector<int> arr;

	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	for (int i = 0, cnt = 1; i < M; i++)
	{
		if (cnt % K == 0)
			cnt = 1, ans += arr[N - 2];
		else
			ans += arr[N - 1], cnt++;
	}

	cout << ans;
}