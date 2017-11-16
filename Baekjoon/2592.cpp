#include <iostream>
using namespace std;
int main(void)
{
	int temp, arr[101] = { 0, }, sum = 0, maxidx = -1, max = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		sum += temp;
		arr[temp / 10]++;
	}
	for (int i = 1; i <= 100; i++)
		if (max < arr[i])
			max = arr[i], maxidx = i;
	cout << sum / 10 << "\n" << maxidx * 10;
}
