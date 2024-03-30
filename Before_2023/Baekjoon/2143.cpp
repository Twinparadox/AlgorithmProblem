/*
[G3] 두 배열의 합
입력 받은 배열 두 개를 각각의 부분합을 구해 새로운 배열 형성
생성된 배열을 바탕으로 투포인터 실시
배열의 합이 동일한 경우, 개수를 카운트해서 중복된 값들에 대해 불필요한 포인터 이동 과정이 없도록 함
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
	int T, n, m;
	vector<int> a, b;
	vector<int> aSub, bSub;

	cin >> T;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		aSub.push_back(tmp);
		for (int j = i + 1; j < n; j++)
		{
			tmp += a[j];
			aSub.push_back(tmp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int tmp = b[i];
		bSub.push_back(tmp);
		for (int j = i + 1; j < m; j++)
		{
			tmp += b[j];
			bSub.push_back(tmp);
		}
	}

	sort(aSub.begin(), aSub.end());
	sort(bSub.begin(), bSub.end());

	int aSize = aSub.size(), bSize = bSub.size();
	int aIdx = 0, bIdx = bSize - 1;
	long long ans = 0;
	while (aIdx < aSize && bIdx >= 0)
	{
		if (aSub[aIdx] + bSub[bIdx] == T)
		{
			long long subA = 1, subB = 1;

			while (aIdx < aSize - 1 && aSub[aIdx] == aSub[aIdx + 1])
			{
				aIdx++;
				subA++;
			}
			while (bIdx >= 1 && bSub[bIdx] == bSub[bIdx - 1])
			{
				bIdx--;
				subB++;
			}

			ans += subA * subB;
			aIdx++;
		}

		else if (aIdx < aSize && bIdx >= 0 && aSub[aIdx] + bSub[bIdx] < T)
			aIdx++;
		else if (aIdx<aSize && bIdx >= 0 && aSub[aIdx] + bSub[bIdx]>T)
			bIdx--;
	}
	cout << ans;
}