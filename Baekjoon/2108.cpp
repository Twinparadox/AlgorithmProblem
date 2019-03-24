#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, min = 4001, max = -4001, sum = 0, aver;

	cin >> N;
	vector<int> arr(N);
	vector<int> posi(4001, 0);
	vector<int> neg(4001, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
		sum += arr[i];

		if (arr[i] >= 0)
			posi[arr[i]]++;
		else
			neg[-arr[i]]++;
	}

	double a = (double)sum / N;
	if (a < 0)
		aver = a - 0.5;
	else
		aver = a + 0.5;

	int freq = 0, f = posi[0];
	for (int i = 1; i <= 4000; i++)
	{
		if (f < posi[i])
			freq = i, f = posi[i];
		if (f < neg[i])
			freq = -i, f = neg[i];
	}
	vector<int> freqList;
	if (posi[0] == f)
		freqList.push_back(0);
	for (int i = 1; i <= 4000; i++)
	{
		if (posi[i] == f)
			freqList.push_back(i);
		if (neg[i] == f)
			freqList.push_back(-i);
	}

	if (freqList.size() >= 2)
	{
		sort(freqList.begin(), freqList.end());
		freq = freqList[1];
	}
	else
	{
		freq = freqList[0];
	}

	sort(arr.begin(), arr.end());
	int mid = arr[N / 2];

	cout << aver << '\n';
	cout << mid << '\n';
	cout << freq << '\n';
	cout << max - min << '\n';
}