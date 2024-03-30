/*
이것이 코테다
그리디 - 숫자카드게임
그냥 보드 판 입력 받고, 매 줄마다 최솟값 계산한 후,
최종 해에서는 모든 줄의 최솟값 중 최댓값 선정하면 되는 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, M, ans = 0, su;
	vector<int> arr;
	cin >> N >> M;

	arr.resize(N, 1e5);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> su;
			arr[i] = arr[i] < su ? arr[i] : su;
		}
		ans = ans < arr[i] ? arr[i] : ans;
	}

	cout << ans;
}