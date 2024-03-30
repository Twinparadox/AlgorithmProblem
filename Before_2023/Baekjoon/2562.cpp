#include <iostream>
using namespace std;
int main(void)
{
	const int SIZE = 9;
	int max = -1, maxIdx, arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i], maxIdx = i + 1;
	}
	cout << max << endl << maxIdx;
}
