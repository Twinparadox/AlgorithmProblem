/* 14888 ������ �����ֱ� */
/*
Solved S1

Brute-Force�� Ǯ� �� ����
����� �� �ִ� �����ڸ� ��� �迭�� ����ְ�
C++ STL�� next_permutation�� Ȱ���Ͽ� ������ ��ġ ���� ��� ����Ͽ� ���� ã���� ��
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, ansMax = -2e9, ansMin = 2e9;
	vector<int> arr;
	vector<int> ops(4, 0);
	vector<int> opArr;

	cin >> N;
	arr.resize(N);
	opArr.resize(N - 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> ops[i];

	int idx = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < ops[i]; j++)
			opArr[idx++] = i;

	do
	{
		int cur = arr[0];
		for (int i = 0; i < N - 1; i++)
		{
			switch (opArr[i])
			{
			case 0:
				cur += arr[i + 1];
				break;
			case 1:
				cur -= arr[i + 1];
				break;
			case 2:
				cur *= arr[i + 1];
				break;
			case 3:
				if (cur < 0 && arr[i + 1] > 0)
				{
					cur *= -1;
					cur /= arr[i + 1];
					cur *= -1;
				}
				else if (arr[i + 1] < 0 && cur > 0)
				{
					cur /= -arr[i + 1];
					cur *= -1;
				}
				else
				{
					cur /= arr[i + 1];
				}
				break;
			default:
				break;
			}
		}
		ansMax = ansMax < cur ? cur : ansMax;
		ansMin = ansMin < cur ? ansMin : cur;
	} while (next_permutation(opArr.begin(), opArr.end()));
	cout << ansMax << '\n' << ansMin;
}