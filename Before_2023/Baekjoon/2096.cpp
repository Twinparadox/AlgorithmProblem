/*
[G4] 2096 - 내려가기
2차원 DP 문제
dp[i][j] = i번째까지의 줄에서 j칸에서의 최대 점수, 최소 점수
다만, 이 코드에서는 dp 테이블을 2차원으로 만들지 않고,
1차원으로 두고 단계마다 갱신하도록 함
min, max 2개의 테이블 생성
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	vector<int> dp1(3, 0), dp2(3, 0), tmp(3);
	int N, first, second, third;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second >> third;

		tmp[0] = max(dp1[0] + first, dp1[1] + first);
		tmp[1] = max(dp1[0] + second, max(dp1[1] + second, dp1[2] + second));
		tmp[2] = max(dp1[1] + third, dp1[2] + third);
		dp1.assign(tmp.begin(), tmp.end());

		tmp[0] = min(dp2[0] + first, dp2[1] + first);
		tmp[1] = min(dp2[0] + second, min(dp2[1] + second, dp2[2] + second));
		tmp[2] = min(dp2[1] + third, dp2[2] + third);
		dp2.assign(tmp.begin(), tmp.end());
	}

	int ans1 = -1, ans2 = 1e7;
	for (int i = 0; i < 3; i++)
	{
		ans1 = max(ans1, dp1[i]);
		ans2 = min(ans2, dp2[i]);
	}
	cout << ans1 << ' ' << ans2;
}