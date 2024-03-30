/*
[G5] 색종이
수학 및 구현이라고 되어있음
수학으로 접근했다가, 몇 줄 안 되는 코드로 시도했으나, 실패
완전 구현으로 넘어가서 풀었음
*/
#include <iostream>
using namespace std;
int main(void)
{
	const int SIZE = 7;
	int ans = 0, tmp;
	int arr[SIZE];
	for (int i = 1; i < SIZE; i++)
		cin >> arr[i];

	ans += arr[6] + arr[5] + arr[4];
	for (int i = 0; i < arr[5]; i++)
	{
		arr[1] -= 11;
		if (arr[1] <= 0)
			arr[1] = 0;
	}
	for (int i = 0; i < arr[4]; i++)
	{
		if (arr[2] >= 5)
			arr[2] -= 5;
		else
		{
			arr[1] -= (5 - arr[2]) * 4;
			if (arr[1] < 0)
				arr[1] = 0;
			arr[2] = 0;
		}
	}

	ans += arr[3] / 4;
	arr[3] %= 4;
	if (arr[3])
	{
		if (arr[3] == 3)
		{
			if (arr[2] >= 1)
				arr[2]--, arr[1] -= 5;
			else
				arr[1] -= 9;
			if (arr[1] < 0)
				arr[1] = 0;
		}
		else if (arr[3] == 2)
		{
			if (arr[2] >= 3)
				arr[2] -= 3, arr[1] -= 6;
			else if (arr[2] == 2)
				arr[2] = 0, arr[1] -= 10;
			else if (arr[2] == 1)
				arr[2] = 0, arr[1] -= 14;
			else
				arr[1] -= 18;
			if (arr[1] < 0)
				arr[1] = 0;
		}
		else
		{
			if (arr[2] >= 5)
				arr[2] -= 5, arr[1] -= 7;
			else
				arr[1] -= 7 + (5 - arr[2]) * 4, arr[2] = 0;
			if (arr[1] < 0) arr[1] = 0;
		}
		ans++;
	}

	tmp = arr[2] * 4 + arr[1];
	ans += (tmp + 35) / 36;

	cout << ans << endl;
	return 0;
}