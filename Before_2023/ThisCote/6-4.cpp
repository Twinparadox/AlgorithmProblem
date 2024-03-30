/*
이것이 코테다
정렬 - 기본문제
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int N, K;
	long long ans = 0;
	vector<int> a, b;

	cin >> N >> K;
	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < K; i++)
	{
		if (a[i] < b[N - 1 - i])
			a[i] = b[N - 1 - i];
		else
			break;
	}

	for (int i = 0; i < N; i++)
		ans += a[i];
	cout << ans;
}