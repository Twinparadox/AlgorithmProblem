#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int arr[5] = { 0, }, tmp, max = 0, maxidx;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> tmp;
			arr[i] += tmp;
		}
	}
	for (int i = 0; i < 5; i++)
		if (max < arr[i])
			max = arr[i], maxidx = i + 1;
	cout << maxidx << " " << max;
}
