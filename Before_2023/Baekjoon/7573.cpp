/* [G4] 7573 - 고기잡기 */
/*
물고기를 모서리에 걸치게 해서 그물에 잡히는 물고기를 찾는 방식
MxM번의 물고기 선정과정과, 그물 내 물고기 포함 여부 탐색과정에서의 M만큼 탐색
물고기가 하나더라도, 하나를 두 마리처럼 인식하고 선택하게 됨
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, L, M, ans = 0;
vector<pair<int, int> > arr;
void countingFish(int x, int y, int len)
{
	int cnt = 0;
	int xEnd = x + len, yEnd = y + (L / 2) - len;
	for (int i = 0; i < M; i++)
	{
		if (arr[i].first >= x && arr[i].first <= xEnd && arr[i].second >= y && arr[i].second <= yEnd)
			cnt++;
	}

	ans = max(ans, cnt);
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> N >> L >> M;
	arr.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		arr[i] = make_pair(x, y);
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			for (int len = 1; len < L / 2; len++)
				countingFish(arr[i].first, arr[j].second, len);

	cout << ans;
}