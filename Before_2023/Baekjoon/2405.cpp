/* [G3] 2405 - 세 수, 두 M */
/*
수학 문제이긴 하나, 난이도가 높지 않음
부동소수점 오차를 고려해서 실수 연산을 사용하지 않아야 함
결과는 평균 * 3이기 때문에, 결과적으로 |2b - (a+c)|를 최대화하는 것이 목표
해당 값을 최대화하는 조건은, 최솟값이나 최댓값을 고정해두고
각각 (b,c)와 (a,b)를 정해가면서 정답을 찾으면 되는 문제
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	int N, ans = 0, tmp;
	vector<int> arr;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = 1; i < N - 1; i++)
	{
		tmp = 2 * arr[i] - arr[0] - arr[i + 1];
		tmp = abs(tmp);
		ans = max(tmp, ans);

		tmp = 2 * arr[i] - arr[i - 1] - arr[N - 1];
		tmp = abs(tmp);
		ans = max(tmp, ans);
	}
	cout << ans;
}