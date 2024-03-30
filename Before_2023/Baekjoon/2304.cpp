/*
[S2] 창고 다각형
최대 지점 기준으로 왼쪽 오른쪽에서 area 누적하면 풀 수 있음
단, 예외 케이스에 대한 처리가 필요하며,
시작과 끝이 동일하거나, 최대지점이 시작이거나 마지막일 때를 유의해야 함
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int start = 1001, end = 0, N, area = 0, height = 0, maxH = 0, maxCur = 0;
	vector<int> arr(1001, 0);
	cin >> N;

	int L, H;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		arr[L] = H;
		if (start > L)
			start = L;
		if (end < L)
			end = L;
		if (maxH < H)
			maxH = H, maxCur = L;
	}

	area = height = arr[start];
	for (int i = start + 1; i <= maxCur; i++)
	{
		if (height < arr[i])
			height = arr[i];
		area += height;
	}
	if (start != end && maxCur != end)
	{
		height = arr[end];
		area += height;
		for (int i = end - 1; i > maxCur; i--)
		{
			if (height < arr[i])
				height = arr[i];
			area += height;
		}
	}

	cout << area;
}