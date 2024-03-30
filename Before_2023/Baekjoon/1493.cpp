/*
[G5] 1493 - 박스 채우기
그리디 문제
집어 넣을 수 있는 최대 크기부터 먼저 밀어넣고,
작은 크기로 넘어갈 때 이미 채운 부피에서 채워야될 부피를 계산하며 답을 탐색
모든 경우에 대해서 최대 크기를 집어넣는 쪽으로 접근
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