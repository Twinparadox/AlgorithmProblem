/*
[G5] 피자 굽기
오븐의 깊숙한 곳의 반지름이 무엇이든, 그곳에 도달할 때까지 입구에 걸리는 것이 없어야 함
따라서, 5 6 4 3 6 2 3 => 5 5 4 3 3 2 2 로 볼 수 있음
맨 처음 피자가 오븐의 가장 깊은 곳에 위치해야 하므로,
피자는 순차적으로, 오븐은 역행하며 탐색하면 됨
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int D, N, ans;
	vector<int> oven, pizza;
	cin >> D >> N;

	oven.resize(D + 1);
	pizza.resize(N + 1);

	for (int i = 1; i <= D; i++)
		cin >> oven[i];
	for (int i = 1; i <= N; i++)
		cin >> pizza[i];

	int prev = oven[1];
	for (int i = 2; i <= D; i++)
	{
		if (prev < oven[i])
			oven[i] = prev;
		else
			prev = oven[i];
	}

	int pIdx = 1;
	for (ans = D; ans > 0 && pIdx <= N; ans--)
		if (pizza[pIdx] <= oven[ans])
			pIdx++;

	if (ans < 0 || pIdx <= N)
		cout << 0;
	else
		cout << ans + 1;
}