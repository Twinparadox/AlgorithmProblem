/*
[G5] 1493 - �ڽ� ä���
�׸��� ����
���� ���� �� �ִ� �ִ� ũ����� ���� �о�ְ�,
���� ũ��� �Ѿ �� �̹� ä�� ���ǿ��� ä���ߵ� ���Ǹ� ����ϸ� ���� Ž��
��� ��쿡 ���ؼ� �ִ� ũ�⸦ ����ִ� ������ ����
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	const int SIZE = 20;
	int N;
	long long L, W, H;
	long long volume = 0, ans = 0, subV;
	vector<long long> arr;

	cin >> L >> W >> H >> N;
	arr.resize(SIZE);

	int bin, su;
	for (int i = 0; i < N; i++)
	{
		cin >> bin >> su;
		arr[bin] = su;
	}

	for (int i = SIZE - 1; i >= 0; i--)
	{
		volume *= 8;
		subV = (L / (long long)pow(2, i)) * (W / (long long)pow(2, i)) * (H / (long long)pow(2, i));
		subV -= volume;

		long long cnt = min(arr[i], subV);
		volume += cnt;
		ans += cnt;
	}

	if (volume == L * W * H)
		cout << ans;
	else
		cout << -1;
}